#include "attribframe.h"

#include <QLayout>
#include <QPushButton>
#include <QLabel>

AttribFrame::AttribFrame(QWidget *parent) : QGroupBox(parent)
{
    setTitle("Liste des Attributs");

    type = new QLineEdit;
    name = new QLineEdit;
    QPushButton *del = new QPushButton("<--");
    QPushButton *add = new QPushButton("-->");

    list = new QListWidget;
    list->setFixedWidth(100);
    list->setAlternatingRowColors(true);

    QPalette pal(list->palette());
    pal.setColor(QPalette::Base, QColor(0, 0, 0, 0));
    listget = new QListWidget;
    listget->setFixedWidth(100);
    listget->setPalette(pal);
    listget->setEditTriggers(QAbstractItemView::CurrentChanged);
    listset = new QListWidget;
    listset->setFixedWidth(100);
    listset->setPalette(pal);
    listset->setEditTriggers(QAbstractItemView::CurrentChanged);

    QVBoxLayout *vlay1 = new QVBoxLayout;
    vlay1->setAlignment(Qt::AlignVCenter);
    vlay1->addWidget(new QLabel("Type de l'attribut :"));
    vlay1->addWidget(type);
    vlay1->addWidget(new QLabel("Nom de l'attribut :"));
    vlay1->addWidget(name);

    QVBoxLayout *vlay2 = new QVBoxLayout;
    vlay2->setAlignment(Qt::AlignVCenter);
    vlay2->addWidget(add);
    vlay2->addWidget(del);

    QHBoxLayout *hlay = new QHBoxLayout;
    hlay->addLayout(vlay1);
    hlay->addLayout(vlay2);
    hlay->addWidget(list);
    hlay->addWidget(listget);
    hlay->addWidget(listset);

    setLayout(hlay);
    connect(add, SIGNAL(clicked(bool)), this, SLOT(addAttribut()));
    connect(del, SIGNAL(clicked(bool)), this, SLOT(delAttribut()));
    connect(name, SIGNAL(returnPressed()), add, SLOT(click()));

}

void AttribFrame::addAttribut(){
    if(name->text().isEmpty() || type->text().isEmpty()) return;
    QString nom = name->text();
    QString typ = type->text();
    name->clear();
    new QListWidgetItem(typ+" "+nom, list);

    QString nomCap = nom[0].toUpper()+nom.mid(1);
    QListWidgetItem *itemset = new QListWidgetItem("set"+nomCap, listset);
    itemset->setFlags(itemset->flags() | Qt::ItemIsUserCheckable | Qt::ItemIsEditable);
    itemset->setCheckState(Qt::Unchecked);
    QListWidgetItem *itemget = new QListWidgetItem("get"+nomCap, listget);
    itemget->setFlags(itemget->flags() | Qt::ItemIsUserCheckable | Qt::ItemIsEditable);
    itemget->setCheckState(Qt::Checked);
}

void AttribFrame::delAttribut(){
    listset->takeItem(list->currentRow());
    listget->takeItem(list->currentRow());
    list->takeItem(list->currentRow());
}
