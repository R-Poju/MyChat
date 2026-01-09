#ifndef APPLYFRIENDITEM_H
#define APPLYFRIENDITEM_H

#include <QDialog>

namespace Ui {
class ApplyFriendItem;
}

class ApplyFriendItem : public QDialog
{
    Q_OBJECT

public:
    explicit ApplyFriendItem(QWidget *parent = nullptr);
    ~ApplyFriendItem();

private:
    Ui::ApplyFriendItem *ui;
};

#endif // APPLYFRIENDITEM_H
