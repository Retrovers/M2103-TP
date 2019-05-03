#ifndef _OBJETTEMPO
#define _OBJETTEMPO

#include "Chrono.h"

namespace nsDigicode {

    class ObjetTempo {
    private :
        int delai;
        Chrono* chrono;
    protected:
        int attente;
    public:
        ObjetTempo(Chrono* chrono,int tempo);
        Chrono* getChrono();
        void finTempo();
        int getDelai();
    };
	
} /* ns_Digicode */

#endif /* _OBJETTEMPO */
