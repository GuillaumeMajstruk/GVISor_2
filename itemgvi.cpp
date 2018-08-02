#include "itemgvi.h"

ItemGvi::ItemGvi(QWidget *parent) :
    QWidget(parent)
{
    QFont Font = font();
    Font.setPointSize(12);
    setFont(Font);
    try
    {
        setBackgroundColor(this, ITEM_COLOR_BROWN);
    }
    catch(error& err)
    {
        err.display();
        exit(err.getErrorNum().toInt());
    }
    setEquipementStatus(equipementStatus::NO_STATUS);
    QHBoxLayout *mainLayout = new QHBoxLayout();

    QHBoxLayout *equipement_layout = new QHBoxLayout();
    equipement_gb = new QGroupBox(this);
    equipement_gb->setTitle("Equipement");
    equipement_name_lbl = new QLabel(equipement_gb);
    equipement_name_lbl->setObjectName("equipement_name_LBL");
    equipement_name_lbl->setText("EQUIPEMENT_NAME");
    equipement_layout->addStretch(1);
    equipement_layout->addWidget(equipement_name_lbl);
    equipement_layout->addStretch(1);
    equipement_gb->setLayout(equipement_layout);

    separator1 = new QFrame(this);
    separator1->setFrameShape(QFrame::VLine);
    separator1->setFrameShadow(QFrame::Sunken);
    separator2 = new QFrame(this);
    separator2->setFrameShape(QFrame::VLine);
    separator2->setFrameShadow(QFrame::Sunken);

    QHBoxLayout *statusEquipementLayout = new QHBoxLayout();
    status_equipement_gb = new QGroupBox(this);
    status_equipement_gb->setTitle("Status de l'équipement");
    equipement_non_valide_qcb = new QCheckBox(status_equipement_gb);
    equipement_non_valide_qcb->setText("NON VALIDE");
    equipement_non_valide_qcb->setObjectName("NON VALIDE");
    equipement_valide_qcb = new QCheckBox(status_equipement_gb);
    equipement_valide_qcb->setText("VALIDE");
    equipement_valide_qcb->setObjectName("VALIDE");
    equipement_missing = new QCheckBox(status_equipement_gb);
    equipement_missing->setText("MISSING");
    equipement_missing->setObjectName("MISSING");
    equipement_collect = new QCheckBox("COLLECT");
    equipement_collect->setText("COLLECT");
    equipement_collect->setObjectName("COLLECT");
    statusEquipementLayout->addWidget(equipement_valide_qcb);
    statusEquipementLayout->addWidget(equipement_non_valide_qcb);
    statusEquipementLayout->addWidget(equipement_missing);
    statusEquipementLayout->addWidget(equipement_collect);
    status_equipement_gb->setLayout(statusEquipementLayout);

    QHBoxLayout *defauts_layout = new QHBoxLayout();
    defauts_gb = new QGroupBox(this);
    defauts_gb->setTitle("Renseignement(s) du(/des) défaut(s)");
    description_defaut_le = new QLineEdit(defauts_gb);
    description_defaut_le->setObjectName("description_defaut_LE");
    description_defaut_le->setText("Description optionnelle.");
    list_defauts_qcb = new QComboBox(defauts_gb);
    list_defauts_qcb->setObjectName("list_defaut_QCB");
    list_defauts_qcb->addItem("");
    list_defauts_qcb->addItem("Défaut de continuité");
    list_defauts_qcb->addItem("Défaut d'isolement");
    list_defauts_qcb->addItem("Gaine HS");
    list_defauts_qcb->addItem("Prise HS");
    list_defauts_qcb->installEventFilter(this);
    choice_defauts_qcb = new QComboBox(defauts_gb);
    choice_defauts_qcb->setObjectName("choid_defauts_QCB");
    choice_defauts_qcb->addItem("Réparable");
    choice_defauts_qcb->addItem("Envoi en réparation");
    choice_defauts_qcb->addItem("Envoie en Bench Test");
    choice_defauts_qcb->installEventFilter(this);
    defauts_layout->addWidget(list_defauts_qcb);
    defauts_layout->addWidget(choice_defauts_qcb);
    defauts_layout->addWidget(description_defaut_le);
    defauts_layout->addStretch(1);
    defauts_gb->setLayout(defauts_layout);
    defauts_gb->setDisabled(true);

    connect(equipement_valide_qcb, &QCheckBox::clicked, this, &ItemGvi::updateRequested);
    connect(equipement_non_valide_qcb, &QCheckBox::clicked, this, &ItemGvi::updateRequested);
    connect(equipement_missing, &QCheckBox::clicked, this, &ItemGvi::updateRequested);
    connect(equipement_collect, &QCheckBox::clicked, this, &ItemGvi::updateRequested);

    connect(list_defauts_qcb, &QComboBox::currentTextChanged, this, &ItemGvi::statusChanged);
    connect(choice_defauts_qcb, &QComboBox::currentTextChanged, this, &ItemGvi::statusChanged);
    connect(description_defaut_le, &QLineEdit::textEdited, this, &ItemGvi::statusChanged);

    mainLayout->addWidget(equipement_gb);
    mainLayout->addWidget(separator1);
    mainLayout->addWidget(status_equipement_gb);
    mainLayout->addWidget(separator2);
    mainLayout->addWidget(defauts_gb);
    setLayout(mainLayout);
    show();
}

ItemGvi::~ItemGvi()
{
    equipement_gb = nullptr;
    equipement_name_lbl = nullptr;

    status_equipement_gb = nullptr;
    equipement_non_valide_qcb = nullptr;
    equipement_valide_qcb = nullptr;
    equipement_missing = nullptr;
    equipement_collect = nullptr;

    defauts_gb = nullptr;
    description_defaut_le = nullptr;
    list_defauts_qcb = nullptr;
    choice_defauts_qcb = nullptr;

    separator1 = nullptr;
    separator2 = nullptr;

    delete (equipement_gb);
    delete (equipement_name_lbl);
    delete (status_equipement_gb);
    delete (equipement_non_valide_qcb);
    delete (equipement_valide_qcb);
    delete (equipement_missing);
    delete (equipement_collect);
    delete (defauts_gb);
    delete (description_defaut_le);
    delete (list_defauts_qcb);
    delete (choice_defauts_qcb);
    delete (separator1);
    delete (separator2);
}

void    ItemGvi::setEquipementStatus(equipementStatus s)
{
#ifdef DEBUG
    qDebug() << "call SetEquipementStatus()";
#endif
    e_status = s;
    emit statusChanged();
}

QString ItemGvi::getEquipementStatusStr()
{
    switch(e_status)
    {
       case equipementStatus::NO_STATUS:
        return "NO_STATUS";
    case equipementStatus::NON_VALIDE:
        return "NON_VALIDE";
    case equipementStatus::VALIDE:
        return "VALIDE";
    case equipementStatus::MISSING:
        return "MISSING";
    case equipementStatus::COLLECT:
        return "COLLECT";
    }
    return "ERROR";
}

QString ItemGvi::getEquipementStatusDescription() const
{
    return (description_defaut_le->text());
}

void    ItemGvi::updateRequested()
{
    if (sender()->objectName() == "VALIDE")
    {
        equipementIsValid = true;
        equipementIsNotValide = false;
        equipementIsMissing = false;
        equipementIsCollected = false;
        equipement_valide_qcb->setCheckState(Qt::Checked);
        equipement_non_valide_qcb->setCheckState(Qt::Unchecked);
        equipement_missing->setCheckState(Qt::Unchecked);
        equipement_collect->setCheckState(Qt::Unchecked);
        description_defaut_le->setText("Description optionnelle.");
        defauts_gb->setEnabled(equipementIsNotValide);
        try
        {
            setBackgroundColor(this, ITEM_COLOR_GREEN);
        }
        catch(error& err)
        {
            err.display();
            exit(err.getErrorNum().toInt());
        }
        setEquipementStatus(equipementStatus::VALIDE);
    }
    else if (sender()->objectName() == "NON VALIDE")
    {
        equipementIsValid = false;
        equipementIsNotValide = true;
        equipementIsMissing = false;
        equipementIsCollected = false;
        equipement_valide_qcb->setCheckState(Qt::Unchecked);
        equipement_non_valide_qcb->setCheckState(Qt::Checked);
        equipement_missing->setCheckState(Qt::Unchecked);
        equipement_collect->setCheckState(Qt::Unchecked);
        description_defaut_le->setText("");
        defauts_gb->setEnabled(equipementIsNotValide);
        list_defauts_qcb->setEnabled(equipementIsNotValide);
        choice_defauts_qcb->setEnabled(equipementIsNotValide);
        try
        {
            setBackgroundColor(this, ITEM_COLOR_RED);
        }
        catch(error& err)
        {
            err.display();
            exit(err.getErrorNum().toInt());
        }
        setEquipementStatus(equipementStatus::NON_VALIDE);
    }
    else if (sender()->objectName() == "MISSING")
    {
        equipementIsValid = false;
        equipementIsNotValide = false;
        equipementIsMissing = true;
        equipementIsCollected = false;
        equipement_valide_qcb->setCheckState(Qt::Unchecked);
        equipement_non_valide_qcb->setCheckState(Qt::Unchecked);
        equipement_missing->setCheckState(Qt::Checked);
        equipement_collect->setCheckState(Qt::Unchecked);
        description_defaut_le->setText("");
        defauts_gb->setEnabled(equipementIsMissing);
        list_defauts_qcb->setEnabled(equipementIsNotValide);
        choice_defauts_qcb->setEnabled(equipementIsNotValide);
        try
        {
            setBackgroundColor(this, ITEM_COLOR_GREY);
        }
        catch(error& err)
        {
            err.display();
            exit(err.getErrorNum().toInt());
        }

        setEquipementStatus(equipementStatus::MISSING);
    }
    else if (sender()->objectName() == "COLLECT")
    {
        equipementIsValid = false;
        equipementIsNotValide = false;
        equipementIsMissing = false;
        equipementIsCollected = true;
        equipement_valide_qcb->setCheckState(Qt::Unchecked);
        equipement_non_valide_qcb->setCheckState(Qt::Unchecked);
        equipement_missing->setCheckState(Qt::Unchecked);
        equipement_collect->setCheckState(Qt::Checked);
        description_defaut_le->setText("");
        defauts_gb->setEnabled(equipementIsMissing);
        list_defauts_qcb->setEnabled(equipementIsNotValide);
        choice_defauts_qcb->setEnabled(equipementIsNotValide);
        try
        {
            setBackgroundColor(this, ITEM_COLOR_BLUE);
        }
        catch(error& err)
        {
            err.display();
            exit(err.getErrorNum().toInt());
        }

        setEquipementStatus(equipementStatus::COLLECT);
    }
}

bool    ItemGvi::equipementHasStatus()
{
    return (this->getEquipementStatus() != equipementStatus::NO_STATUS);
}

void    ItemGvi::loadingUpdate(const QStringList &properties)
{
    QString status = properties.at(0);
    QString def_type, def_choice, def_description;

    if (properties.size() > 4)
        throw error(ErrorType::Critical, LOADING_SAVE_PROPERTIES_ERRTITLE, LOADING_SAVE_PROPERTIES_ERRDES, LOADING_SAVE_PROPERTIES_ERRNUM);

    if (status == "VALIDE")
    {
        equipementIsValid = true;
        equipementIsNotValide = false;
        equipementIsMissing = false;
        equipementIsCollected = false;
        equipement_valide_qcb->setCheckState(Qt::Checked);
        equipement_non_valide_qcb->setCheckState(Qt::Unchecked);
        equipement_missing->setCheckState(Qt::Unchecked);
        equipement_collect->setCheckState(Qt::Unchecked);
        description_defaut_le->setText("Description optionnelle.");
        defauts_gb->setEnabled(equipementIsNotValide);
        try
        {
            setBackgroundColor(this, ITEM_COLOR_GREEN);
        }
        catch(error& err)
        {
            err.display();
            exit(err.getErrorNum().toInt());
        }
        setEquipementStatus(equipementStatus::VALIDE);
    }
    else if (status == "NON_VALIDE")
    {
        def_type = properties.at(1);
        def_choice = properties.at(2);
        def_description = properties.at(3);

        equipementIsValid = false;
        equipementIsNotValide = true;
        equipementIsMissing = false;
        equipementIsCollected = false;
        equipement_valide_qcb->setCheckState(Qt::Unchecked);
        equipement_non_valide_qcb->setCheckState(Qt::Checked);
        equipement_missing->setCheckState(Qt::Unchecked);
        equipement_collect->setCheckState(Qt::Unchecked);
        description_defaut_le->setText(def_description);
        list_defauts_qcb->setCurrentText(def_type);
        choice_defauts_qcb->setCurrentText(def_choice);
        defauts_gb->setEnabled(equipementIsNotValide);
        list_defauts_qcb->setEnabled(equipementIsNotValide);
        choice_defauts_qcb->setEnabled(equipementIsNotValide);
        try
        {
            setBackgroundColor(this, ITEM_COLOR_RED);
        }
        catch(error& err)
        {
            err.display();
            exit(err.getErrorNum().toInt());
        }
        setEquipementStatus(equipementStatus::NON_VALIDE);
    }
    else if (status == "MISSING")
    {
        def_description = properties.at(3);
        equipementIsValid = false;
        equipementIsNotValide = false;
        equipementIsMissing = true;
        equipementIsCollected = false;
        equipement_valide_qcb->setCheckState(Qt::Unchecked);
        equipement_non_valide_qcb->setCheckState(Qt::Unchecked);
        equipement_missing->setCheckState(Qt::Checked);
        equipement_collect->setCheckState(Qt::Unchecked);
        description_defaut_le->setText(def_description);
        defauts_gb->setEnabled(equipementIsMissing);
        list_defauts_qcb->setEnabled(equipementIsNotValide);
        choice_defauts_qcb->setEnabled(equipementIsNotValide);
        try
        {
            setBackgroundColor(this, ITEM_COLOR_GREY);
        }
        catch(error& err)
        {
            err.display();
            exit(err.getErrorNum().toInt());
        }

        setEquipementStatus(equipementStatus::MISSING);
    }
    else if (status == "COLLECT")
    {
        equipementIsValid = false;
        equipementIsNotValide = false;
        equipementIsMissing = false;
        equipementIsCollected = true;
        equipement_valide_qcb->setCheckState(Qt::Unchecked);
        equipement_non_valide_qcb->setCheckState(Qt::Unchecked);
        equipement_missing->setCheckState(Qt::Unchecked);
        equipement_collect->setCheckState(Qt::Checked);
        description_defaut_le->setText("");
        defauts_gb->setEnabled(equipementIsMissing);
        list_defauts_qcb->setEnabled(equipementIsNotValide);
        choice_defauts_qcb->setEnabled(equipementIsNotValide);
        try
        {
            setBackgroundColor(this, ITEM_COLOR_BLUE);
        }
        catch(error& err)
        {
            err.display();
            exit(err.getErrorNum().toInt());
        }
        setEquipementStatus(equipementStatus::COLLECT);
    }
}

bool ItemGvi::eventFilter(QObject *o, QEvent *ev)
{
    if ((o == list_defauts_qcb || o == choice_defauts_qcb) && ev->type() == QEvent::Wheel)
            return true;
    return QObject::eventFilter(o, ev);
}
