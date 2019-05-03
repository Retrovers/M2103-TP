#include <iostream>
#include <iomanip>
#include "InterfaceDeSaisie.h"                  
#include "Chrono.h"
#include "Voyant.h"
#include "kbhit.h"

using namespace std;
using namespace nsDigicode;

InterfaceDeSaisie::InterfaceDeSaisie(Chrono* chrono, int delai, int nbchiffres) : ObjetTempo (chrono, delai), leVoyantVert(vert, eteint), leVoyantRouge(rouge, allume), clavier() {
    this->nbChiffresAttendus = nbchiffres;
}

int InterfaceDeSaisie::saisirCode(){
    this->statut();
    cout << "Entrez vos 4 chiffres : " << endl;
    string code;

    for (unsigned i = 0; i < 4; ++i){
    int l = clavier.saisirChiffre();
    code += l;
    }
    return std::stoi(code);
}

void InterfaceDeSaisie::statut (string s)
{
    cout << "VERT"  << setw (4) << leVoyantVert.getStatut ()
         << setw (7) << "ROUGE" << setw (4) << leVoyantRouge.getStatut ()
	     << setw (24) << s << flush;
} //statut


