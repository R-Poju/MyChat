#include "conuseritem.h"
#include "ui_conuseritem.h"

ConUserItem::ConUserItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConUserItem)
{
    ui->setupUi(this);
}

ConUserItem::~ConUserItem()
{
    delete ui;
}
