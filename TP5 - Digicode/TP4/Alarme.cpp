#include <iostream>
#include <unistd.h>
#include "Alarme.h"

using namespace std;

Alarme::Alarme()
{

}

void Alarme::declencher(void){
    while (true){
        cout << "Alarme : la porte n'a pas été refermée" << endl;
        sleep(1);
    }
}
