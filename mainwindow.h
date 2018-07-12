#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QMouseEvent>

class SideBar;

QT_BEGIN_NAMESPACE
class QTabBar;
class QStackedWidget;
class QHBoxLayout;
class QVBoxLayout;
class QSplitter;
class QMenu;
class QMenuBar;
class QToolBar;
class QAction;
class QPushButton;
QT_END_NAMESPACE


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    /*Q_PROPERTY(QPoint previousPosition READ previousPosition WRITE setPreviousPosition NOTIFY previousPositionChanged)

    enum MouseType {
        None = 0,
        Top,
        Bottom,
        Left,
        Right,
        Move
    };*/

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //QPoint previousPosition() const;

public slots:
    //void setPreviousPosition(QPoint previousPosition);

signals:
    //void previousPositionChanged(QPoint previousPosition);

private slots:
    void onBtnFichierClicked();
    void populateSideBar();

protected:
    /*void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;*/
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::MainWindow *ui;
    QVBoxLayout *mainLayout;
    //QHBoxLayout *menuLayout;
    QMenuBar *menuBar;
    QToolBar *menuToolBar;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
    QToolBar *mainToolBar;
    QToolBar *sceneToolBar;
    QTabBar *tabBar;
    QStackedWidget *stackedWidget;
    QSplitter *mainSplitter;
    QAction *fileNew;
    QAction *open;
    QAction *save;
    QAction *copy;
    QAction *paste;
    QAction *cut;
    QPushButton *zoomPlusBtn;
    QPushButton *zoomMoinsBtn;
    QPushButton *zoomFullBtn;

    /*MouseType m_leftMouseButtonPressed;
    QPoint m_previousPosition;

    MouseType checkResizableField(QMouseEvent *event);*/
};

#endif // MAINWINDOW_H
