#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QWidget>
#include "defframe.h"
#include "optionframe.h"
#include "commentframe.h"
#include "codedialog.h"
#include "attribframe.h"
#include "headerframe.h"

class MainFrame : public QWidget
{
    Q_OBJECT
public:
    MainFrame(QWidget *parent = 0);

signals:

public slots:
    void submit();

private:
    DefFrame defClass;
    HeaderFrame header;
    AttribFrame attributs;
    OptionFrame option;
    CommentFrame com;
    QWidget foot;

};

#endif // MAINFRAME_H
