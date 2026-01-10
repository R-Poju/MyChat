#ifndef FRIENDINFOPAGE_H
#define FRIENDINFOPAGE_H

#include <QDialog>

namespace Ui {
class FriendInfoPage;
}

class FriendInfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit FriendInfoPage(QWidget *parent = nullptr);
    ~FriendInfoPage();

private:
    Ui::FriendInfoPage *ui;
};

#endif // FRIENDINFOPAGE_H
