/********************************************************************************
** Form generated from reading UI file 'connectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONDIALOG_H
#define UI_CONNECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_connectionDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *matricule_lbl;
    QLineEdit *matricule_LE;
    QPushButton *ok_button;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_2;

    void setupUi(QDialog *connectionDialog)
    {
        if (connectionDialog->objectName().isEmpty())
            connectionDialog->setObjectName(QStringLiteral("connectionDialog"));
        connectionDialog->resize(400, 100);
        QFont font;
        font.setPointSize(12);
        connectionDialog->setFont(font);
        gridLayout = new QGridLayout(connectionDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        matricule_lbl = new QLabel(connectionDialog);
        matricule_lbl->setObjectName(QStringLiteral("matricule_lbl"));

        gridLayout->addWidget(matricule_lbl, 0, 0, 1, 1);

        matricule_LE = new QLineEdit(connectionDialog);
        matricule_LE->setObjectName(QStringLiteral("matricule_LE"));

        gridLayout->addWidget(matricule_LE, 1, 0, 1, 1);

        ok_button = new QPushButton(connectionDialog);
        ok_button->setObjectName(QStringLiteral("ok_button"));

        gridLayout->addWidget(ok_button, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(connectionDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 1, 1, 1);


        retranslateUi(connectionDialog);

        QMetaObject::connectSlotsByName(connectionDialog);
    } // setupUi

    void retranslateUi(QDialog *connectionDialog)
    {
        connectionDialog->setWindowTitle(QApplication::translate("connectionDialog", "Dialog", Q_NULLPTR));
        matricule_lbl->setText(QApplication::translate("connectionDialog", "Entrez votre matricule", Q_NULLPTR));
        ok_button->setText(QApplication::translate("connectionDialog", "Valider", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("connectionDialog", "Quitter", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class connectionDialog: public Ui_connectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONDIALOG_H
