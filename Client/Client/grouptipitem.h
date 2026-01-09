#ifndef GROUPTIPITEM_H
#define GROUPTIPITEM_H

#include <QDialog>

namespace Ui {
class GroupTipItem;
}

class GroupTipItem : public QDialog
{
    Q_OBJECT

public:
    explicit GroupTipItem(QWidget *parent = nullptr);
    ~GroupTipItem();

private:
    Ui::GroupTipItem *ui;
};

#endif // GROUPTIPITEM_H
