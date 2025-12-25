#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QList>
//#include "statelabel.h"
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

//protected:
//    bool eventFilter(QObject* watched, QEvent* event) override;
//    void handleGlobalMousePress(QMouseEvent* event);

private:
    Ui::ChatDialog *ui;
    //void AddLBGroup(StateLabel* lb);
};

#endif // CHATDIALOG_H


































