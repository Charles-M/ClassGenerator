#ifndef DEFFRAME_H
#define DEFFRAME_H

#include <QGroupBox>
#include <QLineEdit>

class DefFrame : public QGroupBox
{
public:
    DefFrame(QWidget *parent = 0);

private:
    QLineEdit name;
    QLineEdit base;

    friend class MainFrame;
};

#endif // DEFFRAME_H
