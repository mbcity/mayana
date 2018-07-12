#ifndef STYLEHELPER_H
#define STYLEHELPER_H

#include <QString>

class StyleHelper
{
public:
    static QString getWindowStyleSheet();
    static QString getLabelStyleSheet();
    static QString getCloseStyleSheet();
    static QString getMaximizeStyleSheet();
    static QString getRestoreStyleSheet();
    static QString getMinimizeStyleSheet();
    static QString getNextStyleSheet();
    static QString getPreviousStyleSheet();
    static QString getStopStyleSheet();
    static QString getPlayStyleSheet();
    static QString getPauseStyleSheet();
    static QString getMenuStyleSheet();
    static QString getTableViewStyleSheet();
    static QString getToolBarButtonStyleSheet();
    static QString getMenuButtonStyleSheet();
    static QString getMenuFrameStyleSheet();
    static QString getMainFrameStyleSheet();
    static QString getToolBarFrameStyleSheet();
};

#endif // STYLEHELPER_H
