#include "global_functions.h"

bool    strIsDigit(const QString& a_str)
{
    for (int i = 0; i < a_str.size(); i++)
    {
        if (!a_str.at(i).isDigit())
            return (false);
    }
    return (true);
}

bool    strIsAlpha(const QString& a_str)
{
    for (int i = 0; i < a_str.size(); i++)
    {
        if (!a_str.at(i).isLetter())
            return (false);
    }
    return (true);
}

bool    strIsAlnum(const QString &a_str)
{
    for (int i = 0; i < a_str.size(); i++)
    {
        if (!a_str.at(i).isLetter() && !a_str.at(i).isDigit() && a_str.at(i) != " ")
            return (false);
    }
    return (true);
}

bool    strIsAlphaWithSpace(const QString &a_str)
{
    for (int i = 0; i < a_str.size(); i++)
    {
        if (!a_str.at(i).isLetter() && a_str.at(i) != " " && a_str.at(i) != "-")
            return (false);
    }
    return (true);
}

void setBackgroundColor(QWidget *an_object, QColor a_color)
{
    if (!an_object)
        throw error(ErrorType::Critical, INTERFACE_INIT_ERRTITLE, INTERFACE_INIT_ERRDES, INTERFACE_INIT_ERRNUM);
    an_object->setAutoFillBackground(true);
    QPalette p;
    p.setColor(QPalette::Background, a_color);
    an_object->setPalette(p);
}
