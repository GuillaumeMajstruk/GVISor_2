#ifndef CHANTIER_H
#define CHANTIER_H

#include <QString>
#include "Ressources/engine.h"

class Chantier
{
    friend class Engine;
public:
    Chantier(const QString& input_engineSN);
    ~Chantier();

    void                setNumeroLancement(const QString &num);
    QString             getNumeroLancement() const { return numero_lancement; }
    Engine              *getEngine() const { return moteur_actuel; }
    void                setCompanyName(const QString &name);
    QString             getCompanyName() const { return company_name; }

private:
    QString     numero_lancement;
    QString     company_name;
    Engine      *moteur_actuel;
};

#endif // CHANTIER_H
