#ifndef _INTERFACE
#define _INTERFACE
#include <string>
#include "ObjetTempo.h"
#include "Voyant.h"
#include "Clavier.h"

namespace nsDigicode {

    class InterfaceDeSaisie : ObjetTempo {
    private:
        int nbChiffresAttendus;
        void statut(std::string="\n");
        Voyant leVoyantVert;
        Voyant leVoyantRouge;
        Clavier clavier;
    public :
        InterfaceDeSaisie(Chrono* chrono, int delai, int nbchiffres);
        int saisirCode();
	}; // InterfaceDeSaisie
	
} /* ns_Digicode */

#endif /* _INTERFACE */
