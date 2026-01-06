#include "findsuccessdialog.h"
#include "ui_findsuccessdialog.h"

FindSuccessDialog::FindSuccessDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindSuccessDialog)
{
    ui->setupUi(this);
}

FindSuccessDialog::~FindSuccessDialog()
{
    delete ui;
}
