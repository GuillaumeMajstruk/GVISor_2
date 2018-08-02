#include "chantier.h"

Chantier::Chantier(const QString &input_engineSN)
{
    moteur_actuel = new Engine(input_engineSN);
}

Chantier::~Chantier()
{

}

void    Chantier::setNumeroLancement(const QString &num)
{
    numero_lancement = num;
}

void    Chantier::setCompanyName(const QString &name)
{
    company_name = name;
}
