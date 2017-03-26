#include "headerframe.h"

#include <QPushButton>
#include <QLayout>
#include <QLabel>

HeaderFrame::HeaderFrame(QWidget *parent) : QGroupBox(parent)
{
    setTitle("Liste des Headers");

    name = new QLineEdit;
    name->setFixedWidth(200);
    QPushButton *del = new QPushButton("<--");
    QPushButton *add = new QPushButton("-->");

    list = new QListWidget;
    list->setFixedWidth(200);
    list->setAlternatingRowColors(true);

    QVBoxLayout *vlay1 = new QVBoxLayout;
    vlay1->setAlignment(Qt::AlignVCenter);
    vlay1->addWidget(new QLabel("Nom du header :"));
    vlay1->addWidget(name);

    QVBoxLayout *vlay2 = new QVBoxLayout;
    vlay2->setAlignment(Qt::AlignVCenter);
    vlay2->addWidget(add);
    vlay2->addWidget(del);

    QHBoxLayout *hlay = new QHBoxLayout;
    hlay->addLayout(vlay1);
    hlay->addLayout(vlay2);
    hlay->addWidget(list);

    setLayout(hlay);
    connect(add, SIGNAL(clicked(bool)), this, SLOT(addHeader()));
    connect(del, SIGNAL(clicked(bool)), this, SLOT(delHeader()));
    connect(name, SIGNAL(returnPressed()), add, SLOT(click()));
}

void HeaderFrame::addHeader(){
    if(name->text().isEmpty()) return;

    new QListWidgetItem(name->text(), list);
    name->clear();
}

void HeaderFrame::delHeader(){
    list->takeItem(list->currentRow());
}
