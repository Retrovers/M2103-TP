#include "Clavier.h"
#include "kbhit.h"

Clavier::Clavier()
{

}

int Clavier::saisirChiffre(void){
   while(true){
       char l = _kbhit();
       if (l == '0' || l == '1' || l == '2' || l == '3' || l == '4' || l == '5' || l == '6' || l == '7' || l == '8' || l == '9'){
           return l;
       }
    }
}
