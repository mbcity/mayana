#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "doctype1.h"
#include "doctype2.h"
#include "stylehelper.h"
#include <QVBoxLayout>
#include <QTabBar>
#include <QToolBar>
#include <QLineEdit>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QStackedWidget>
#include <QTabWidget>
#include <QSplitter>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QGraphicsView>
#include <QGraphicsDropShadowEffect>
#include "sidebar.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    //m_leftMouseButtonPressed(None)
{
    ui->setupUi(this);

    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(9);
    shadowEffect->setOffset(0);
    ui->centralWidget->setGraphicsEffect(shadowEffect);
    ui->centralWidget->layout()->setMargin(0);
    ui->centralWidget->layout()->setSpacing(0);
    ui->label_message->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    /*connect(ui->toolButton_reduce, &QToolButton::clicked, this, &MainWindow::showMinimized);
    connect(ui->toolButton_maximize, &QToolButton::clicked, [this](){
        if (this->isMaximized()) {
            ui->toolButton_maximize->setStyleSheet(StyleHelper::getMaximizeStyleSheet());
            this->layout()->setMargin(9);
            this->showNormal();
        } else {
            ui->toolButton_maximize->setStyleSheet(StyleHelper::getRestoreStyleSheet());
            this->layout()->setMargin(0);
            this->showMaximized();
        }
    });
    connect(ui->toolButton_close, &QToolButton::clicked, this, &MainWindow::close);*/

    //connect(ui->toolButton_fichier, &QToolButton::clicked, this, &MainWindow::onBtnFichierClicked);

    DocType1 doc;
    qDebug("%s", doc.objectName().toStdString().c_str());

    DocType2 doc1;
    qDebug("%s", doc1.objectName().toStdString().c_str());

    /*this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setStyleSheet(StyleHelper::getWindowStyleSheet());
    this->setMouseTracking(true);*/


    /*! QMenu *menu = new QMenu("Fichier");
    menu->addAction("Nouveau");


    ui->pushButton_fichier->setMenu(menu);*/

    zoomPlusBtn = new QPushButton("+", this);
    zoomMoinsBtn = new QPushButton("-", this);
    zoomFullBtn = new QPushButton("100 %", this);


    /*! zoomPlusBtn->setMenu(menu); */

    populateSideBar();


    zoomPlusBtn->setGeometry(width() - 180-2, height() - 30, 60, 30);     /*! -décalage pour avoir bordure Button */
    zoomPlusBtn->show();
    zoomMoinsBtn->setGeometry(width() - 120-1, height() - 30, 60, 30);
    zoomMoinsBtn->show();
    zoomFullBtn->setGeometry(width() - 60, height() - 30, 60, 30);
    zoomFullBtn->show();

    zoomPlusBtn->setStyleSheet(QString(
                    "QPushButton {"
                        /*"background-color: qlineargradient(x1:0, y1:1, x2:1, y2:1,"
                                                          "stop:0 gray, stop:1 black);"*/
                        "background-color: #253645;"
                        "color: white;"
                        "border: none;"
                    "}"
                   "QPushButton:pressed {"
                       "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                         "stop: 0 #dadbde, stop: 1 #f6f7fa);"
                        "color: black;"
                        "border: none;"
                   "}"
                                   )
                );

    zoomMoinsBtn->setStyleSheet(QString(
                    "QPushButton {"
                        "background-color: #253645;"
                        "color: white;"
                        "border: none;"
                    "}"
                   "QPushButton:pressed {"
                       "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                         "stop: 0 #dadbde, stop: 1 #f6f7fa);"
                        "color: black;"
                        "border: none;"
                   "}"
                                   )
                );

    zoomFullBtn->setStyleSheet(QString(
                    "QPushButton {"
                        "background-color: #253645;"
                        "color: white;"
                        "border: none;"
                    "}"
                   "QPushButton:pressed {"
                       "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                         "stop: 0 #dadbde, stop: 1 #f6f7fa);"
                        "color: black;"
                        "border: none;"
                   "}"
                                   )
                );

    ///this->setStyleSheet(StyleHelper::getWindowStyleSheet());

    ui->label_message->setStyleSheet(StyleHelper::getLabelStyleSheet());

    /*ui->toolButton_athena->setStyleSheet(StyleHelper::getMenuStyleSheet());
    ui->toolButton_close->setStyleSheet(StyleHelper::getCloseStyleSheet());
    ui->toolButton_maximize->setStyleSheet(StyleHelper::getMaximizeStyleSheet());
    ui->toolButton_reduce->setStyleSheet(StyleHelper::getMinimizeStyleSheet());*/
    ui->toolButton_stop->setStyleSheet(StyleHelper::getStopStyleSheet());
    ui->toolButton_play->setStyleSheet(StyleHelper::getPlayStyleSheet());
    ui->toolButton_pause->setStyleSheet(StyleHelper::getPauseStyleSheet());
    ui->toolButton_donneesReseau->setStyleSheet(StyleHelper::getToolBarButtonStyleSheet());
    ui->toolButton_calculEtats->setStyleSheet(StyleHelper::getToolBarButtonStyleSheet());
    ui->toolButton_calculPercolation->setStyleSheet(StyleHelper::getToolBarButtonStyleSheet());
    ui->toolButton_dispoAnalytique->setStyleSheet(StyleHelper::getToolBarButtonStyleSheet());
    ui->toolButton_dispoGlobaleSimulation->setStyleSheet(StyleHelper::getToolBarButtonStyleSheet());
    ui->toolButton_dispoSimulation->setStyleSheet(StyleHelper::getToolBarButtonStyleSheet());

    ui->frame_menu->setStyleSheet(StyleHelper::getMenuFrameStyleSheet());
    ui->frame_toolBar->setStyleSheet(StyleHelper::getToolBarFrameStyleSheet());

    //ui->frame_main->setStyleSheet(StyleHelper::getMainFrameStyleSheet());
    ui->toolButton->setStyleSheet(StyleHelper::getMenuButtonStyleSheet());
    ui->toolButton_edition->setStyleSheet(StyleHelper::getMenuButtonStyleSheet());
    ui->toolButton_affichage->setStyleSheet(StyleHelper::getMenuButtonStyleSheet());
    ui->toolButton_calcul->setStyleSheet(StyleHelper::getMenuButtonStyleSheet());
    ui->toolButton_couches->setStyleSheet(StyleHelper::getMenuButtonStyleSheet());
    ui->toolButton_fenetre->setStyleSheet(StyleHelper::getMenuButtonStyleSheet());
    /*ui->btn_next->setStyleSheet(StyleHelper::getNextStyleSheet());
    ui->btn_previous->setStyleSheet(StyleHelper::getPreviousStyleSheet());
    ui->btn_add->setStyleSheet(StyleHelper::getMenuStyleSheet());
    ui->playlistView->setStyleSheet(StyleHelper::getTableViewStyleSheet());
    ui->btn_add->setText(tr("Добавить"));
    ui->btn_next->setCursor(Qt::PointingHandCursor);
    ui->btn_previous->setCursor(Qt::PointingHandCursor);
    ui->btn_stop->setCursor(Qt::PointingHandCursor);
    ui->btn_play->setCursor(Qt::PointingHandCursor);
    ui->btn_pause->setCursor(Qt::PointingHandCursor);*/


    /*menuToolBar = new QToolBar;
    fileMenu = new QMenu("Fichier");
    editMenu = new QMenu("Edition");
    helpMenu = new QMenu("Aide");
    menuBar = new QMenuBar;
    mainToolBar = new QToolBar;
    sceneToolBar = new QToolBar;
    tabBar = new QTabBar;
    stackedWidget = new QStackedWidget;
    mainSplitter = new QSplitter;
    fileNew = new QAction("Nouveau");
    open = new QAction("Ouvrir...");
    save = new QAction("Enregistrer");
    copy = new QAction("Copier");
    paste = new QAction("Coller");
    cut = new QAction("Couper");

    fileMenu->addAction(fileNew);
    fileMenu->addSeparator();
    fileMenu->addAction(open);
    fileMenu->addAction(save);

    editMenu->addAction(cut);
    editMenu->addAction(copy);
    editMenu->addAction(paste);

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(editMenu);
    menuBar->addMenu(helpMenu);

    menuToolBar->addWidget(menuBar);

    //mainLayout->addWidget(menuToolBar);
    mainLayout->addWidget(mainToolBar);
    mainLayout->addWidget(mainSplitter);

    ui->centralWidget->setLayout(mainLayout);*/



    /*QVBoxLayout *layout = new QVBoxLayout;

    QTabBar *bar = new QTabBar;
    QToolBar *tool = new QToolBar;
    QMenuBar *menuBar1 = new QMenuBar;
    QLineEdit *lineEdit = new QLineEdit;

    for (int i=0; i<3; i++) {
        tool->addAction(new QAction(QString("Action %1").arg(i)));
        menuBar1->addAction(new QAction(QString("Action%1").arg(i)));
    }
    QMenu *menu1 = new QMenu("Fichier");
    menu1->addAction(new QAction("Nouveau"));
    menu1->addAction(new QAction("Ouvrir..."));
    menu1->addAction(new QAction("Enregistrer"));
    menuBar1->addMenu(menu1);

    layout->addWidget(bar);
    layout->addWidget(menuBar1);
    layout->addWidget(lineEdit);
    layout->addWidget(tool);

    ui->centralWidget->setLayout(layout);*/
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::populateSideBar()
{
    ui->sideBar->addAction("Accueil", QIcon(":/sidebar/mode_welcome_mask@2x.png"));
    ui->sideBar->addAction("Editer", QIcon(":/sidebar/mode_edit_mask@2x.png"));
    ui->sideBar->addAction("Design", QIcon(":/sidebar/mode_design_mask@2x.png"));
    ui->sideBar->addAction("Aide", QIcon(":/sidebar/mode_help_mask@2x.png"));
}


void MainWindow::onBtnFichierClicked()
{
    ///ui->toolButton_fichier->showMenu();
}

/*QPoint MainWindow::previousPosition() const
{
    return m_previousPosition;
}

void MainWindow::setPreviousPosition(QPoint previousPosition)
{
    if (m_previousPosition == previousPosition)
        return;

    m_previousPosition = previousPosition;
    emit previousPositionChanged(previousPosition);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton ) {
        m_leftMouseButtonPressed = checkResizableField(event);
        setPreviousPosition(event->pos());
    }
    return QWidget::mousePressEvent(event);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_leftMouseButtonPressed = None;
    }
    return QWidget::mouseReleaseEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    switch (m_leftMouseButtonPressed) {
    case Move: {
        if (isMaximized()) {
            ui->toolButton_maximize->setStyleSheet(StyleHelper::getMaximizeStyleSheet());
            this->layout()->setMargin(9);
            auto part = event->screenPos().x() / width();
            this->showNormal();
            auto offsetX = width() * part;
            setGeometry(event->screenPos().x() - offsetX, 0, width(), height());
            setPreviousPosition(QPoint(offsetX, event->y()));
        } else {
            auto dx = event->x() - m_previousPosition.x();
            auto dy = event->y() - m_previousPosition.y();
            setGeometry(x() + dx, y() + dy, width(), height());
        }
        break;
    }
    case Top: {
        if (!isMaximized()) {
        auto dy = event->y() - m_previousPosition.y();
        setGeometry(x(), y() + dy, width(), height() - dy);
        }
        break;
    }
    case Bottom: {
        if (!isMaximized()) {
            auto dy = event->y() - m_previousPosition.y();
            setGeometry(x(), y(), width(), height() + dy);
            setPreviousPosition(event->pos());
        }
        break;
    }
    case Left: {
        if (!isMaximized()) {
            auto dx = event->x() - m_previousPosition.x();
            setGeometry(x() + dx, y(), width() - dx, height());
        }
        break;
    }
    case Right: {
        if (!isMaximized()) {
            auto dx = event->x() - m_previousPosition.x();
            setGeometry(x(), y(), width() + dx, height());
            setPreviousPosition(event->pos());
        }
        break;
    }
    default:
        checkResizableField(event);
        break;
    }
    return QWidget::mouseMoveEvent(event);
}*/

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    zoomPlusBtn->setGeometry(width() - 180-2, height() - 30, 60, 30);
    zoomPlusBtn->show();
    zoomMoinsBtn->setGeometry(width() - 120-1, height() - 30, 60, 30);
    zoomMoinsBtn->show();
    zoomFullBtn->setGeometry(width() - 60, height() - 30, 60, 30);
    zoomFullBtn->show();
}

/*MainWindow::MouseType MainWindow::checkResizableField(QMouseEvent *event)
{
    QPointF position = event->screenPos();
    qreal x = this->x();
    qreal y = this->y();
    qreal width = this->width();
    qreal height = this->height();

    QRectF rectTop(x + 9, y, width - 18, 7);
    QRectF rectBottom(x + 9, y + height - 7, width - 18, 7);
    QRectF rectLeft(x, y + 9, 7, height - 18);
    QRectF rectRight(x + width - 7, y + 9, 7, height - 18);
    QRectF rectInterface(x + 9, y + 9, width - 18, height - 18);

    if (rectTop.contains(position)) {
        setCursor(Qt::SizeVerCursor);
        return Top;
    } else if (rectBottom.contains(position)) {
        setCursor(Qt::SizeVerCursor);
        return Bottom;
    } else if (rectLeft.contains(position)) {
        setCursor(Qt::SizeHorCursor);
        return Left;
    } else if (rectRight.contains(position)) {
        setCursor(Qt::SizeHorCursor);
        return Right;
    } else if (rectInterface.contains(position)){
        setCursor(QCursor());
        return Move;
    } else {
        setCursor(QCursor());
        return None;
    }
}*/
