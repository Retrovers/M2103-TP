#include <iostream>
#include "Rationnel.h"

using namespace nsMath;
using namespace std;

#define RATIONNEL nsMath::Rationnel

RATIONNEL::Rationnel(const int& Num, const int& Denom){
    myNum = Num;
    myDenom = Denom;
    simplifier();
}

RATIONNEL::Rationnel(const Rationnel& copy){
    myNum = copy.myNum;
    myDenom = copy.myDenom;
    //simplifier();
}

void RATIONNEL::simplifier(){
    if (myNum > 0 && myDenom > 0){
        int div = PGCD(myNum, myDenom);
        myNum /= div;
        myDenom /= div;
    } else if (myNum < 0 && myDenom < 0){
        myNum = abs(myNum);
        myDenom = abs(myDenom);
        simplifier();
    } else if (myDenom < 0){
        myDenom = abs(myDenom);
        myNum = myNum * -1;
    }
}

void RATIONNEL::display(){
    cout << myNum << "/" << myDenom;
}

Rationnel RATIONNEL::operator+(const Rationnel& rat){
    if (myDenom != rat.myDenom){
        return Rationnel( (rat.myNum * myDenom) + (myNum * rat.myDenom) , rat.myDenom * myDenom);
    } else {
        return Rationnel(myNum + rat.myNum, myDenom);
    }
}
Rationnel RATIONNEL::operator-(const Rationnel& rat){
    if (myDenom != rat.myDenom){
        return Rationnel( (myNum * rat.myDenom) - (rat.myNum * myDenom) , rat.myDenom * myDenom);
    } else {
        return Rationnel(myNum - rat.myNum, myDenom);
    }
}
Rationnel RATIONNEL::operator*(const Rationnel& rat){
    return Rationnel(myNum * rat.myNum, myDenom * rat.myDenom);
}
Rationnel RATIONNEL::operator/(const Rationnel& rat){
    return Rationnel(myNum * rat.myDenom, myDenom *rat.myNum);
}

bool RATIONNEL::operator<(const Rationnel& rat){
    if ((myNum/myDenom) < (rat.myNum/rat.myDenom)){
        return true;
    } else {
        return false;
    }
}
bool RATIONNEL::operator==(const Rationnel& rat){
    if ((myNum/myDenom) == (rat.myNum/rat.myDenom)){
        return true;
    } else {
        return false;
    }
}

namespace  {
    int PGCD(int a, int b){
        while (a != b){
            if (a < b){
                b = b - a;
            } else {
                a = a - b;
            }
        }
        return b;
    }
}

#undef DUREE
