#include "authenfriend.h"
#include "ui_authenfriend.h"
#include <QScrollBar>
#include "clickedlabel.h"
#include "friendlabel.h"
#include "usermgr.h"
#include "tcpmgr.h"

AuthenFriend::AuthenFriend(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::AuthenFriend)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    this->setObjectName("AuthenFriend");
    this->setModal(true);
    ui->lb_ed->setPlaceholderText("搜索、添加标签");
    ui->back_ed->setPlaceholderText("六脉神剑");

    ui->lb_ed->SetMaxLength(21);
    ui->lb_ed->move(2, 2);
    ui->lb_ed->setFixedHeight(20);
    ui->lb_ed->setMaxLength(10);
    ui->input_tip_wid->hide();

    _tip_cur_point = QPoint(5, 5);

    _tip_data = { "同学","家人","菜鸟教程","C++ Primer","Rust 程序设计",
                  "父与子学Python","nodejs开发指南","go 语言开发指南",
                     "游戏伙伴","金融投资","微信读书","拼多多拼友" };

    connect(ui->more_lb, &ClickedOnceLabel::clicked, this, &AuthenFriend::ShowMoreLabel);
    InitTipLbs();

    //链接输入标签回车事件
    connect(ui->lb_ed, &CustomizeEdit::returnPressed, this, &AuthenFriend::SlotLabelEnter);
    connect(ui->lb_ed, &CustomizeEdit::textChanged, this, &AuthenFriend::SlotLabelTextChange);
    connect(ui->lb_ed, &CustomizeEdit::editingFinished, this, &AuthenFriend::SlotLabelEditFinished);
    connect(ui->tip_lb, &ClickedOnceLabel::clicked, this, &AuthenFriend::SlotAddFirendLabelByClickTip);

    ui->scrollArea->horizontalScrollBar()->setHidden(true);
    ui->scrollArea->verticalScrollBar()->setHidden(true);
    ui->scrollArea->installEventFilter(this);
    ui->sure_btn->SetState("normal", "hover", "press");
    ui->cancel_btn->SetState("normal", "hover", "press");

    connect(ui->sure_btn, &QPushButton::clicked, this, &AuthenFriend::SlotApplySure);
    connect(ui->cancel_btn, &QPushButton::clicked, this, &AuthenFriend::SlotApplyCancel);
}

AuthenFriend::~AuthenFriend()
{
    delete ui;
}

void AuthenFriend::InitTipLbs()
{
    int lines = 1;
    for(int i = 0; i < _tip_data.size(); i++){
        auto* lb = new ClickedLabel(ui->lb_list);
        lb->SetState("normal", "hover", "pressed", "selected_normal",
                     "selected_hover", "selected_pressed");
        lb->setObjectName("tipslb");
        lb->setText(_tip_data[i]);
        connect(lb, &ClickedLabel::clicked, this, &AuthenFriend::SlotChangeFriendLabelByTip);

        QFontMetrics fontMetrics(lb->font());
        int textWidth = fontMetrics.width(lb->text());
        int textHeight = fontMetrics.height();

        if(_tip_cur_point.x() + textWidth + tip_offset > ui->lb_list->width()){
            lines++;
            if(lines > 2){
                delete lb;
                return;
            }

            _tip_cur_point.setX(tip_offset);
            _tip_cur_point.setY(_tip_cur_point.y() + textHeight + 15);
        }

        auto next_point = _tip_cur_point;

        AddTipLbs(lb, _tip_cur_point, next_point, textWidth, textHeight);

        _tip_cur_point = next_point;
    }
}

void AuthenFriend::AddTipLbs(ClickedLabel* lb, QPoint cur_point, QPoint& next_point, int text_width, int text_height)
{
    lb->move(cur_point);
    lb->show();
    _add_labels.insert(lb->text(), lb);
    _add_label_keys.push_back(lb->text());
    next_point.setX(lb->pos().x() + text_width + 15);
    next_point.setY(lb->pos().y());
}

bool AuthenFriend::eventFilter(QObject* obj, QEvent* event)
{
    if(obj == ui->scrollArea && event->type() == QEvent::Enter){
        ui->scrollArea->verticalScrollBar()->setHidden(false);
    }
    else if(obj == ui->scrollArea && event->type() == QEvent::Leave){
        ui->scrollArea->verticalScrollBar()->setHidden(true);
    }
    return QObject::eventFilter(obj, event);
}

void AuthenFriend::SetApplyInfo(std::shared_ptr<ApplyInfo> apply_info)
{
    _apply_info = apply_info;
    ui->back_ed->setPlaceholderText(apply_info->_name);
}

void AuthenFriend::ShowMoreLabel()
{
    qDebug() << "receive more label clicked";
    ui->more_lb_wid->hide();

    ui->lb_list->setFixedWidth(325);
    _tip_cur_point = QPoint(5, 5);
    auto next_point = _tip_cur_point;
    int textWidth;
    int textHeight;
    //重拍现有的Label
    for(auto& added_key : _add_label_keys){
        auto added_lb = _add_labels[added_key];

        QFontMetrics fontMetrics(added_lb->font());
        textWidth = fontMetrics.width(added_lb->text());
        textHeight = fontMetrics.height();

        if(_tip_cur_point.x() + textWidth + tip_offset > ui->lb_list->width()){
            _tip_cur_point.setX(tip_offset);
            _tip_cur_point.setY(_tip_cur_point.y() + textHeight + 15);
        }
        added_lb->move(_tip_cur_point);

        next_point.setX(added_lb->pos().x() + textWidth + 15);
        next_point.setY(_tip_cur_point.y());

        _tip_cur_point = next_point;
    }

    //添加未添加的
    for(int i = 0; i < _tip_data.size(); i++){
        auto iter = _add_labels.find(_tip_data[i]);
        if(iter != _add_labels.end()){
            continue;
        }

        auto* lb = new ClickedLabel(ui->lb_list);
        lb->SetState("normal", "hover", "pressed", "selected_normal",
                     "selected_hover", "selected_pressed");
        lb->setObjectName("tipslb");
        lb->setText(_tip_data[i]);
        connect(lb, &ClickedLabel::clicked, this, &AuthenFriend::SlotChangeFriendLabelByTip);

        QFontMetrics fontMetrics(lb->font());
        int textWidth = fontMetrics.width(lb->text());
        int textHeight = fontMetrics.height();

        if(_tip_cur_point.x() + textWidth + tip_offset > ui->lb_list->width()){
            _tip_cur_point.setX(tip_offset);
            _tip_cur_point.setY(_tip_cur_point.y() + textHeight + 15);
        }

        next_point = _tip_cur_point;

        AddTipLbs(lb, _tip_cur_point, next_point, textWidth, textHeight);

        _tip_cur_point = next_point;
    }

    int diff_height = next_point.y() + textHeight + tip_offset - ui->lb_list->height();
    ui->lb_list->setFixedHeight(next_point.y() + textHeight + tip_offset);

    ui->scrollcontent->setFixedHeight(ui->scrollcontent->height() + diff_height);
}

void AuthenFriend::resetLabels()
{

}





































