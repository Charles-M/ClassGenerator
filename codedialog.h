#ifndef CODEDIALOG_H
#define CODEDIALOG_H

#include <QDialog>

class CodeDialog : public QDialog
{
    Q_OBJECT
public:
    CodeDialog(QString title, QString &codeh, QString &codecpp, QWidget *parent = 0);

public slots:
    void save();

private:
    QString title;
    QString codeh;
    QString codecpp;

};

#endif // CODEDIALOG_H
