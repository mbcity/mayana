#include "sidebar.h"

#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
#include <QEvent>

#define action_height 90

SideBar::SideBar(QWidget *parent) :
    QWidget(parent),
    m_checkedAction(nullptr),
    m_overAction(nullptr)
{
    setMouseTracking(true);
}

void SideBar::addAction(QAction *action)
{
    m_actions.push_back(action);
    action->setCheckable(true);
    update();
}

QAction *SideBar::addAction(const QString &text, const QIcon &icon)
{
    QAction *action = new QAction(icon, text, this);
    action->setCheckable(true);
    m_actions.push_back(action);
    update();
    return action;
}

QSize SideBar::minimumSizeHint() const
{
    return action_height*QSize(1, m_actions.size());
}

void SideBar::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QFont fontText(painter.font());
    fontText.setFamily("Helvetica Neue");
    painter.setFont(fontText);

    int action_y = 0;
    painter.fillRect(rect(), QColor("#34495E"));
    for(auto action: m_actions)
    {

        QRect actionRect(0, action_y, event->rect().width(), action_height);

        if(action->isChecked())
        {
            painter.fillRect(actionRect, QColor(35, 35, 35));
        }

        if(action == m_overAction){
            painter.fillRect(actionRect, QColor(150, 150, 150));
        }

        painter.setPen(QColor(255, 255, 255));
        QSize size = painter.fontMetrics().size(Qt::TextSingleLine, action->text());
        QRect actionTextRect(QPoint(actionRect.width()/2 - size.width()/2, actionRect.bottom()-size.height()-5), size);
        painter.drawText(actionTextRect, Qt::AlignCenter, action->text());

        QRect actionIconRect(0, action_y + 10, actionRect.width(), actionRect.height()-2*actionTextRect.height()-10);
        QIcon  actionIcon(action->icon());
        actionIcon.paint(&painter, actionIconRect);

        action_y += actionRect.height();
    }
}

void SideBar::mousePressEvent(QMouseEvent *event)
{
    QAction* tempAction = actionAt(event->pos());
    if(tempAction == nullptr || tempAction->isChecked())
        return;
    qDebug()<<"clicked";
    if(m_checkedAction)
        m_checkedAction->setChecked(false);
    if(m_overAction == tempAction)
        m_overAction = nullptr;
    m_checkedAction = tempAction;
    tempAction->setChecked(true);
    update();
    QWidget::mousePressEvent(event);
}

void SideBar::mouseMoveEvent(QMouseEvent *event)
{
    QAction* tempAction = actionAt(event->pos());
    if(tempAction == nullptr){
        m_overAction = nullptr;
        update();
        return;
    }
    if(tempAction->isChecked() || m_overAction == tempAction)
        return;
    m_overAction = tempAction;
    update();
    QWidget::mouseMoveEvent(event);
}

void SideBar::leaveEvent(QEvent *event)
{
    m_overAction = nullptr;
    update();
    QWidget::leaveEvent(event);
}

QAction *SideBar::actionAt(const QPoint &at)
{
    int action_y = 0;
    for(auto action: m_actions)
    {
        QRect actionRect(0, action_y, rect().width(), action_height);
        if(actionRect.contains(at))
            return action;
        action_y += actionRect.height();
    }
    return nullptr;
}

#undef action_height
