
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
#include <CException.h>
#include "Duree.h"
#include "CstCodErr.h"

using namespace nsUtil;
using namespace std;

#define DUREE nsUtil::Duree

DUREE::Duree  (const ULLong_t duree /* = ULLong_t (0) */)
    : myDuree (duree)
{
    normaliser ();

} // Duree()

DUREE::Duree  (const Duree & duree)
    : myDuree (duree.getDuree ())
{
    normaliser ();

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
         << setw (6) << myDays    << ':'
         << setfill ('0')
         << setw (2)  << myHours   << ":"
         << setw (2)  << myMinutes << ":"
         << setw (2)  << mySeconds
         << setfill (' ')
         << ']' << std::flush;

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
    return DUREE(myDuree + d.myDuree);
} // operator +()

DUREE  DUREE::operator - (const Duree & d) const
{
    return DUREE(myDuree - (myDuree < d.myDuree ? myDuree : d.myDuree));

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
    myDuree += d.getDuree();
    return *this;
}
DUREE & DUREE::operator -= (const Duree &d) noexcept{
   myDuree -= d.getDuree();
   return *this;
}
DUREE & DUREE::operator += (const unsigned long long &d) noexcept{
    myDuree += d;
    return *this;
}
DUREE & DUREE::operator -= (const unsigned long long &d) noexcept{
   myDuree -= d;
   return *this;
}
DUREE  DUREE::operator ++ (int) noexcept {
    Duree copy = *this;
    ++myDuree;
    normaliser();
    return copy;
}
Duree & DUREE::operator ++ (void) noexcept{
    ++myDuree;
    normaliser();
    return *this;
}
DUREE  DUREE::operator -- (int) noexcept {
    if(myDuree != 0){
        Duree copy = *this;
        --myDuree;
        normaliser();
        return copy;
    } else {
        throw CException("Duree pas 0", 240);
    }
}

DUREE & DUREE::operator -- (void) noexcept {
    if(myDuree != 0){
        --myDuree;
        normaliser();
         return *this;
    } else {
        throw CException("Duree pas 0", 240);
    }
}
#undef DUREE
