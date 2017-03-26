#include "commentframe.h"

#include <QFormLayout>

CommentFrame::CommentFrame(QWidget *parent) : QGroupBox(parent)
{
    setCheckable(true);
    setTitle("Ajouter des commentaires");
    date.setCalendarPopup(true);
    date.setMinimumDate(QDate::currentDate());

    QFormLayout *lay = new QFormLayout();

    lay->addRow("&Auteur : ", &author);
    lay->addRow("Da&te de création : ", &date);
    lay->addRow("&Rôle de la classe : ", &description);
    setLayout(lay);
}
