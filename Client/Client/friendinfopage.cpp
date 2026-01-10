#include "friendinfopage.h"
#include "ui_friendinfopage.h"

FriendInfoPage::FriendInfoPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FriendInfoPage)
{
    ui->setupUi(this);
}

FriendInfoPage::~FriendInfoPage()
{
    delete ui;
}
