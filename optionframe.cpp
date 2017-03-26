#include "optionframe.h"

#include <QVBoxLayout>

OptionFrame::OptionFrame(QWidget *parent) : QGroupBox(parent)
{
    setTitle("Options");
    QVBoxLayout *lay = new QVBoxLayout;
    protect.setText("Protéger le &header contre les inclusions multiples");
    construct.setText("Générer un &constructeur par défaut");
    destruct.setText("Générer un &destructeur");
    header.setEnabled(protect.isChecked());

    lay->addWidget(&protect);
    lay->addWidget(&header);
    lay->addWidget(&construct);
    lay->addWidget(&destruct);

    connect(&protect, SIGNAL(clicked(bool)), &header, SLOT(setEnabled(bool)));

    setLayout(lay);

}

void OptionFrame::editHead(QString text){
    header.setText("HEADER_"+text.toUpper());
}
