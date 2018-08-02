#ifndef GLOBAL_FUNCTIONS_H
#define GLOBAL_FUNCTIONS_H

//[INCLUDES]
#   include <QMainWindow>
#   include <QPushButton>
#   include <QWidget>
#   include <QLineEdit>
#   include <QLabel>
#   include <QGroupBox>
#   include <QDate>
#   include <QPalette>
#   include <QtSql/QSqlDatabase>
#   include <QtSql/QSqlDriver>
#   include <QMessageBox>
#   include <QTableWidget>
#   include <QtXlsx>
#   include <QScrollArea>
#   include <QCheckBox>
#   include <QHBoxLayout>
#   include <QGridLayout>
#   include <QFont>
#   include <QFile>
#   include <QFileDialog>
#   include <QTextStream>
#   include <QColor>
#   include <QFrame>
#   include <QComboBox>
#   include <QString>
#   include <QVector>
#   include <QMap>
#   include <QVariant>
#   include <QSpacerItem>
#   include <QPrinter>
#   include <QPrintDialog>
#   include <QDebug>
#   include <QStandardPaths>
#   include <QDir>
#   include <QAxObject>
#   include <QAxWidget>

#   include <iostream>
#   include <ostream>

#   include "Ressources/chantier.h"
#   include "itemgvi.h"
#   include "gvi_recap.h"
#   include "error.h"
#   include "print.h"
//[!INCLUDES]

//[COLOR]
#   define COLOR_RED        QColor(255, 0, 0, 100)
#   define COLOR_GREEN      QColor(50, 255, 50, 200)
#   define ITEM_COLOR_RED   QColor(255, 0, 0, 100)
#   define ITEM_COLOR_BROWN QColor(255, 210, 70, 150)
#   define ITEM_COLOR_GREEN QColor(0, 255, 0, 100)
#   define ITEM_COLOR_GREY  QColor(150, 150, 150, 250)
#   define ITEM_COLOR_BLUE  QColor(0, 0, 250, 100)
//[!COLOR]

//[EXPORT COLOR]
#   define EXPORT_COLOR_GREEN   QColor(0, 150, 0, 100)
#   define EXPORT_COLOR_RED     QColor(255, 0, 0, 100)
#   define EXPORT_COLOR_GREY    QColor(50, 50, 50, 250)
#   define EXPORT_COLOR_BLUE    QColor(0, 0, 180, 100)
//[!EXPORT COLOR]

//[LABEL STYLESHEET]
#   define LBL_SS_GREEN     "QLabel { background-color : rgba(0,255,0,0.5); color : dark; }"
#   define LBL_SS_RED       "QLabel { background-color : rgba(255,0,0,0.5); color : dark; }"
#   define LBL_SS_GREY      "QLabel { background-color : rgba(200,200,200,0.8); color : dark; }"
#   define LBL_SS_BLUE      "QLabel { background-color : rgba(0,0,200,0.3); color : dark; }"
//[!LABEL STYLESHEET]

//[BASE CONSTANTS]
#   define CST_ZERO     0
#   define CST_TEN      10
#   define CST_HUNDRED  100
#   define CST_THOUSAND 1000
//[!BASE CONSTANTS]

//[SIZE CONSTANTS]
#   define SN_SIZE      6
#   define WO_SIZE      8
#   define CL_SIZE      3
#   define OP_NAME_SIZE 3
//[!SIZE CONSTANTS]

//[PARSER SERPARATORS]
//#   define START        '{'
//#   define END          '}'
//#   define KEY_VAL_SEP  ':'
//#   define KEY_SEP      "'"
#   define EQ_FLAG      "eq-"
//[!PARSER SERPARATORS]

//[ENABLE/DISABLE DEBUG]

//#   define DEBUG //to show basics debug informations in the console
//#   define CALL_DEBUG //to print functions calls in the console

//[!ENABLE/DISABLE DEBUG]

//[TIME CONSTANTS (in ms)]
#   define T_FIVE_S 5000
#   define T_TEN_S 10000
//[!TIME CONSTANTS]

//[ERROR CODES]
    //[SOFT_INIT]
    #   define LOCALDIR_INIT_ERRNUM                 "2"
    #   define LOCALDIR_INIT_ERRTITLE                "ON SOFTWARE INITIALISATION"
    #   define LOCALDIR_INIT_ERRDES                 "L'initialisation du programme a échouée."

    #   define LOADUSERS_INIT_ERRNUM                 "22"
    #   define LOADUSERS_INIT_ERRTITLE               "Erreur !"
    #   define LOADUSERS_INIT_ERRDES                 "Impossible de charger la liste des operateurs disponibles !"
    //[!SOFT_INIT]
    //[RUNTIME_ERROR]
    #   define INTERFACE_INIT_ERRNUM                "3"
    #   define INTERFACE_INIT_ERRTITLE               "ON RUNTIME INTERFACE INITIALISATION"
    #   define INTERFACE_INIT_ERRDES                "L'initialisation de l'interface du programme a échouée."

    #   define LOADING_SAVE_PROPERTIES_ERRNUM       "4"
    #   define LOADING_SAVE_PROPERTIES_ERRTITLE      "ON RUNTIME / LOADING A SAVE FILE"
    #   define LOADING_SAVE_PROPERTIES_ERRDES       "Le programme de chargement a échoué.\nLe fichier en chargement est peut-être corrompue."

    #   define LOADING_SAVE_PARSE_ERRNUM            "5"
    #   define LOADING_SAVE_PARSE_ERRTITLE           "ON RUNTIME / LOADING A SAVE FILE"
    #   define LOADING_SAVE_PARSE_ERRDES            "Le fichier que vous essayez de charger semble être corrompue. Essayez un autre fichier."

    #   define OPENING_FILE_ERRNUM                  "6"
    #   define OPENING_FILE_ERRTITLE                "ON RUNTIME / OPENING A SAVE FILE"
    #   define OPENING_FILE_ERRDES                  "L'ouverture de ce fichier semble être impossible."

    #   define CREATING_FILE_ERRNUM                 "7"
    #   define CREATING_FILE_ERRTITLE               "ON RUNTIME / CREATING A FILE"
    #   define CREATING_FILE_ERRDES                 "Erreur à la tentative de création du fichier"

    //[!RUNTIME_ERROR]

    //[RUNTIME_NON_CRITICAL_ERROR]
    #   define RECOVERABLE_ERRNUM                   "42"
    #   define WRONG_SN_CHARSET_ERRTITLE            "Erreur !"
    #   define WRONG_SN_CHARSET_ERRDES              "le SN du moteur ne doit comporter que des chiffres"

    #   define WRONG_WORK_ORDER_CHARSET_ERRTITLE    "Erreur !"
    #   define WRONG_WORK_ORDER_CHARSET_ERRDES      "le numero de lancement ne doit comporter que des chiffres"

    #   define WRONG_CLIENT_NAME_CHARSET_ERRTITLE   "Erreur !"
    #   define WRONG_CLIENT_NAME_CHARSET_ERRDES     "la dénomination du client ne doit comporter que des lettres"

    #   define WRONG_OPERATOR_NAME_CHARSET_ERRTITLE "Attention !"
    #   define WRONG_OPERATOR_NAME_CHARSET_ERRDES   "Les noms ne sont composés géneralement que de lettres\nSi vous voulez ajouter un utilisateur, séparez les noms par un espace."

    #   define WRONG_SN_ERRTITLE                    "Erreur !"
    #   define WRONG_SN_ERRDES                      "le SN du moteur entré est incorrect (6 chiffres uniquement) ou inconnue"

    #   define USER_NOT_FOUND_ERRTITLE              "Utilisateur non trouvé !"
    #   define USER_NOT_FOUND_ERRDES                "Le matricule que vous avez entré semble incorrect, essayez avec un autre."

    #   define USER_EMPTY_ERRTITLE                  "Le champ est vide !"
    #   define USER_EMPTY_ERRDES                    "Vous devez rentrer un matricule au format 'mXXXXXX'."
    //[!RUNTIME_NON_CRITICAL_ERROR]
//[/ERROR CODES]

//[LOCAL PATHS]
#   define PATH_EXPORT_SAVE             qApp->applicationDirPath() + "/GVIs/Gvi_In_Progress/"
#   define PATH_EXPORT_FINISHED         qApp->applicationDirPath() + "/GVIs/Gvi_Finished/"
//[!LOCAL PATHS]

bool    strIsDigit(const QString& a_str);
bool    strIsAlpha(const QString& a_str);
bool    strIsAlnum(const QString& a_str);
bool    strIsAlphaWithSpace(const QString& a_str);
void    setBackgroundColor(QWidget *an_object, QColor a_color);

#endif // GLOBAL_FUNCTIONS_H
