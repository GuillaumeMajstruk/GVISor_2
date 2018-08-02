/********************************************************************************
** Form generated from reading UI file 'gvi_recap.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GVI_RECAP_H
#define UI_GVI_RECAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gvi_recap
{
public:
    QGridLayout *gridLayout;
    QPushButton *validate_informations_PB;
    QPushButton *modify_informations_PB;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QGroupBox *equipements_missing_GB;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *equipements_non_valides_GB;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *equipements_valides_GB;
    QVBoxLayout *verticalLayout;
    QGroupBox *equipements_collect_GB;
    QVBoxLayout *verticalLayout_5;

    void setupUi(QWidget *gvi_recap)
    {
        if (gvi_recap->objectName().isEmpty())
            gvi_recap->setObjectName(QStringLiteral("gvi_recap"));
        gvi_recap->setWindowModality(Qt::ApplicationModal);
        gvi_recap->resize(2000, 1400);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gvi_recap->sizePolicy().hasHeightForWidth());
        gvi_recap->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        gvi_recap->setFont(font);
        gridLayout = new QGridLayout(gvi_recap);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        validate_informations_PB = new QPushButton(gvi_recap);
        validate_informations_PB->setObjectName(QStringLiteral("validate_informations_PB"));

        gridLayout->addWidget(validate_informations_PB, 3, 0, 1, 1);

        modify_informations_PB = new QPushButton(gvi_recap);
        modify_informations_PB->setObjectName(QStringLiteral("modify_informations_PB"));

        gridLayout->addWidget(modify_informations_PB, 2, 0, 1, 1);

        scrollArea = new QScrollArea(gvi_recap);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1980, 1312));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        equipements_missing_GB = new QGroupBox(scrollAreaWidgetContents);
        equipements_missing_GB->setObjectName(QStringLiteral("equipements_missing_GB"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(equipements_missing_GB->sizePolicy().hasHeightForWidth());
        equipements_missing_GB->setSizePolicy(sizePolicy1);
        equipements_missing_GB->setFlat(false);
        verticalLayout_3 = new QVBoxLayout(equipements_missing_GB);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));

        gridLayout_2->addWidget(equipements_missing_GB, 0, 3, 1, 1);

        equipements_non_valides_GB = new QGroupBox(scrollAreaWidgetContents);
        equipements_non_valides_GB->setObjectName(QStringLiteral("equipements_non_valides_GB"));
        sizePolicy1.setHeightForWidth(equipements_non_valides_GB->sizePolicy().hasHeightForWidth());
        equipements_non_valides_GB->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(equipements_non_valides_GB);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        gridLayout_2->addWidget(equipements_non_valides_GB, 0, 1, 1, 1);

        equipements_valides_GB = new QGroupBox(scrollAreaWidgetContents);
        equipements_valides_GB->setObjectName(QStringLiteral("equipements_valides_GB"));
        sizePolicy1.setHeightForWidth(equipements_valides_GB->sizePolicy().hasHeightForWidth());
        equipements_valides_GB->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(equipements_valides_GB);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        gridLayout_2->addWidget(equipements_valides_GB, 0, 0, 1, 1);

        equipements_collect_GB = new QGroupBox(scrollAreaWidgetContents);
        equipements_collect_GB->setObjectName(QStringLiteral("equipements_collect_GB"));
        equipements_collect_GB->setCheckable(false);
        verticalLayout_5 = new QVBoxLayout(equipements_collect_GB);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));

        gridLayout_2->addWidget(equipements_collect_GB, 0, 4, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(gvi_recap);

        QMetaObject::connectSlotsByName(gvi_recap);
    } // setupUi

    void retranslateUi(QWidget *gvi_recap)
    {
        gvi_recap->setWindowTitle(QApplication::translate("gvi_recap", "Form", Q_NULLPTR));
        validate_informations_PB->setText(QApplication::translate("gvi_recap", "Terminer la GVI", Q_NULLPTR));
        modify_informations_PB->setText(QApplication::translate("gvi_recap", "Modifier les informations", Q_NULLPTR));
        equipements_missing_GB->setTitle(QApplication::translate("gvi_recap", "Equipement(s) Missing", Q_NULLPTR));
        equipements_non_valides_GB->setTitle(QApplication::translate("gvi_recap", "Equipement(s) non Valide(s)", Q_NULLPTR));
        equipements_valides_GB->setTitle(QApplication::translate("gvi_recap", "Equipement(s) Valide(s)", Q_NULLPTR));
        equipements_collect_GB->setTitle(QApplication::translate("gvi_recap", "Equipement(s) Collect(s)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gvi_recap: public Ui_gvi_recap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GVI_RECAP_H
