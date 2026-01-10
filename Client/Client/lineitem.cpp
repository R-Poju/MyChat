#include "lineitem.h"
#include "ui_lineitem.h"

LineItem::LineItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LineItem)
{
    ui->setupUi(this);
}

LineItem::~LineItem()
{
    delete ui;
}
