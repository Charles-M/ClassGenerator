#include "codedialog.h"

#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>

CodeDialog::CodeDialog(QString title, QString &codeh, QString &codecpp, QWidget *parent)
    : QDialog(parent), title(title), codeh(codeh), codecpp(codecpp)
{
    QTextEdit *texth = new QTextEdit;
    texth->setFont(QFont("Courier"));
    texth->setLineWrapMode(QTextEdit::NoWrap);
    texth->setPlainText(codeh);
    texth->setReadOnly(true);

    QTextEdit *textcpp = new QTextEdit;
    textcpp->setFont(QFont("Courier"));
    textcpp->setLineWrapMode(QTextEdit::NoWrap);
    textcpp->setPlainText(codecpp);
    textcpp->setReadOnly(true);

    QTabWidget *tab = new QTabWidget;
    tab->addTab(texth, QIcon(), title+".h");
    tab->addTab(textcpp, QIcon(), title+".cpp");

    QPushButton *close = new QPushButton("Fermer");
    connect(close, SIGNAL(clicked()), this, SLOT(accept()));
    QPushButton *save = new QPushButton("Enregistrer");
    connect(save, SIGNAL(clicked()), this, SLOT(save()));

    QVBoxLayout *lay = new QVBoxLayout;
    lay->addWidget(tab);
    lay->addWidget(save);
    lay->addWidget(close);

    setLayout(lay);
    resize(400, 500);
}

void CodeDialog::save(){
    QString dir = QFileDialog::getExistingDirectory();

    QFile file(dir+"/"+title+".h");
    file.open(QFile::WriteOnly);
    QTextStream stream(&file);
    stream << codeh;
    file.close();

    file.setFileName(dir+"/"+title+".cpp");
    file.open(QFile::WriteOnly);
    stream << (codecpp);
    file.close();
}
