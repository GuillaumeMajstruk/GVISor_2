#ifndef EXPORT_H
#define EXPORT_H

#include "global_functions.h"

#define     HEADER_LINES    4
#define     ENGINE_SN_SLOT  "A1"
#define     WORK_ORDER_SLOT "D2"
#define     CLIENT_NME_SLOT "A2"

QXlsx::Document     *createEmptyGviLabel(int nb_of_elem);
void                exportGVILabel(QString& current_file, const Chantier& c, const QVector<ItemGvi *> &eqts);

#endif // EXPORT_H
