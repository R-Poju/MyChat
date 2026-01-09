#include "friendlabel.h"
#include "ui_friendlabel.h"

FriendLabel::FriendLabel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FriendLabel)
{
    ui->setupUi(this);
}

FriendLabel::~FriendLabel()
{
    delete ui;
}
