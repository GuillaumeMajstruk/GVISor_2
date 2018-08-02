 #include "mainwindow.h"
#include "error.h"
#include "ui_mainwindow.h"

using namespace QXlsx;

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    try
    {
        connectUser();
        initializeUi();
        setDate();
        loadChildWidget();
        setWindowPropreties();
        setWidgetsConnection();
        setupIcons();
        setupDirs();
        nom_operateurs_toedit->setText(m_operatorsName);
        nom_operateurs_toedit->setEnabled(false);
    }
    catch(error& s_error)
    {
        s_error.display();
        exit(s_error.getErrorNum().toInt());
    }
}

MainWindow::~MainWindow()
{
    ui = nullptr;


    date_label = nullptr;
    sn_moteur_toedit = nullptr;
    valider_informations_chantier_pb = nullptr;
    chantier_gb = nullptr;
    type_moteur_toedit = nullptr;
    n_lancement_toedit = nullptr;
    client_toedit = nullptr;
    nom_operateurs_toedit = nullptr;
    liste_equipements_qsa = nullptr;
    recap = nullptr;

    delete (date_label);
    delete (sn_moteur_toedit);
    delete (valider_informations_chantier_pb);
    delete (chantier_gb);
    delete (type_moteur_toedit);
    delete (n_lancement_toedit);
    delete (client_toedit);
    delete (nom_operateurs_toedit);
    delete (liste_equipements_qsa);
    delete (recap);
    clearEquipementList();

    delete (ui);
}

void    MainWindow::connectUser(void)
{
    connectionDialog *c = new connectionDialog;
    int con = c->exec();
    if (!con)
        exit(0);
    m_operatorsName = c->getOperatorName().toUpper();
    m_current_user_name = m_operatorsName;

    c = nullptr;
    delete(c);
    return ;
}

void    MainWindow::initializeUi(void)
{
    ui->setupUi(this);
    ui->progressBar->setHidden(true);
    ui->progressBar->setValue(0);
    ui->liste_equipements_QSA->setEnabled(false);
    ui->actionAutoriser_les_modifications->setEnabled(false);
    ui->actionBloquer_les_modifications->setEnabled(false);
    ui->current_user_TOEDIT->setText(m_current_user_name);
}

void    MainWindow::setDate(void)
{
    QDate *date = new QDate();
    current_date = date->currentDate().toString("dd/MM/yyyy");
    date_label = findChild<QLabel*>("date_TOEDIT");
    date_label->setText(current_date);

    delete(date);
}

void    MainWindow::loadChildWidget(void)
{
    if (!(sn_moteur_toedit = findChild<QLineEdit*>("sn_moteur_TOEDIT")) ||
            !(valider_informations_chantier_pb = findChild<QPushButton*>("valider_informations_chantier_PB")) ||
            !(chantier_gb = findChild<QGroupBox*>("chantier_GB")) ||
            !(type_moteur_toedit = findChild<QLabel*>("type_moteur_TOEDIT")) ||
            !(n_lancement_toedit = findChild<QLineEdit*>("n_lancement_TOEDIT")) ||
            !(client_toedit = findChild<QLineEdit*>("client_TOEDIT")) ||
            !(nom_operateurs_toedit = findChild<QLineEdit*>("nom_operateurs_TOEDIT")) ||
            !(liste_equipements_qsa = findChild<QScrollArea*>("liste_equipements_QSA")))
    {
        throw error(ErrorType::Critical, INTERFACE_INIT_ERRTITLE, INTERFACE_INIT_ERRDES, INTERFACE_INIT_ERRNUM);
    }
}

void    MainWindow::setupDirs(void)
{
    if (!m_current_paths.mkpath(PATH_EXPORT_SAVE) ||
        !m_current_paths.mkpath(PATH_EXPORT_FINISHED))
        throw error(ErrorType::Critical, LOCALDIR_INIT_ERRTITLE, LOCALDIR_INIT_ERRDES, LOCALDIR_INIT_ERRNUM);
}

void    MainWindow::setWindowPropreties(void)
{
    setWindowTitle("");
    setWindowState(Qt::WindowMaximized);
    chantier_gb->setAutoFillBackground(true);
    try
    {
        setBackgroundColor(chantier_gb, COLOR_RED);
    }
    catch(error& err)
    {
        err.display();
        exit(err.getErrorNum().toInt());
    }
}

void    MainWindow::setWidgetsConnection(void)
{
    connect(sn_moteur_toedit, &QLineEdit::textChanged, this, &MainWindow::updateSN);
    connect(n_lancement_toedit, &QLineEdit::textChanged, this, &MainWindow::updateWorkOrder);
    connect(client_toedit, &QLineEdit::textChanged, this, &MainWindow::updateClient);
    connect(nom_operateurs_toedit, &QLineEdit::textChanged, this, &MainWindow::updateOperatorsName);
    connect(valider_informations_chantier_pb, &QPushButton::clicked, this, &MainWindow::loadEquipementList);

    connect(this, &MainWindow::checkSN_auto, this, &MainWindow::updateEngineType);
    connect(this, &MainWindow::validerInformationsChantier, this, &MainWindow::updateChantierStatusColor);
    connect(this, &MainWindow::allEquipementsHasStatus, ui->valider_gvi_PB, &QPushButton::setEnabled);

    connect(ui->actionA_propos_de_Qt, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(ui->actionA_propos_de_GVInspector, &QAction::triggered, this, &MainWindow::aboutGvinspector);
    connect(ui->valider_gvi_PB, &QPushButton::clicked, this, &MainWindow::showGviRecap);
    connect(ui->actionCharger, &QAction::triggered, this, &MainWindow::loadStartedGvi);
    connect(ui->actionOuvrir_l_aide_de_GVIsor, &QAction::triggered, this, &MainWindow::showHelp);
    connect(ui->actionImprimer, &QAction::triggered, this, &MainWindow::printDocuments);
    connect(ui->actionAutoriser_les_modifications, &QAction::triggered, this, &MainWindow::allowModifications);
    connect(ui->actionBloquer_les_modifications, &QAction::triggered, this, &MainWindow::blockModifications);
    connect(ui->actionQuitter, &QAction::triggered, this, &MainWindow::onQuitButtonClick);
}

void    MainWindow::setupIcons(void)
{
    ui->actionCharger->setIcon(QIcon("Ressources/img/Icons/doc_ico/add_document.ico"));
    ui->actionA_propos_de_GVInspector->setIcon(QIcon("Ressources/img/Icons/basic_ico/about.ico"));
    ui->actionA_propos_de_Qt->setIcon(QIcon("Ressources/img/Icons/basic_ico/about.ico"));
    ui->actionOuvrir_l_aide_de_GVIsor->setIcon(QIcon("Ressources/img/Icons/basic_ico/help.ico"));
    ui->actionAutoriser_les_modifications->setIcon(QIcon("Ressources/img/Icons/basic_ico/done.ico"));
    ui->actionBloquer_les_modifications->setIcon(QIcon("Ressources/img/Icons/basic_ico/error.ico"));
}

void    MainWindow::updateSN(const QString &input_SN)
{
    if (!strIsDigit(input_SN))
    {
        error(ErrorType::Recoverable, WRONG_SN_CHARSET_ERRTITLE, WRONG_SN_CHARSET_ERRDES, RECOVERABLE_ERRNUM).display();
        sn_moteur_toedit->setText("");
        return ;
    }
    m_inputSN = input_SN;
    m_engineSnIsValid = (m_inputSN.size() == SN_SIZE) ? true : false;
    checkInformations();
    if (!m_engineSnIsValid)
        type_moteur_toedit->setText("");
    else
        emit checkSN_auto();
}

void    MainWindow::updateWorkOrder(const QString& input_WO)
{
    if (!strIsDigit(input_WO))
    {
        error(ErrorType::Recoverable, WRONG_WORK_ORDER_CHARSET_ERRTITLE, WRONG_WORK_ORDER_CHARSET_ERRDES, RECOVERABLE_ERRNUM).display();
        n_lancement_toedit->setText("");
        return ;
    }
    m_workOrder = input_WO;
    m_workorderNumIsValid = (m_workOrder.size() >= WO_SIZE) ? true : false;
    checkInformations();
}

void    MainWindow::updateClient(const QString &input_CLIENT)
{
    if (!strIsAlpha(input_CLIENT))
    {
        error(ErrorType::Recoverable, WRONG_CLIENT_NAME_CHARSET_ERRTITLE, WRONG_CLIENT_NAME_CHARSET_ERRDES, RECOVERABLE_ERRNUM).display();
        client_toedit->setText("");
        return ;
    }
    m_client = input_CLIENT;
    m_clientIsValid = (m_client.size() == CL_SIZE) ? true : false;
    checkInformations();
}

void    MainWindow::updateOperatorsName(const QString &input_OP)
{
    if (!strIsAlphaWithSpace(input_OP))
    {
        error(ErrorType::Recoverable, WRONG_OPERATOR_NAME_CHARSET_ERRTITLE, WRONG_OPERATOR_NAME_CHARSET_ERRDES, RECOVERABLE_ERRNUM).display();
        nom_operateurs_toedit->setText("");
        return ;
    }
    if (input_OP.size() >= OP_NAME_SIZE)
    {
        m_operatorsName = input_OP.toUpper();
        m_operatorNameIsValid = true;
    }
    else
        m_operatorNameIsValid = false;
    checkInformations();
}

void    MainWindow::updateEngineType(void)
{
    chantier = new Chantier(m_inputSN);
    if (chantier->getEngine()->getEngineType() != engineType::Error)
        type_moteur_toedit->setText(chantier->getEngine()->getEngineTypeStr());
    else
    {
        error(ErrorType::Recoverable, WRONG_SN_ERRTITLE, WRONG_SN_ERRDES, RECOVERABLE_ERRNUM).display();
        sn_moteur_toedit->setText("");
        type_moteur_toedit->setText("");
    }
    checkInformations();
}

void    MainWindow::checkInformations(void)
{
    if ((m_engineSnIsValid && m_workorderNumIsValid && m_clientIsValid && !(type_moteur_toedit->text().isEmpty())
         && m_operatorNameIsValid))
    {
        m_chantierIsValid = true;
        valider_informations_chantier_pb->setEnabled(true);
        chantier->setNumeroLancement(m_workOrder);
        chantier->setCompanyName(m_client.toUpper());
    }
    else
    {
        m_chantierIsValid = false;
        valider_informations_chantier_pb->setEnabled(false);
    }
    emit validerInformationsChantier(m_chantierIsValid);
}

void    MainWindow::updateChantierStatusColor(bool inputValue)
{
    try
    {
        if (inputValue)
            setBackgroundColor(chantier_gb, COLOR_GREEN);
        else
            setBackgroundColor(chantier_gb, COLOR_RED);
    }
    catch(error& err)
    {
        err.display();
        exit(err.getErrorNum().toInt());
    }
}

void    MainWindow::updateProgressBarValue()
{
    float j = 0;
    for (int i = 0; i < equipement_list.size(); i++)
        if (equipement_list.at(i)->getEquipementStatus() != equipementStatus::NO_STATUS)
            j++;
    ui->progressBar->setValue((j / equipement_list.size()) * 100);
}

void    MainWindow::loadEquipementList()
{
    QWidget *eq = new QWidget;
    QVBoxLayout *l = new QVBoxLayout;

    if (m_eq_to_load.isEmpty())
        loadFromDatabase(eq, l);
    else
        loadFromSaveFile(eq, l);
    eq->setLayout(l);
    liste_equipements_qsa->setWidget(eq);
    chantier_gb->setDisabled(true);
    ui->progressBar->setHidden(false);
    liste_equipements_qsa->setEnabled(true);
    ui->actionAutoriser_les_modifications->setEnabled(true);
    ui->actionBloquer_les_modifications->setEnabled(true);

    eq = nullptr;
    l = nullptr;
    delete(eq);
    delete(l);
}

void    MainWindow::loadFromDatabase(QWidget *eq, QVBoxLayout *l)
{
    int current_col = 1;

    //Premier chargement depuis la base de donnees
    Document x(":/database/Ressources/excel_files/equipement_list.xlsx");
    x.selectSheet(chantier->getEngine()->getEngineTypeStr());
    for (int current_row = 1; current_row <= x.currentWorksheet()->dimension().lastRow(); current_row++)
    {
        QString current_val = x.read(current_row, current_col).toString();
        ItemGvi *current_it = new ItemGvi(eq);
        current_it->setToolTip(QString("PN, SN de l'equipement N_%1 (%2), "
                               "ainsi que la ref de doc seront chargés et accessibles depuis ce Tooltip").arg(current_row).arg(current_val));
        current_it->setToolTipDuration(T_TEN_S);
        current_it->findChild<QLabel*>("equipement_name_LBL")->setText(current_val);
        current_it->setObjectName(current_val);
        onLoad_connectItem(current_it);
        equipement_list.push_back(current_it);
        l->addWidget(current_it);

        current_it = nullptr;
        delete (current_it);
    }
}

void    MainWindow::loadFromSaveFile(QWidget *eq, QVBoxLayout *l)
{
    // Il y avait deja des elements dans la liste suite a un chargement prealablement effectue
    // on reinitialise la liste
    if (!equipement_list.isEmpty())
        equipement_list = QVector<ItemGvi*>();

    QStringList key_list = m_eq_to_load.keys();
    for (int i = 0; i < key_list.size(); i++)
    {
        //Le nom de l'item tel qu'il doit apparaitre
        QString current_it_name = key_list.at(i);
        if (current_it_name.contains(EQ_FLAG))
        {
            //Le nom de l'equipement dans le fichier de sauvegarde
            QString current_it_saved_name = current_it_name;
            current_it_name.replace(EQ_FLAG, "");
            ItemGvi *current_it = new ItemGvi(eq);
            current_it->findChild<QLabel*>("equipement_name_LBL")->setText(current_it_name);
            current_it->setObjectName(current_it_name);
            current_it->setToolTip(QString("PN, SN de l'equipement N_%1 (%2), "
                                   "ainsi que la ref de doc seront chargés et accessibles depuis ce Tooltip").arg(i + 1).arg(current_it_name));
            current_it->setToolTipDuration(T_TEN_S);
            try
            {
                current_it->loadingUpdate(m_eq_to_load.value(current_it_saved_name));
            }
            catch(error err)
            {
                err.display();
                exit(err.getErrorNum().toInt());
            }
            onLoad_connectItem(current_it);
            equipement_list.push_back(current_it);
            l->addWidget(current_it);
            (current_it->equipementHasStatus()) ? current_it->setEnabled(false) : current_it->setEnabled(true);

            current_it = nullptr;
            delete (current_it);
        }
    }
    checkAllEquipementsStatus();
    updateProgressBarValue();
}

void    MainWindow::onLoad_connectItem(ItemGvi *current_it)
{
    connect(current_it->findChild<QCheckBox*>("VALIDE"), &QCheckBox::clicked, this, &MainWindow::checkAllEquipementsStatus);
    connect(current_it->findChild<QCheckBox*>("NON VALIDE"), &QCheckBox::clicked, this, &MainWindow::checkAllEquipementsStatus);
    connect(current_it->findChild<QCheckBox*>("MISSING"), &QCheckBox::clicked, this, &MainWindow::checkAllEquipementsStatus);
    connect(current_it->findChild<QCheckBox*>("COLLECT"), &QCheckBox::clicked, this, &MainWindow::checkAllEquipementsStatus);
    connect(current_it, &ItemGvi::statusChanged, this, &MainWindow::updateProgressBarValue);
    connect(current_it, &ItemGvi::statusChanged, this, &MainWindow::autoSave);
}

void    MainWindow::clearEquipementList(void)
{
    for (auto x: equipement_list)
    {
        x = nullptr;
        delete (x);
    }
    return ;
}

void    MainWindow::checkAllEquipementsStatus()
{
    for (int i = 0; i < equipement_list.size(); i++)
        if (equipement_list[i]->getEquipementStatus() == equipementStatus::NO_STATUS)
            return;
    emit allEquipementsHasStatus(true);
    return;
}

void    MainWindow::showGviRecap(void)
{
    if (recap)
        delete (recap);
    recap = new gvi_recap();
    QGroupBox *valide = recap->findChild<QGroupBox*>("equipements_valides_GB");
    QVBoxLayout *valide_lay = qobject_cast<QVBoxLayout*>(valide->layout());
    QGroupBox *non_valide = recap->findChild<QGroupBox*>("equipements_non_valides_GB");
    QVBoxLayout *non_valide_lay = qobject_cast<QVBoxLayout*>(non_valide->layout());
    QGroupBox *missing = recap->findChild<QGroupBox*>("equipements_missing_GB");
    QVBoxLayout *missing_lay = qobject_cast<QVBoxLayout*>(missing->layout());
    QGroupBox *collect = recap->findChild<QGroupBox*>("equipements_collect_GB");
    QVBoxLayout *collect_lay = qobject_cast<QVBoxLayout*>(collect->layout());

    for (int i = 0; i < equipement_list.size(); i++)
    {
        QLabel *l = new QLabel;
        if (equipement_list[i]->getEquipementStatus() == equipementStatus::VALIDE)
        {
            valide_lay->addWidget(l);
            l->setStyleSheet(LBL_SS_GREEN);
        }
        else if (equipement_list[i]->getEquipementStatus() == equipementStatus::NON_VALIDE)
        {
            non_valide_lay->addWidget(l);
            l->setStyleSheet(LBL_SS_RED);
        }
        else if (equipement_list[i]->getEquipementStatus() == equipementStatus::MISSING)
        {
            missing_lay->addWidget(l);
            l->setStyleSheet(LBL_SS_GREY);
        }
        else if (equipement_list[i]->getEquipementStatus() == equipementStatus::COLLECT)
        {
            collect_lay->addWidget(l);
            l->setStyleSheet(LBL_SS_BLUE);
        }
        l->setText(equipement_list[i]->objectName());
        l->show();
    }
    valide_lay->addStretch();
    non_valide_lay->addStretch();
    missing_lay->addStretch();
    collect_lay->addStretch();
    connect(recap, &gvi_recap::exportRequired, this, &MainWindow::exportGVI);
    recap->setWindowState(Qt::WindowMaximized);
    recap->show();

    valide = nullptr;
    non_valide = nullptr;
    missing = nullptr;
    collect = nullptr;
    valide_lay = nullptr;
    non_valide_lay = nullptr;
    missing_lay = nullptr;
    collect_lay = nullptr;

    delete (valide);
    delete (non_valide);
    delete (missing);
    delete (collect);
    delete (valide_lay);
    delete (non_valide_lay);
    delete (missing_lay);
    delete (collect_lay);
}

void    MainWindow::exportGVI()
{
    QMessageBox ask_for_validation;
    ask_for_validation.setText(QString("<b>Les informations que vous avez rentrées sont sur le point "
                               "d'être enregistrées...</b>"));
    ask_for_validation.setInformativeText(  "Si elles sont correctes, cliquez sur 'Save'\n"
                                            "sinon cliquez sur 'Cancel'.");
    ask_for_validation.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    int ret = ask_for_validation.exec();
    switch(ret)
    {
    case QMessageBox::Save:
        exportGVILabel(m_current_file_name, *chantier, equipement_list);
        break;
    case QMessageBox::Cancel:
        recap->close();
        return ;
    }
    QMessageBox ask_for_print;
    ask_for_print.setText(QString("Voulez-vous imprimer l'étiquette pour la servante ?"));
    QPushButton *print = ask_for_print.addButton("Print", QMessageBox::YesRole);
    ask_for_print.setStandardButtons(QMessageBox::Cancel);
    ask_for_print.exec();
    if (ask_for_print.clickedButton() == print)
        printFile(m_current_file_name);
    else
        ask_for_print.close();
    recap->close();

    print = nullptr;
    delete (print);
}

/*
 * Enregistrement d'une GVI en cours ou terminee de facon a pouvoir la charger
*/
void    MainWindow::saveGviTemp(void)
{
       QFile    tmp;

       m_current_paths.setCurrent(PATH_EXPORT_SAVE);
       tmp.setFileName(m_current_paths.path() + "/" + QString("%1_%2_%3.gtmp").arg(chantier->getEngine()->getEngineSN()).arg(chantier->getNumeroLancement()).arg(QDate::currentDate().toString("ddMMyyyy")));

       if (!tmp.open(QIODevice::WriteOnly | QIODevice::Text))
       {
           error(ErrorType::Critical, CREATING_FILE_ERRTITLE, CREATING_FILE_ERRDES, CREATING_FILE_ERRNUM).display();
           return ;
       }
       QTextStream t(&tmp);
       t << "engine_sn:" << chantier->getEngine()->getEngineSN() << "\n"
         << "work_order_number:" << chantier->getNumeroLancement() << "\n"
         << "company_name:" << chantier->getCompanyName() << "\n"
         << "engine_type:" << chantier->getEngine()->getEngineTypeStr() << "\n"
         << "operator_name:" << m_operatorsName << "\n";
       for (int i = 0; i < equipement_list.size(); i++)
       {
           ItemGvi *current = equipement_list[i];
           // si le fichier est deja ecrit on ne reecris pas le flag avant chaque equipements
           if (current->equipement_name_lbl->text().contains(EQ_FLAG))
               t << current->equipement_name_lbl->text();
           else
              t << EQ_FLAG + current->equipement_name_lbl->text();
           if (current->getEquipementStatus() == equipementStatus::NON_VALIDE || current->getEquipementStatus() == equipementStatus::MISSING)
           {
               t << ":" << current->getEquipementStatusStr() << '|' << current->list_defauts_qcb->currentText()
                 << '|' << current->choice_defauts_qcb->currentText() << '|' << current->description_defaut_le->text() << "\n";
           }
           else
               t << ':' << current->getEquipementStatusStr() << '\n';

           current = nullptr;
           delete(current);
       }
       if (!nom_operateurs_toedit->text().contains(m_current_user_name))
       {
           m_operatorsName = m_eq_to_load.value("operator_name").at(0) + " " + m_current_user_name;
           nom_operateurs_toedit->setText(m_operatorsName);
       }
       return ;
}

void    MainWindow::autoSave(void)
{
    saveGviTemp();
    ui->statusBar->showMessage("Enregistrement automatique effectué...", T_FIVE_S);
    return ;
}

/*
 * Fonction de chargement d'une GVI deja commencee
 * EN TEST
*/
void    MainWindow::loadStartedGvi(void)
{
    ui->valider_gvi_PB->setEnabled(false);
    QFile load = QFileDialog::getOpenFileName(NULL, "Charger une GVI", PATH_EXPORT_SAVE, "*.gtmp");
    QFileInfo f_info(load);

    if (!load.exists())
        return ;
    if (!load.open(QIODevice::ReadOnly))
    {
        error(ErrorType::Recoverable, OPENING_FILE_ERRTITLE, OPENING_FILE_ERRDES, OPENING_FILE_ERRNUM).display();
        return ;
    }
    QMessageBox::information(NULL, "Chargement effectué !",
                             QString("Le chargement de la gvi: <b>%1</b> a été correctement effectué !").arg(f_info.fileName()));
    QTextStream reader(&load);
    if (!m_eq_to_load.isEmpty())
        m_eq_to_load = eq_map();
    while (!reader.atEnd())
        if (!(Parser::parseSaveFile(reader.readLine(), m_eq_to_load)))
        {
            error(ErrorType::Recoverable, LOADING_SAVE_PARSE_ERRTITLE, LOADING_SAVE_PARSE_ERRDES, LOADING_SAVE_PARSE_ERRNUM).display();
            return ;
        }
    chantier_gb->setEnabled(true);
    liste_equipements_qsa->setEnabled(false);
    n_lancement_toedit->setText(m_eq_to_load.value("work_order_number").at(0));
    n_lancement_toedit->setEnabled(false);
    sn_moteur_toedit->setText(m_eq_to_load.value("engine_sn").at(0));
    sn_moteur_toedit->setEnabled(false);
    client_toedit->setText(m_eq_to_load.value("company_name").at(0));
    client_toedit->setEnabled(false);
    m_operatorsName = m_eq_to_load.value("operator_name").at(0);
    nom_operateurs_toedit->setText(m_operatorsName);

    return ;
}

void    MainWindow::aboutGvinspector(void)
{
    QMessageBox::about(
                        NULL,
                        "A propos",
                        QString("<b>General Visual Instpector: </b>logiciel en cours de développement.< br>< br>"
                        "<t>Il a été pensé par Majstruk Guillaume avec l'aide du bureau technique Teixeira David, puis réalisé en C++/Qt "
                        "par Majstruk Guillaume.<b>< br>< br>(version: %1)</b>").arg(qApp->applicationVersion())
                       );
}

void    MainWindow::showHelp(void)
{
    QString path = QString("file:///%1/%2").arg(QApplication::applicationDirPath()).arg("doc/help/acceuil.html");
    QDesktopServices::openUrl(QUrl(path, QUrl::TolerantMode));
}

void    MainWindow::printDocuments(void)
{
    QFile load = QFileDialog::getOpenFileName(NULL, "Fichier a imprimer", PATH_EXPORT_FINISHED, "*.gtmp, *.xlsx");
    printFile(load.fileName());
}

void    MainWindow::allowModifications(void)
{
    if (equipement_list.isEmpty())
        return ;
    for (int i = 0; i < equipement_list.size(); i++)
        if(equipement_list[i]->equipementHasStatus() && !equipement_list[i]->isEnabled())
            equipement_list[i]->setEnabled(true);
}

void    MainWindow::blockModifications(void)
{
    if (equipement_list.isEmpty())
        return ;
    for (int i = 0; i < equipement_list.size(); i++)
        if(equipement_list[i]->equipementHasStatus() && equipement_list[i]->isEnabled())
            equipement_list[i]->setEnabled(false);
}

void    MainWindow::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::question(NULL, "Quitter ?", "Etes-vous sûr de vouloir quitter ?");
    switch(ret)
    {
    case QMessageBox::Yes:
        event->accept();
        break;
    case QMessageBox::No:
        event->ignore();
        break;
    }
    return ;
}

void    MainWindow::onQuitButtonClick(void)
{
    int ret = QMessageBox::question(NULL, "Quitter ?", "Etes-vous sûr de vouloir quitter ?");
    switch(ret)
    {
    case QMessageBox::Yes:
        exit(0);
        break;
    case QMessageBox::No:
        break;
    }
    return ;
}
