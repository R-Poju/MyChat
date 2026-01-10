#ifndef LINEITEM_H
#define LINEITEM_H

#include <QDialog>

namespace Ui {
class LineItem;
}

class LineItem : public QDialog
{
    Q_OBJECT

public:
    explicit LineItem(QWidget *parent = nullptr);
    ~LineItem();

private:
    Ui::LineItem *ui;
};

#endif // LINEITEM_H
