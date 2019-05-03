#include <iomanip>
#include <iostream>
#include "Porte.h"
#include "Chrono.h"
#include "Capteur.h"


using namespace std;
using namespace nsDigicode;

Porte::Porte(Chrono* chrono, int i) : ObjetTempo(chrono, i){

}

bool Porte::ouvrir(){
    cout << endl << "Porte deverouiller ! En attente d'ouverture de porte par l'utilisateur..." << endl;
    this->attente = 1;
    this->getChrono()->demarrer(this);

    while (true) {
       if (this->capteur.detecter() != 0){
            break;
        }
    }

    cout << "Porte Ouverte ! En attente de fermeture de porte par l'utilisateur..." << endl;
    this->fermer();

    return true;
}
bool Porte::fermer(){

    while (true) {
       if (this->capteur.detecter() != 0){
            break;
        }
    }

    cout << "Porte refermé !  Reinitialisation du systeme..." << endl;
    std::system("clear");

    this->getChrono()->arreter();
    return true;
}


