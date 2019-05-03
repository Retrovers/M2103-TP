#include <iomanip>
#include <iostream>
#include "Capteur.h"
#include "kbhit.h"

using namespace std;

Capteur::Capteur()
{

}

int Capteur::detecter(void){
    char l;
    l = _kbhit();
    if (l == '1'){
        return 1;
    } else {
        return 0;
    }

}
