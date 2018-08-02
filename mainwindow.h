#ifndef MAINWINDOW_H
#   define MAINWINDOW_H

#   include "global_functions.h"
#   include "connectiondialog.h"
#   include "export.h"
#   include "parser.h"

typedef QMap<QString /*item name*/, QStringList /*item parameters*/> eq_map;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit            MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Chantier            *chantier;

private:
    Ui::MainWindow      *ui;
    bool                m_engineSnIsValid = false;
    bool                m_workorderNumIsValid = false;
    bool                m_clientIsValid = false;
    bool                m_operatorNameIsValid = false;
    bool                m_chantierIsValid = false;

    QString             current_date;
    QLabel              *date_label;

    QString             m_inputSN;
    QString             m_workOrder;
    QString             m_client;
    QString             m_operatorsName;


    QLineEdit           *sn_moteur_toedit = nullptr;
    QPushButton         *valider_informations_chantier_pb = nullptr;
    QGroupBox           *chantier_gb = nullptr;
    QLabel              *type_moteur_toedit = nullptr;
    QLineEdit           *n_lancement_toedit = nullptr;
    QLineEdit           *client_toedit = nullptr;
    QLineEdit           *nom_operateurs_toedit = nullptr;
    QScrollArea         *liste_equipements_qsa = nullptr;
    QVector<ItemGvi*>   equipement_list;
    gvi_recap           *recap = nullptr;
    QDir                m_current_paths;
    QString             m_current_file_name;
    eq_map              m_eq_to_load;
    bool                m_onLoad = false;

    QString             m_current_user_name;

private:
    void                connectUser(void);
    void                initializeUi(void);
    void                setupDirs(void);
    void                setDate(void);
    void                loadChildWidget(void);
    void                setWindowPropreties(void);
    void                setWidgetsConnection(void);
    void                setupIcons(void);

    void                loadFromDatabase(QWidget *eq, QVBoxLayout *l);
    void                loadFromSaveFile(QWidget *eq, QVBoxLayout *l);
    void                onLoad_connectItem(ItemGvi *current_it);
    void                clearEquipementList(void);
#ifdef DEBUG
    void                loadDefaultEquipementList(void);
#endif
private slots:
    void                updateSN(const QString& input_SN);
    void                updateWorkOrder(const QString& input_WO);
    void                updateClient(const QString& input_CLIENT);
    void                updateOperatorsName(const QString& input_OP);
    void                updateEngineType(void);
    void                updateChantierStatusColor(bool inputValue);
    void                updateProgressBarValue();

    void                loadEquipementList(void);

    void                aboutGvinspector();
    void                checkInformations(void);
    void                checkAllEquipementsStatus(void);

    void                showGviRecap(void);
    void                exportGVI(void);

    void                saveGviTemp(void);
    void                autoSave(void);
    void                loadStartedGvi(void);
    void                showHelp(void);
    void                printDocuments(void);
    void                allowModifications(void);
    void                blockModifications(void);
    void                closeEvent(QCloseEvent *event);
    void                onQuitButtonClick(void);
signals:
    void                validerInformationsChantier(bool newStatus);
    void                allEquipementsHasStatus(bool status);
    void                checkSN_auto(void);

};

#endif // MAINWINDOW_H
