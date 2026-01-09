#include "contactuserlist.h"
#include "global.h"
#include "listitembase.h"
#include "grouptipitem.h"
#include "conuseritem.h"
#include <QRandomGenerator>

ContactUserList::ContactUserList(QWidget* parent) :_add_friend_item(nullptr)
{
    Q_UNUSED(parent);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->viewport()->installEventFilter(this);

    addContactUserList();

    connect(this, &QListWidget::itemClicked, this, &ContactUserList::slot_item_clicked);
}

void ContactUserList::ShowRedPoint(bool bshow)
{
    _add_friend_item->ShowRedPoint(bshow);
}

void ContactUserList::addContactUserList()
{
    auto* groupTip = new GroupTipItem();
    QListWidgetItem* item = new QListWidgetItem;
    item->setSizeHint(groupTip->sizeHint());
    this->addItem(item);
    this->setItemWidget(item, groupTip);
    item->setFlags(item->flags() & ~Qt::ItemIsSelectable);

    _add_friend_item = new ConUserItem();
    _add_friend_item->setObjectName("new_friend_item");
    _add_friend_item->SetInfo(tr("新的朋友"), ":/res/add_friend.png");
    _add_friend_item->SetItemType(ListItemType::APPLY_FRIEND_ITEM);

    QListWidgetItem* add_item = new QListWidgetItem;
    add_item->setSizeHint(_add_friend_item->sizeHint());
    this->addItem(add_item);
    this->setItemWidget(add_item, _add_friend_item);
    //默认设置新的朋友申请条目被选中
    this->setCurrentItem(add_item);

    auto* groupCon = new GroupTipItem();
    groupCon->SetGroupTip(tr("联系人"));
    QListWidgetItem* groupitem = new QListWidgetItem;
    groupitem->setSizeHint(groupCon->sizeHint());
    this->addItem(groupitem);
    this->setItemWidget(groupitem, groupCon);
    groupitem->setFlags(groupitem->flags() & ~Qt::ItemIsSelectable);

    //创建QListWidgetItem, 并设置自定义的widget
    for(int i = 0; i < 13; i++){
        int randowValue = QRandomGenerator::global()->bounded(100);
        int str_i = randomValue%strs.size();
        int head_i = randomValue%heads.size();
        int name_i = randomValue%names.size();

        auto* con_user_wid = new ConUserItem();
        con_user_wid->SetInfo(names[name_i], heads[head_i]);
        QListWidgetItem* item = new QListWidgetItem;

        item->setSizeHint(con_user_wid->sizeHint());
        this->addItem(item);
        this->setItemWidget(item, con_user_wid);
    }
}

bool ContactUserList::eventFilter(QObject* object, QEvent* event)
{
    //检查事件是否是鼠标悬浮进入或离开
    if(watched == this->viewport()){
        if(event->type() == QEvent::Enter){
            this->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        }
        else if(event->type() == QEvent::Leave){
            this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        }
    }

    //检查事件是否是鼠标滚轮事件
    if(watched == this->viewport() && event->type() == QEvent::Wheel){
        QWheelEvent* wheelEvent = static_cast<QWheelEvent*>(event);
        int numDegrees = wheelEvent->angleDelta().y() / 8;
        int numSteps = numDegrees / 15;

        this->verticalScrollBar()->setValue(this->verticalScrollBar()->value() - numSteps);

        QScrollBar* scrollBar = this->verticalScrollBar();
        int maxScrollValue = scrollBar->maximum();
        int currentValue = scrollBar->value();

        if(maxScrollValue - currentValue <= 0){
            qDebug() << "load more contact user";
            emit sig_loading_contact_user();
        }

        return true;
    }

    return QListWidget::eventFilter(watched, event);
}

void ContactUserList::slot_item_clicked(QListWidgetItem* item)
{
    QWidget* widget = this->itemWidget(item);
    if(!widget){
        qDebug() << "slot item clicked widget is nullptr";
        return;
    }

    ListItemBase* customItem = qobject_cast<ListItemBase*>(widget);
    if(!customItem){
        qDebug() << "slot item clicked widget is nullptr";
        return;
    }

    auto itemType = customItem->GetItemType();
    if(itemType == ListItemType::INVALID_ITEM || itemType == ListItemType::GROUP_TIP_ITEM){
        qDebug() << "slot invalid item clicked";
        return;
    }

    if(itemType == ListItemType::APPLY_FRIEND_ITEM){
        qDebug() << "apply friend item clicked ";
        emit sig_switch_apply_friend_page();
        return;
    }
}


































