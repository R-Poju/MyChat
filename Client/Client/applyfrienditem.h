#ifndef APPLYFRIENDITEM_H
#define APPLYFRIENDITEM_H

#include <QDialog>
#include <memory>
#include "listitembase.h"
#include "userdata.h"

namespace Ui {
class ApplyFriendItem;
}

class ApplyFriendItem : public ListItemBase
{
    Q_OBJECT

public:
    explicit ApplyFriendItem(QWidget* parent = nullptr);
    ~ApplyFriendItem();
    void SetInfo(std::shared_ptr<ApplyInfo> apply_info);
    void ShowAddBtn(bool bshow);
    QSize sizeHint() const override{
        return QSzie(250, 80);
    }

private:
    Ui::ApplyFriendItem *ui;
    std::shared_ptr<ApplyInfo> _apply_info;
signals:
    void sig_auth_friend(std::shared_ptr<ApplyInfo> apply_info);
};

#endif // APPLYFRIENDITEM_H































