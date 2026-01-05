#ifndef ADDUSERITEM_H
#define ADDUSERITEM_H

#include <QDialog>

namespace Ui {
class AddUserItem;
}

class AddUserItem : public QDialog
{
    Q_OBJECT

public:
    explicit AddUserItem(QWidget *parent = nullptr);
    ~AddUserItem();

private:
    Ui::AddUserItem *ui;
};

#endif // ADDUSERITEM_H
