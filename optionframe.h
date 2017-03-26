#ifndef OPTIONFRAME_H
#define OPTIONFRAME_H

#include <QGroupBox>
#include <QCheckBox>
#include <QLineEdit>
#include <vector>

class OptionFrame : public QGroupBox
{
    Q_OBJECT
public:
    OptionFrame(QWidget *parent = 0);

public slots:
    void editHead(QString text);

private:
    QCheckBox protect;
    QCheckBox construct;
    QCheckBox destruct;
    QLineEdit header;

    friend class MainFrame;

};

#endif // OPTIONFRAME_H
