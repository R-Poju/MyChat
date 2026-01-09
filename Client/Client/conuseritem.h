#ifndef CONUSERITEM_H
#define CONUSERITEM_H

#include <QDialog>

namespace Ui {
class ConUserItem;
}

class ConUserItem : public QDialog
{
    Q_OBJECT

public:
    explicit ConUserItem(QWidget *parent = nullptr);
    ~ConUserItem();

private:
    Ui::ConUserItem *ui;
};

#endif // CONUSERITEM_H
