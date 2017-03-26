#ifndef ATTRIBFRAME_H
#define ATTRIBFRAME_H

#include <QGroupBox>
#include <QLineEdit>
#include <QListWidget>

class AttribFrame : public QGroupBox
{
    Q_OBJECT

public:
    AttribFrame(QWidget *parent = 0);

public slots:
    void addAttribut();
    void delAttribut();

private:
    QLineEdit *name;
    QLineEdit *type;
    QListWidget *list;
    QListWidget *listget;
    QListWidget *listset;

    friend class MainFrame;
};

#endif // ATTRIBFRAME_H
