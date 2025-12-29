#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QList>
#include "statelabel.h"
#include "global.h"

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

private:
    Ui::ChatDialog* ui;
//    void AddLBGroup(StateLabel* lb);
//    void addChatUserList();
    void ShowSearch(bool bsearch = false);
//    void clearLabelState(StateLabel* lb);
    ChatUIMode _mode;
    QList<StateLabel*> _lb_list;
    bool _b_loading;
public slots:
//    void slot_loading_chat_user();
//    void slot_side_chat();
//    void slot_side_contact();
//    void slot_text_changed(const QString& str);
//    void slot_focus_out();

private slots:
//    void on_send_btn_clicked();
};

#endif // CHATDIALOG_H


































