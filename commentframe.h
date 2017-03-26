#ifndef COMMENTFRAME_H
#define COMMENTFRAME_H

#include <QGroupBox>
#include <QLineEdit>
#include <QDateEdit>
#include <QTextEdit>

class CommentFrame : public QGroupBox
{
public:
    CommentFrame(QWidget *parent = 0);

private:
    QLineEdit author;
    QDateEdit date;
    QTextEdit description;

    friend class MainFrame;
};

#endif // COMMENTFRAME_H
