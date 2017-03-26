#include "mainframe.h"

#include <QVBoxLayout>
#include <QIcon>
#include <QPushButton>
#include <QApplication>
#include <QMessageBox>
#include <vector>

MainFrame::MainFrame(QWidget *parent) : QWidget(parent)
{
    setWindowIcon(QIcon(":/icon.jpg"));

    // construction Foot
        QHBoxLayout *footlay = new QHBoxLayout;
        QPushButton *buttOk = new QPushButton("Générer !");
        QPushButton *buttKo = new QPushButton("Quitter");
        footlay->addStretch();
        footlay->addWidget(buttOk);
        footlay->addWidget(buttKo);
        foot.setLayout(footlay);
        connect(buttKo, SIGNAL(clicked()), qApp, SLOT(quit()));
        connect(buttOk, SIGNAL(clicked()), this, SLOT(submit()));
        connect(&defClass.name, SIGNAL(textChanged(QString)), &option, SLOT(editHead(QString)));

    // constuction mainframe
        QVBoxLayout *lay = new QVBoxLayout;
        lay->addWidget(&defClass);
        lay->addWidget(&header);
        lay->addWidget(&attributs);
        lay->addWidget(&option);
        lay->addWidget(&com);
        lay->addWidget(&foot);

    setLayout(lay);
}

void MainFrame::submit(){
    // check name
    QString className = defClass.name.text();
    if(className.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Le nom de la classe est obligatoire (et doit commencer par une majuscule).");
        return;
    }

    // construct text
    QString contentcpp;
    QString contenth;
    if(com.isChecked()){
        contenth += "/*\n";
        contenth += "Auteur : " + com.author.text() + "\n";
        contenth += "Date de création : " + com.date.date().toString() + "\n\n";
        contenth += "Rôle :\n" + com.description.toPlainText() + "\n*/\n\n" ;
        contentcpp += "/*\n";
        contentcpp += "Auteur : " + com.author.text() + "\n";
        contentcpp += "Date de création : " + com.date.date().toString() + "\n\n";
        contentcpp += "Rôle :\n" + com.description.toPlainText() + "\n*/\n\n" ;
    }

    if(option.protect.isChecked()){
        contenth += "#ifndef " + option.header.text() + "\n";
        contenth += "#define " + option.header.text() + "\n\n";
    }
    for(int i =0; i < header.list->count(); i++)
        contenth += "#include \""+header.list->item(i)->text()+".h\"\n";

    if(!defClass.base.text().isEmpty()) contenth += "#include \"" + defClass.base.text() + ".h\"\n\n";
    contenth += "class " + className;
    contentcpp += "#include \"" + className + ".h\"\n";

    if(!defClass.base.text().isEmpty()) contenth += " : public " + defClass.base.text();
    contenth += "\n{\n    public:\n";

    if(option.construct.isChecked()) {
        contenth += "        " + className + "();\n";
        contentcpp += "\n"+className + "::" + className + "() {\n\n}\n";
    }
    if(option.destruct.isChecked()) {
        contenth += "        ~" + className + "();\n";
        contentcpp += "\n"+className + "::~" + className + "() {\n\n}\n";
    }

    // *********** GETTER SETTER ******
    for(int i =0; i < attributs.listget->count(); i++){
        QString type = attributs.list->item(i)->text().split(' ')[0];
        QString var = attributs.list->item(i)->text().split(' ')[1];
        if(attributs.listget->item(i)->checkState()){
            QString getName = attributs.listget->item(i)->text();
            contenth += "        "+type+" "+getName+"() const;\n";
            contentcpp += "\n"+type+" "+className+"::"+getName+"() const {\n    return "+var+";\n}\n";
        }
        if(attributs.listset->item(i)->checkState()){
            QString setName = attributs.listset->item(i)->text();
            contenth += "        void "+setName+"("+type+" const& _"+var+");\n";
            contentcpp += "\nvoid "+className+"::"+setName+"("+type+" const& _"+var+"){\n    "+var+" = _"+var+";\n}\n";
        }
    }
    // ********************************

    contenth += "\n    protected:\n\n    private:\n";

    for(int i =0; i < attributs.list->count(); i++){
        contenth += "        "+attributs.list->item(i)->text()+";\n";
    }
    contenth += "\n};";

    if(option.protect.isChecked())
        contenth += "\n\n#endif // " + option.header.text() + "\n";


    // call qdialog
    CodeDialog dial(className, contenth, contentcpp);
    dial.exec();
}
