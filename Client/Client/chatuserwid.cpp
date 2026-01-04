#include "chatuserwid.h"
#include "ui_chatuserwid.h"

ChatUserWid::ChatUserWid(QWidget *parent) :
    ListItemBase(parent),
    ui(new Ui::ChatUserWid)
{
    ui->setupUi(this);
    SetItemType(ListItemType::ChatUserItem);
}

ChatUserWid::~ChatUserWid()
{
    delete ui;
}

void ChatUserWid::SetInfo(QString name, QString head, QString msg)
{
    _name = name;
    _head = head;
    _msg = msg;
    // 加载图片
    QPixmap pixmap(_head);

    // 设置图片自动缩放
    ui->icon_lb->setPixmap(pixmap.scaled(ui->icon_lb->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->icon_lb->setScaledContents(true);

//    ui->user_name_lb->setText(_name);
//    ui->user_chat_lb->setText(_msg);

    QFontMetrics fontMetrics(ui->user_name_lb->font());
    QString nameText = fontMetrics.elidedText(_name, Qt::ElideRight, ui->user_name_lb->width());
    QFontMetrics fontMetrics(ui->user_chat_lb->font());
    QString msgText = fontMetrics.elidedText(_msg, Qt::ElideRight, ui->user_chat_lb->width());

    //手动截断文本，保留前面部分并添加省略号
    int numCharsToShow = ui->user_chat_lb->width() - 3;     //显示前127个字符
    if(ui->user_chat_lb->text().length() > numCharsToShow){
        ui->user_chat_lb->setText(QString(ui->user_chat_lb->text().left(numCharsToShow) + "..."));
    }
    if(ui->user_name_lb->text().length() > numCharsToShow){
        ui->user_name_lb->setText(QString(ui->user_name_lb->text().left(numCharsToShow) + "..."));
    }
    ui->user_chat_lb->setText(msgText);
    ui->user_name_lb->setText(nameText);
}


























