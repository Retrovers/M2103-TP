#ifndef PORTE_H
#define PORTE_H

#include "Chrono.h"
#include "ObjetTempo.h"
#include "Capteur.h"

class Porte : nsDigicode::ObjetTempo {
private:
    Capteur capteur;
    bool fermer();
public:
    Porte(nsDigicode::Chrono* chrono, int i);
    bool ouvrir();
};

#endif // PORTE_H
