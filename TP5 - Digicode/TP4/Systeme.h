#ifndef SYSTEME_H
#define SYSTEME_H

#include "InterfaceDeSaisie.h"
#include "Porte.h"
#include "Alarme.h"
#include "BD.h"
#include "Archivage.h"
#include "Chrono.h"

class Systeme {
private :
    nsDigicode::InterfaceDeSaisie Interface;
    Porte porte;
    Alarme alarme;
    nsDigicode::BD bd;
    nsDigicode::Archivage archivage;
    nsDigicode::Chrono chrono;

public:
    Systeme(int delaiClavier, int delaiPorte, int nbChiffresClavier);
};

#endif // SYSTEME_H
