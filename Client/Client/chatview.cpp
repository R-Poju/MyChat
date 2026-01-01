#include "chatview.h"
#include <QScrollBar>
#include <QVBoxLayout>
#include <QEvent>
#include <QDebug>
#include <QTimer>
#include <QStyleOption>
#include <QPainter>

ChatView::ChatView(QWidget* parent)
    :QWidget(parent), isAppended(false)
{
    QVBoxLayout* pMainLayout = new QVBoxLayout();
    this->setLayout(pMainLayout);
    pMainLayout->setMargin(0);

    m_pScrollArea = new QScrollArea();
    m_pScrollArea->setObjectName("chat_area");
    pMainLayout->addWidget(m_pScrollArea);

    QWidget* W = new QWidget(this);
    w->setObjectName("chat_bg");
    w->setAutoFillBackground(true);
    QVBoxLayout* pHLayout_1 = new QVBoxLayout();
    pHLayout_1->addWidget(new QWidget(), 100000);
    w->setLayout(pHLayout_1);
    m_pScrollArea->setWidget(w);

    m_pScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QScrollBar* pVScrollBar = m_pScrollArea->verticalScrollBar();
    connect(pVScrollBar, &QScrollBar::rangeChanged, this, &ChatView::onVScrollBarMoved);
    //把垂直ScrollBar放到上边，而不是原来的并排
    QHBoxLayout* pHLayout_2 = new QHBoxLayout();
    pHLayout_2
}










































ChatView::ChatView(QWidget *parent)
{

}
