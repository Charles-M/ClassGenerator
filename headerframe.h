#ifndef HEADERFRAME_H
#define HEADERFRAME_H

#include <QGroupBox>
#include <QListWidget>
#include <QLineEdit>

class HeaderFrame : public QGroupBox
{
    Q_OBJECT

public:
    HeaderFrame(QWidget *parent = 0);

public slots:
    void addHeader();
    void delHeader();

private:
    QLineEdit *name;
    QListWidget *list;

    friend class MainFrame;
};

#endif // HEADERFRAME_H
