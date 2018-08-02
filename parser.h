#ifndef PARSER_H
#define PARSER_H

#   include "global_functions.h"
#   define PARSER_LINE_DELIM    ":"

namespace Parser
{
bool parseSaveFile(const QString &file_line, QMap<QString, QStringList> &eq_map);
}

#endif // PARSER_H
