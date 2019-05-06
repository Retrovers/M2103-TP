
/**
 *
 * \file    Duree.cpp
 *
 * \authors M. Laporte
 *
 * \date    02/04/2018
 *
 * \version V2.0
 *
 * \brief  définitions de la classe Duree
 *
 **/
#include <iostream>
#include <iomanip>   // setw()
#include <math.h>
#include "Duree.h"

using namespace nsUtil;
using namespace std;

#define DUREE nsUtil::Duree

DUREE::Duree  (const ULLong_t duree /* = ULLong_t (0) */)
    : myDuree (duree)
{
    normaliser ();
    cout << "duree construite : ";
    display (cout);
    cout << endl;

} // Duree()

DUREE::Duree  (const Duree & duree)
    : myDuree (duree.getDuree ())
{
    normaliser ();
    cout << "duree construite par recopie : ";
    display (cout);
    cout << endl;

} // Duree()

DUREE::~Duree  (void)
{
    cout << "duree détruite : ";
    display (cout);
    cout << endl;

} // Duree()

void DUREE::normaliser (void)
{
    myDays    =  myDuree / 86400;
    myHours   = (myDuree % 86400) / 3600;
    myMinutes  = (myDuree % 3600) / 60;
    mySeconds =  myDuree % 60;

} // normaliser()

ULLong_t DUREE::getDuree (void) const { return myDuree; }

void DUREE::display (ostream & os) const {
    os << '['
         << setw (10) << myDays    << ':'
         << setfill ('0')
         << setw (2)  << myHours   << " heure(s)"
         << setw (2)  << myMinutes << " minute(s)"
         << setw (2)  << mySeconds << " seconde(s)"
         << setfill (' ')
         << ']';

} // display()
/*
void DUREE::incr (const ULLong_t delta)
{
    myDuree += delta;
    normaliser ();

} // incr()

void DUREE::decr (const ULLong_t delta)
{
    myDuree -= (delta > myDuree) ? myDuree : delta;

} // decr()
*/
DUREE DUREE::operator + (const Duree & d) const
{
    Duree l (myDuree + d.getDuree());
    return l;

} // operator +()

DUREE DUREE::operator - (const Duree & d) const
{
    Duree l (myDuree - (myDuree < d.myDuree ? myDuree : d.myDuree));
    return l;

} // operator -()

bool DUREE::operator > (const Duree & d) const
{
    return myDuree > d.myDuree;

} // operator >()

bool DUREE::operator < (const Duree & d) const
{
    return myDuree < d.myDuree;

} // operator <()

bool DUREE::operator != (const Duree & d) const
{
    return myDuree != d.myDuree;

} // operator !=()

bool DUREE::operator == (const Duree & d) const
{
    return myDuree == d.myDuree;

} // operator ==()

void DUREE::setDuree (ULLong_t d){
        myDuree = d;
        normaliser();
}

DUREE & DUREE::operator += (const Duree &d) noexcept{
    Duree l (myDuree += d.getDuree());
    return l;
}
DUREE & DUREE::operator -= (const Duree &d) noexcept{
   Duree l (myDuree -= d.getDuree());
   return l;
}
DUREE DUREE::operator ++ (int i) noexcept {
    Duree l (myDuree + i);
    return l;
}
DUREE & DUREE::operator ++ (void) noexcept {
    Duree l (myDuree -= (1 > myDuree) ? myDuree : 1);
    return l;
}
DUREE DUREE::operator -- (int i) noexcept {
    Duree l(myDuree - i);
    normaliser ();
    return l;
}
DUREE & DUREE::operator -- (void) noexcept {
    Duree l (myDuree += (1 > myDuree) ? myDuree : 1);
    return l;
}

#undef DUREE
