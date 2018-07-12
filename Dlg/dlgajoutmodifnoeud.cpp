#include "dlgajoutmodifnoeud.h"
#include "ui_dlgajoutmodifnoeud.h"

DlgAjoutModifNoeud::DlgAjoutModifNoeud(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgAjoutModifNoeud)
{
    ui->setupUi(this);
}

DlgAjoutModifNoeud::~DlgAjoutModifNoeud()
{
    delete ui;
}
