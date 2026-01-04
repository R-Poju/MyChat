#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QList>
#include "statelabel.h"
#include "global.h"
#include "statewidget.h"

namespace Ui {
class ChatDialog;
}

class ChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChatDialog(QWidget *parent = nullptr);
    ~ChatDialog();

protected:
//    bool eventFilter(QObject* watched, QEvent* event) override;
//    void handleGlobalMousePress(QMouseEvent* event);
    void CloseFindDlg();
private:
    Ui::ChatDialog* ui;
//    void AddLBGroup(StateLabel* lb);
//    void addChatUserList();
    void ShowSearch(bool bsearch = false);
    void clearLabelState(StateLabel* lb);
    void AddLBGroup(StateWidget* lb);
    ChatUIMode _mode;
    QList<StateLabel*> _lb_list;
    bool _b_loading;
public slots:
    void slot_loading_chat_user();
    void slot_side_chat();
//    void slot_side_contact();
//    void slot_text_changed(const QString& str);
//    void slot_focus_out();
    void slot_loading_contact_user();
    void slot_switch_apply_friend_page();
    void slot_friend_info_page();
    void slot_show_search(bool show);
private slots:

};

#endif // CHATDIALOG_H


































