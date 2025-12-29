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
//#include "loadingdlg.h"


ChatDialog::ChatDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatDialog), _mode(ChatUIMode::ChatMode), _b_loading(false)
{
    ui->setupUi(this);

    ui->add_btn->SetState("normal","hover","press");
    ui->add_btn->setProperty("state","normal");

    QAction* searchAction = new QAction(ui->search_edit);

}

ChatDialog::~ChatDialog()
{
    delete ui;
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






































