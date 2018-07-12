#ifndef DLGAJOUTMODIFNOEUD_H
#define DLGAJOUTMODIFNOEUD_H

#include <QDialog>

namespace Ui {
class DlgAjoutModifNoeud;
}

class DlgAjoutModifNoeud : public QDialog
{
    Q_OBJECT

public:
    explicit DlgAjoutModifNoeud(QWidget *parent = 0);
    ~DlgAjoutModifNoeud();

private:
    Ui::DlgAjoutModifNoeud *ui;
};

#endif // DLGAJOUTMODIFNOEUD_H
