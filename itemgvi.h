#ifndef ITEMGVI_H
#define ITEMGVI_H

#include "../global_functions.h"

enum class equipementStatus
{
    NO_STATUS,
    VALIDE,
    NON_VALIDE,
    MISSING,
    COLLECT
};

class Q_DECL_EXPORT ItemGvi : public QWidget
{
    Q_OBJECT
public:
    QGroupBox           *equipement_gb = nullptr;
    QLabel              *equipement_name_lbl = nullptr;

    QGroupBox           *status_equipement_gb = nullptr;
    QCheckBox           *equipement_non_valide_qcb = nullptr;
    QCheckBox           *equipement_valide_qcb = nullptr;
    QCheckBox           *equipement_missing = nullptr;
    QCheckBox           *equipement_collect = nullptr;

    QGroupBox           *defauts_gb = nullptr;
    QLineEdit           *description_defaut_le = nullptr;
    QComboBox           *list_defauts_qcb = nullptr;
    QComboBox           *choice_defauts_qcb = nullptr;

    QFrame              *separator1 = nullptr;
    QFrame              *separator2 = nullptr;

    bool                equipementIsValid = false;
    bool                equipementIsNotValide = false;
    bool                equipementIsMissing = false;
    bool                equipementIsCollected = false;
public:
    ItemGvi(QWidget *parent = 0);
    ~ItemGvi(void);

    void                setEquipementStatus(equipementStatus s);
    equipementStatus    getEquipementStatus() {return e_status; }
    QString             getEquipementStatusStr();
    QString             getEquipementStatusDescription() const;
    bool                equipementHasStatus();
    void                loadingUpdate(const QStringList &properties);
    bool                eventFilter(QObject *o, QEvent *ev);
private:
    equipementStatus    e_status;
public slots:
    void                updateRequested();
signals:
    void                statusChanged();
};

#endif
