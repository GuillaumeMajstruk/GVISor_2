#include "export.h"

using namespace QXlsx;

/*
 * Fonction qui créer une ébauche de tableau vierge pour
 * la création d'une étiquette à poser sur la servante
 * après la GVI
*/
Document    *createEmptyGviLabel(int nb_of_elem)
{
    Document *doc = new Document();
    Format RowFormat;
    RowFormat.setHorizontalAlignment(Format::AlignHCenter);
    RowFormat.setVerticalAlignment(Format::AlignVCenter);
    RowFormat.setFontSize(72);
    RowFormat.setBorderStyle(Format::BorderThick);
    doc->setColumnWidth(CellRange("A1", "F1"), 15);
    doc->setRowHeight(1, 100);
    doc->mergeCells(CellRange("A1", "F1"), RowFormat);
    RowFormat.setFontSize(42);
    doc->mergeCells(CellRange("A2", "C2"), RowFormat);
    RowFormat.setFontSize(36);
    doc->mergeCells(CellRange("D2", "F2"), RowFormat);
    Format general;
    general.setFontBold(true);
    general.setBorderStyle(Format::BorderMedium);
    general.setHorizontalAlignment(Format::AlignHCenter);
    for (int i = 3; i <= nb_of_elem + 3; i++)
    {
        doc->mergeCells(CellRange(QString("A%1").arg(i), QString("C%1").arg(i)), general);
        doc->mergeCells(CellRange(QString("D%1").arg(i), QString("F%1").arg(i)), general);
    }
    doc->write("A3", "DESIGNATION", general);
    doc->write("D3", "STATUS", general);
    return (doc);
}

/*
 * Fonction d'exporation des informations de la gvi vers le format xlsx
 * une verification de la structure des repertoires doit avoir ete faite
 * HEADER_LINES correspond au nombre de lignes utilisées pour l'entête
 * (SN moteur, Compagnie, WorkOrder)
 * Ces informations sont définies de la façon suivante:
 *      -> ENGINE_SN_SLOT représente la str qui indique la case dans laquelle écrire l'information
 *      -> CLIENT_NME_SLOT "                                                                       "
 *      -> WORK_ORDER_SLOT "                                                                       "
*/
void    exportGVILabel(QString &current_file, const Chantier &c, const QVector<ItemGvi*> &eqts)
{
    QString exp_file_name(PATH_EXPORT_FINISHED + QString("%1_%2_%3.xlsx").arg(c.getEngine()->getEngineSN()).arg(c.getNumeroLancement()).arg(QDate::currentDate().toString("ddMMyyyy")));
    current_file = exp_file_name;
    Document *exp = createEmptyGviLabel(eqts.size());

    exp->write(ENGINE_SN_SLOT, c.getEngine()->getEngineSN().toInt());
    exp->write(CLIENT_NME_SLOT, c.getCompanyName());
    exp->write(WORK_ORDER_SLOT, c.getNumeroLancement().toInt());
    for (int i = 0; i < eqts.size(); i++)
    {
        int delta_lines = i + HEADER_LINES;
        Format *fontColor = &exp->cellAt(CellReference(QString("A%1").arg(delta_lines)))->format();
        if (eqts[i]->getEquipementStatus() == equipementStatus::VALIDE)
            fontColor->setFontColor(EXPORT_COLOR_GREEN);
        else if (eqts[i]->getEquipementStatus() == equipementStatus::NON_VALIDE)
            fontColor->setFontColor(EXPORT_COLOR_RED);
        else if (eqts[i]->getEquipementStatus() == equipementStatus::MISSING)
            fontColor->setFontColor(EXPORT_COLOR_GREY);
        else if (eqts[i]->getEquipementStatus() == equipementStatus::COLLECT)
            fontColor->setFontColor(EXPORT_COLOR_BLUE);
        (eqts[i]->getEquipementStatusDescription() == "Description optionnelle." || eqts[i]->getEquipementStatusDescription().isEmpty()) ?
                    exp->write(delta_lines, 4, eqts[i]->getEquipementStatusStr(), *fontColor):
                    exp->write(delta_lines, 4, eqts[i]->getEquipementStatusStr() + " (" + eqts[i]->getEquipementStatusDescription() + ").", *fontColor);
        exp->write(delta_lines, 1, eqts[i]->objectName(), *fontColor);
    }
    if (!exp->saveAs(exp_file_name))
        QMessageBox::warning(NULL, "Problème de lecture / écriture.",
                             QString("Attention il est impossible d'écrire dans le fichier '%1' peut être est-il déjà ouvert ?!").arg(exp_file_name));
    else
        QMessageBox::information(NULL, "Enregistrement réussi !", QString("Le fichier %1 a été correctement enregistré !").arg(exp_file_name));

    exp = nullptr;
    delete (exp);
}
