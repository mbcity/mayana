#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QWidget>
#include <QAction>


QT_BEGIN_NAMESPACE
class QAction;
QT_END_NAMESPACE

class SideBar : public QWidget
{
    Q_OBJECT
public:
    explicit SideBar(QWidget *parent = nullptr);
    void addAction(QAction *action);
    QAction *addAction(const QString &text, const QIcon &icon = QIcon());
    QSize minimumSizeHint() const;

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void leaveEvent(QEvent * event);

    QAction *actionAt(const QPoint &at);

private:
    QList<QAction *> m_actions;

    QAction *m_checkedAction;
    QAction *m_overAction;

signals:

public slots:
};

#endif // SIDEBAR_H
