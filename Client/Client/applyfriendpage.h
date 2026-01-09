#ifndef APPLYFRIENDPAGE_H
#define APPLYFRIENDPAGE_H

#include <QDialog>

namespace Ui {
class ApplyFriendPage;
}

class ApplyFriendPage : public QDialog
{
    Q_OBJECT

public:
    explicit ApplyFriendPage(QWidget *parent = nullptr);
    ~ApplyFriendPage();

private:
    Ui::ApplyFriendPage *ui;
};

#endif // APPLYFRIENDPAGE_H
