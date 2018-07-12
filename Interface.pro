#-------------------------------------------------
#
# Project created by QtCreator 2018-06-12T23:26:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Interface
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    Dlg/dlgajoutmodifnoeud.cpp \
    document.cpp \
    doctype1.cpp \
    doctype2.cpp \
    stylehelper.cpp \
    sidebar.cpp

HEADERS += \
        mainwindow.h \
    Dlg/dlgajoutmodifnoeud.h \
    document.h \
    doctype1.h \
    doctype2.h \
    stylehelper.h \
    sidebar.h

FORMS += \
    Dlg/dlgajoutmodifnoeud.ui \
    mainwindowFrameless.ui \
    mainwindow.ui

RESOURCES += \
    ressource.qrc
