#include "parser.h"

bool Parser::parseSaveFile(const QString &input, QMap<QString, QStringList>&eq_map)
{
    QString key, value;
    QStringList lst;
    QStringList val_lst;


    lst = input.split(":");
    if (lst.size() > 2 || lst.size() < 2)
        return (false);
    key = lst.at(0);
    value = lst.at(1);
    val_lst = value.split('|');
    eq_map.insertMulti(key, val_lst);
    return (true);
}
