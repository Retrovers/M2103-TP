#include <iomanip>
#include "Voyant.h"

using namespace std;

Voyant::Voyant(Couleur couleur, Etat etat) {
    this->etat = etat;
    this->couleur = couleur;
}

string Voyant::getStatut(){
    if (this->etat == Etat::allume){
        return "ON";
    } else {
        return "OFF";
    }
}
