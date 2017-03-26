#include "defframe.h"

#include <QFormLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QRegExpValidator>

DefFrame::DefFrame(QWidget *parent) : QGroupBox(parent)
{
    QFormLayout *lay = new QFormLayout();
    setTitle("Définition de la classe");

    name.setValidator(new QRegExpValidator(QRegExp("[A-Z][A-z0-9_]*")));
    name.setText("Classe");
    name.setFixedWidth(200);
    base.setText("Mere");
    base.setFixedWidth(200);

    lay->addRow("&Nom : ", &name);
    lay->addRow("Classe &mère : ", &base);
    setLayout(lay);
}

