#include "chatdialog.h"
#include "ui_chatdialog.h"
#include <QAction>
#include <QDebug>
#include <vector>
#include <QRandomGenerator>
#include "chatuserlist.h"
#include "chatuserwid.h"
#include "global.h"
//#include "ChatItemBase.h"
//#include "TextBubble.h"
//#include "PictureBubble.h"
//#include "MessageTextEdit.h"
#include "loadingdlg.h"


ChatDialog::ChatDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatDialog), _mode(ChatUIMode::ChatMode), _b_loading(false)
{
    ui->setupUi(this);

    ui->add_btn->SetState("normal","hover","press");
    ui->add_btn->setProperty("state","normal");

    QAction* searchAction = new QAction(ui->search_edit);
    searchAction->setIcon(QIcon(":/res/search.png"));

    ui->search_edit->addAction(searchAction, QLineEdit::LeadingPosition);
    ui->search_edit->setPlaceholderText(QStringLiteral("搜索"));


    //创建一个清除动作并设置图标
    QAction* clearAction = new QAction(ui->search_edit);
    clearAction->setIcon(QIcon(":/res/close_transparent.png"));

    //初始时不显示清除图标
    //将清除动作添加到LineEdit的末尾位置
    ui->search_edit->addAction(clearAction, QLineEdit::TrailingPosition);

    //当需要显示清除图标时，更改为实际的清除图标
    connect(ui->search_edit, &QLineEdit::textChanged, [clearAction](const QString& text){
       if(!text.isEmpty()){
           clearAction->setIcon(QIcon(":/res/close_search.png"));

       }else{
           clearAction->setIcon(QIcon(":/res/close_transparent.png"));
       }

    });

    //连接清除动作的触发信号到槽函数，用于清除文本
    connect(clearAction, &QAction::triggered, [this, clearAction](){
       ui->search_edit->clear();
       clearAction->setIcon(QIcon(":/res/close_transparent.png"));  //清除文本后，切换回透明图标
       ui->search_edit->clearFocus();

    });

    ui->search_edit->SetMaxLength(15);
}

ChatDialog::~ChatDialog()
{
    delete ui;
}

bool ChatDialog::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress){
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        handleGlobalMousePress(mouseEvent);
    }
    return QDialog::eventFilter(watched, event);
}

void ChatDialog::handleGlobalMousePress(QMouseEvent *event)
{
    //实现点击位置的判断和处理逻辑
    //先判断是否处搜索模式，如果不处于搜索模式则直接返回
    if(_mode != ChatUIMode::SearchMode){
        return;
    }

    //将鼠标点击位置转换为搜索列表坐标系中的位置
    QPoint posInSearchList = ui->search_list->mapFromGlobal(event->globalPos());
    //判断点击位置是否在聊天列表范围内
    if(!ui->search_list->rect().contains(posInSearchList)){
        //如果不在聊天列表内，则清空输入框
        ui->search_edit->clear();
        ShowSearch(false);
    }
}

void ChatDialog::ShowSearch(bool bsearch)
{
    if(bsearch){
        ui->chat_user_list->hide();
        ui->search_list->show();
        _mode = ChatUIMode::SearchMode;
    }else{
        ui->chat_user_list->show();
        ui->search_list->hide();
        _mode = ChatUIMode::ChatMode;
    }
}

void ChatDialog::slot_loading_chat_user()
{
    if(_b_loading){
        return;
    }

    _b_loading = true;
    LoadingDlg* loadingDialog = new LoadingDlg(this);
    loadingDialog->setModal(true);
    loadingDialog->show();
    qDebug() << "add new data to list......";
    addChatUserList();
    //加载完成后，关闭对话框
    loadingDialog->deleteLater();

    _b_loading = false;
}

void ChatDialog::slot_side_chat()
{
    qDebug() << "receive side chat clicked";
    clearLabelState(ui->side_chat_lb);
    ui->stackedWidget->setCurrentWidget(ui->chat_page);
    _state = ChatUIMode::ChatMode;
    ShowSearch(false);
}

void ChatDialog::clearLabelState(StateLabel *lb)
{
    for(auto& ele : _lb_list){
        if(ele == lb){
            continue;
        }

        ele->ClearState();
    }
}

void ChatDialog::AddLBGroup(StateWidget* lb)
{
     _lb_list.push_back(lb);
}



































