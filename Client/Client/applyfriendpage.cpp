#include "applyfriendpage.h"
#include "ui_applyfriendpage.h"

ApplyFriendPage::ApplyFriendPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ApplyFriendPage)
{
    ui->setupUi(this);
}

ApplyFriendPage::~ApplyFriendPage()
{
    delete ui;
}
