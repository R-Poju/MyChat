#include "applyfriendpage.h"
#include "ui_applyfriendpage.h"
#include <QPainter>
#include <QPaintEvent>
#include <QStyleOption>
#include <QRandomGenerator>
#include "applyfrienditem.h"
#include "authenfriend.h"
#include "applyfriend.h"
#include "tcpmgr.h"
#include "usermgr.h"

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

































