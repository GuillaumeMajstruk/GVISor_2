#include "print.h"

void    printFile(const QString &file_to_print)
{
    if (file_to_print.isEmpty())
        return;
    QAxObject *excel = new QAxObject("Excel.Application", 0);
    excel->setProperty("Visible", true);
    QAxObject *wbs = excel->querySubObject("Workbooks");
    QAxObject *wb = wbs->querySubObject("Open(const QString&)", file_to_print);
    wbs = nullptr;
    wb = nullptr;
    excel = nullptr;

    delete (wbs);
    delete (wb);
    delete (excel);
}
