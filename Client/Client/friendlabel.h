#ifndef FRIENDLABEL_H
#define FRIENDLABEL_H

#include <QDialog>

namespace Ui {
class FriendLabel;
}

class FriendLabel : public QDialog
{
    Q_OBJECT

public:
    explicit FriendLabel(QWidget *parent = nullptr);
    ~FriendLabel();

private:
    Ui::FriendLabel *ui;
};

#endif // FRIENDLABEL_H
