#include "adduseritem.h"
#include "ui_adduseritem.h"

AddUserItem::AddUserItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddUserItem)
{
    ui->setupUi(this);
}

AddUserItem::~AddUserItem()
{
    delete ui;
}
