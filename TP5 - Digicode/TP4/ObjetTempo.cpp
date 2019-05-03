#include "ObjetTempo.h"
#include "Chrono.h"

#define OBJETTEMPO nsDigicode::ObjetTempo

using namespace nsDigicode;

OBJETTEMPO::ObjetTempo(Chrono* chrono, int tempo){
    this->attente = tempo;
    this->chrono = chrono;
}

void OBJETTEMPO::finTempo(){
    this->attente = 0;
}

Chrono* OBJETTEMPO::getChrono(){
    return this->chrono;
}

int OBJETTEMPO::getDelai(){
    return this->delai;
}

#undef OBJETTEMPO
