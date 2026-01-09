#ifndef APPLYFRIENDPAGE_H
#define APPLYFRIENDPAGE_H

#include <QDialog>
#include <memory.h>
#include <QJsonArray>
#include "userdata.h"

namespace Ui {
class ApplyFriendPage;
}

class ApplyFriendPage :public QWidget
{
    Q_OBJECT

public:
    explicit ApplyFriendPage(QWidget* parent = nullptr);
    ~ApplyFriendPage();
    void AddNewApply(std::shared_ptr<AddFriendApply> apply);

protected:
    void paintEvent(QPaintEvent* event);

private:
    Ui::ApplyFriendPage *ui;
    void loadApplyList();
public slots:
signals:
    void sig_show_search(bool);
};

#endif // APPLYFRIENDPAGE_H
































