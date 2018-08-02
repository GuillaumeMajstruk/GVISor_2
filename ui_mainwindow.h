/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOptions;
    QAction *actionCharger;
    QAction *actionA_propos_de_GVInspector;
    QAction *actionA_propos_de_Qt;
    QAction *actionImprimer;
    QAction *actionOuvrir_l_aide_de_GVIsor;
    QAction *actionAutoriser_les_modifications;
    QAction *actionBloquer_les_modifications;
    QAction *actionQuitter;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *valider_gvi_PB;
    QGroupBox *chantier_GB;
    QGridLayout *gridLayout_2;
    QGroupBox *moteur_GB;
    QGridLayout *gridLayout_3;
    QLabel *type_moteur_LBL;
    QLineEdit *sn_moteur_TOEDIT;
    QLabel *type_moteur_TOEDIT;
    QLabel *sn_moteur_LBL;
    QGroupBox *operateurs_GB;
    QGridLayout *gridLayout_4;
    QLabel *nom_operateurs_LBL;
    QLineEdit *nom_operateurs_TOEDIT;
    QLabel *current_user_LBL;
    QLabel *current_user_TOEDIT;
    QLineEdit *n_lancement_TOEDIT;
    QLineEdit *client_TOEDIT;
    QLabel *n_lancement_LBL;
    QLabel *date_LBL;
    QLabel *date_TOEDIT;
    QPushButton *valider_informations_chantier_PB;
    QLabel *client_LBL;
    QProgressBar *progressBar;
    QScrollArea *liste_equipements_QSA;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuAide;
    QMenu *menuOptions;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1280, 935);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionCharger = new QAction(MainWindow);
        actionCharger->setObjectName(QStringLiteral("actionCharger"));
        actionA_propos_de_GVInspector = new QAction(MainWindow);
        actionA_propos_de_GVInspector->setObjectName(QStringLiteral("actionA_propos_de_GVInspector"));
        actionA_propos_de_Qt = new QAction(MainWindow);
        actionA_propos_de_Qt->setObjectName(QStringLiteral("actionA_propos_de_Qt"));
        actionImprimer = new QAction(MainWindow);
        actionImprimer->setObjectName(QStringLiteral("actionImprimer"));
        actionOuvrir_l_aide_de_GVIsor = new QAction(MainWindow);
        actionOuvrir_l_aide_de_GVIsor->setObjectName(QStringLiteral("actionOuvrir_l_aide_de_GVIsor"));
        actionAutoriser_les_modifications = new QAction(MainWindow);
        actionAutoriser_les_modifications->setObjectName(QStringLiteral("actionAutoriser_les_modifications"));
        actionAutoriser_les_modifications->setFont(font);
        actionBloquer_les_modifications = new QAction(MainWindow);
        actionBloquer_les_modifications->setObjectName(QStringLiteral("actionBloquer_les_modifications"));
        actionBloquer_les_modifications->setFont(font);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        valider_gvi_PB = new QPushButton(centralWidget);
        valider_gvi_PB->setObjectName(QStringLiteral("valider_gvi_PB"));
        valider_gvi_PB->setEnabled(false);
        valider_gvi_PB->setFont(font);

        gridLayout->addWidget(valider_gvi_PB, 7, 0, 1, 1);

        chantier_GB = new QGroupBox(centralWidget);
        chantier_GB->setObjectName(QStringLiteral("chantier_GB"));
        chantier_GB->setFont(font);
        gridLayout_2 = new QGridLayout(chantier_GB);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        moteur_GB = new QGroupBox(chantier_GB);
        moteur_GB->setObjectName(QStringLiteral("moteur_GB"));
        gridLayout_3 = new QGridLayout(moteur_GB);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        type_moteur_LBL = new QLabel(moteur_GB);
        type_moteur_LBL->setObjectName(QStringLiteral("type_moteur_LBL"));
        type_moteur_LBL->setFont(font);

        gridLayout_3->addWidget(type_moteur_LBL, 1, 0, 1, 1);

        sn_moteur_TOEDIT = new QLineEdit(moteur_GB);
        sn_moteur_TOEDIT->setObjectName(QStringLiteral("sn_moteur_TOEDIT"));
        sn_moteur_TOEDIT->setMaxLength(6);

        gridLayout_3->addWidget(sn_moteur_TOEDIT, 0, 2, 1, 1);

        type_moteur_TOEDIT = new QLabel(moteur_GB);
        type_moteur_TOEDIT->setObjectName(QStringLiteral("type_moteur_TOEDIT"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        type_moteur_TOEDIT->setFont(font1);
        type_moteur_TOEDIT->setTextFormat(Qt::RichText);

        gridLayout_3->addWidget(type_moteur_TOEDIT, 1, 2, 1, 1);

        sn_moteur_LBL = new QLabel(moteur_GB);
        sn_moteur_LBL->setObjectName(QStringLiteral("sn_moteur_LBL"));
        sn_moteur_LBL->setFont(font);

        gridLayout_3->addWidget(sn_moteur_LBL, 0, 0, 1, 1);


        gridLayout_2->addWidget(moteur_GB, 0, 4, 1, 1);

        operateurs_GB = new QGroupBox(chantier_GB);
        operateurs_GB->setObjectName(QStringLiteral("operateurs_GB"));
        gridLayout_4 = new QGridLayout(operateurs_GB);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        nom_operateurs_LBL = new QLabel(operateurs_GB);
        nom_operateurs_LBL->setObjectName(QStringLiteral("nom_operateurs_LBL"));
        nom_operateurs_LBL->setFont(font);

        gridLayout_4->addWidget(nom_operateurs_LBL, 1, 0, 1, 1);

        nom_operateurs_TOEDIT = new QLineEdit(operateurs_GB);
        nom_operateurs_TOEDIT->setObjectName(QStringLiteral("nom_operateurs_TOEDIT"));

        gridLayout_4->addWidget(nom_operateurs_TOEDIT, 1, 1, 1, 1);

        current_user_LBL = new QLabel(operateurs_GB);
        current_user_LBL->setObjectName(QStringLiteral("current_user_LBL"));

        gridLayout_4->addWidget(current_user_LBL, 0, 0, 1, 1);

        current_user_TOEDIT = new QLabel(operateurs_GB);
        current_user_TOEDIT->setObjectName(QStringLiteral("current_user_TOEDIT"));

        gridLayout_4->addWidget(current_user_TOEDIT, 0, 1, 1, 1);


        gridLayout_2->addWidget(operateurs_GB, 6, 0, 1, 5);

        n_lancement_TOEDIT = new QLineEdit(chantier_GB);
        n_lancement_TOEDIT->setObjectName(QStringLiteral("n_lancement_TOEDIT"));
        n_lancement_TOEDIT->setMaxLength(8);

        gridLayout_2->addWidget(n_lancement_TOEDIT, 0, 2, 1, 1);

        client_TOEDIT = new QLineEdit(chantier_GB);
        client_TOEDIT->setObjectName(QStringLiteral("client_TOEDIT"));
        client_TOEDIT->setMaxLength(3);

        gridLayout_2->addWidget(client_TOEDIT, 3, 2, 1, 1);

        n_lancement_LBL = new QLabel(chantier_GB);
        n_lancement_LBL->setObjectName(QStringLiteral("n_lancement_LBL"));
        n_lancement_LBL->setFont(font);

        gridLayout_2->addWidget(n_lancement_LBL, 0, 0, 1, 1);

        date_LBL = new QLabel(chantier_GB);
        date_LBL->setObjectName(QStringLiteral("date_LBL"));
        date_LBL->setFont(font);

        gridLayout_2->addWidget(date_LBL, 1, 0, 1, 1);

        date_TOEDIT = new QLabel(chantier_GB);
        date_TOEDIT->setObjectName(QStringLiteral("date_TOEDIT"));
        date_TOEDIT->setFont(font);

        gridLayout_2->addWidget(date_TOEDIT, 1, 2, 1, 1);

        valider_informations_chantier_PB = new QPushButton(chantier_GB);
        valider_informations_chantier_PB->setObjectName(QStringLiteral("valider_informations_chantier_PB"));
        valider_informations_chantier_PB->setEnabled(false);

        gridLayout_2->addWidget(valider_informations_chantier_PB, 7, 0, 1, 5);

        client_LBL = new QLabel(chantier_GB);
        client_LBL->setObjectName(QStringLiteral("client_LBL"));
        client_LBL->setFont(font);

        gridLayout_2->addWidget(client_LBL, 3, 0, 1, 1);


        gridLayout->addWidget(chantier_GB, 2, 0, 1, 1);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setStyleSheet(QLatin1String("QProgressBar\n"
"{\n"
"	text-align:center;\n"
"	border:2px solid white;\n"
"	border-radius:10px;\n"
"}\n"
"QProgressBar::Chunk\n"
"{\n"
"	background-color:rgb(0, 255, 0);\n"
"	border-radius:5px;\n"
"	margin:2px;\n"
"}\n"
""));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 8, 0, 1, 1);

        liste_equipements_QSA = new QScrollArea(centralWidget);
        liste_equipements_QSA->setObjectName(QStringLiteral("liste_equipements_QSA"));
        liste_equipements_QSA->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        liste_equipements_QSA->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        liste_equipements_QSA->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        liste_equipements_QSA->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1252, 493));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        liste_equipements_QSA->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(liste_equipements_QSA, 5, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 24));
        menuBar->setFont(font);
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuFichier->setFont(font);
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QStringLiteral("menuAide"));
        menuAide->setFont(font);
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QFont font2;
        font2.setPointSize(14);
        statusBar->setFont(font2);
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(n_lancement_TOEDIT, sn_moteur_TOEDIT);
        QWidget::setTabOrder(sn_moteur_TOEDIT, client_TOEDIT);
        QWidget::setTabOrder(client_TOEDIT, nom_operateurs_TOEDIT);
        QWidget::setTabOrder(nom_operateurs_TOEDIT, valider_informations_chantier_PB);
        QWidget::setTabOrder(valider_informations_chantier_PB, valider_gvi_PB);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionCharger);
        menuFichier->addSeparator();
        menuFichier->addAction(actionImprimer);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuAide->addAction(actionA_propos_de_GVInspector);
        menuAide->addSeparator();
        menuAide->addAction(actionA_propos_de_Qt);
        menuAide->addSeparator();
        menuAide->addAction(actionOuvrir_l_aide_de_GVIsor);
        menuAide->addSeparator();
        menuOptions->addAction(actionAutoriser_les_modifications);
        menuOptions->addAction(actionBloquer_les_modifications);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOptions->setText(QApplication::translate("MainWindow", "Options", Q_NULLPTR));
        actionCharger->setText(QApplication::translate("MainWindow", "Charger une GVI...", Q_NULLPTR));
        actionA_propos_de_GVInspector->setText(QApplication::translate("MainWindow", "A propos de General Visual Inspector...", Q_NULLPTR));
        actionA_propos_de_Qt->setText(QApplication::translate("MainWindow", "A propos de Qt...", Q_NULLPTR));
        actionImprimer->setText(QApplication::translate("MainWindow", "Imprimer des documents...", Q_NULLPTR));
        actionOuvrir_l_aide_de_GVIsor->setText(QApplication::translate("MainWindow", "Ouvrir l'aide de GVIsor...", Q_NULLPTR));
        actionAutoriser_les_modifications->setText(QApplication::translate("MainWindow", "Autoriser les modifications...", Q_NULLPTR));
        actionBloquer_les_modifications->setText(QApplication::translate("MainWindow", "Bloquer les modifications...", Q_NULLPTR));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        valider_gvi_PB->setText(QApplication::translate("MainWindow", "V\303\251rifier les informations", Q_NULLPTR));
        chantier_GB->setTitle(QApplication::translate("MainWindow", "Chantier", Q_NULLPTR));
        moteur_GB->setTitle(QApplication::translate("MainWindow", "Moteur", Q_NULLPTR));
        type_moteur_LBL->setText(QApplication::translate("MainWindow", "Type moteur", Q_NULLPTR));
        type_moteur_TOEDIT->setText(QString());
        sn_moteur_LBL->setText(QApplication::translate("MainWindow", "SN moteur", Q_NULLPTR));
        operateurs_GB->setTitle(QApplication::translate("MainWindow", "Op\303\251rateur(s)", Q_NULLPTR));
        nom_operateurs_LBL->setText(QApplication::translate("MainWindow", "Nom du ou des op\303\251rateur(s)", Q_NULLPTR));
        current_user_LBL->setText(QApplication::translate("MainWindow", "Utilisateur Actuel :", Q_NULLPTR));
        current_user_TOEDIT->setText(QString());
        n_lancement_LBL->setText(QApplication::translate("MainWindow", "Num\303\251ro de lancement", Q_NULLPTR));
        date_LBL->setText(QApplication::translate("MainWindow", "Date", Q_NULLPTR));
        date_TOEDIT->setText(QApplication::translate("MainWindow", "CURRENT_ DATE", Q_NULLPTR));
        valider_informations_chantier_PB->setText(QApplication::translate("MainWindow", "Prendre en compte les informations du chantier", Q_NULLPTR));
        client_LBL->setText(QApplication::translate("MainWindow", "Client", Q_NULLPTR));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", Q_NULLPTR));
        menuAide->setTitle(QApplication::translate("MainWindow", "Aide", Q_NULLPTR));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
