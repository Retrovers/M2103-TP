#include <iostream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <duree.h>

typedef NsUtil::Duree DUREE;

void DUREE::normaliser(void){
    mySeconds = myDuree;
    myMinutes = mySeconds / 60;
    mySeconds = mySeconds % 60;
    myHours = myMinutes / 60;
    myMinutes = myMinutes % 60;
    myDay = myHours / 24;
    myHours = myHours % 24;
}
DUREE::Duree(const unsigned long long& Duree){
    myDuree = Duree;
    normaliser();
}
int DUREE::getDuree(void){
    return myDuree;
}
void DUREE::display(void){
    std::cout << std::setw(3)
              << myDay << " jour(s) "
              << myHours << " heure(s) "
              << myMinutes << " minutes(s) "
              << mySeconds << " seconde(s)";
}
void DUREE::incr(const unsigned long long& delta){
    myDuree += delta;
    normaliser();
}
void DUREE::decr(const unsigned long long& delta){
    if (myDuree < delta) {
        myDuree = 0;
        normaliser();
    } else {
        myDuree -= delta;
        normaliser();
    }
}
