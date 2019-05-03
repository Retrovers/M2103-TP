#include <iostream>
#include "Systeme.h"

using namespace std;

Systeme::Systeme(int delaiClavier, int delaiPorte, int nbChiffresClavier) : Interface(&chrono, delaiClavier, nbChiffresClavier), porte(&chrono, delaiPorte) {
    int c;
    while(true){
        archivage.archiver(c = Interface.saisirCode());
        if (bd.verifier(c)) {
            cout << "Code bon ! " << endl;
            if (!porte.ouvrir()){
                alarme.declencher();
            }
        }
    }
}
