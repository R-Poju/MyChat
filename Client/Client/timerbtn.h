#ifndef TIMERBTN_H
#define TIMERBTN_H
#include <qpushbutton.h>
#include <QTimer>

class TimerBtn : public QPushButton

{
public:

    TimerBtn(QWidget* parent = nullptr);
    ~TimerBtn();

    virtual void mouseReleaseEvent(QMouseEvent* e) override;

private:
    QTimer* _timer;
    int _counter;
};

#endif // TIMERBTN_H
