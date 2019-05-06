#ifndef DUREEEDITABLE_H
#define DUREEEDITABLE_H

#include <iostream>
#include "IEditable.hpp"
#include "Duree.h"

class DureeEditable : public nsUtil::IEditable, public nsUtil::Duree {
public:

    DureeEditable(long long unsigned d = 0);

    void display(ostream & os) const;

    DureeEditable & operator ++ (void) noexcept;
    DureeEditable   operator ++ (int i)  noexcept;
    DureeEditable & operator -- (void) noexcept;
    DureeEditable   operator -- (int i)  noexcept;

    DureeEditable & operator += (const Duree & d) noexcept;
    DureeEditable & operator -= (const Duree & d) noexcept;
    DureeEditable & operator -= (unsigned long long Duree) noexcept;
    DureeEditable & operator += (unsigned long long Duree) noexcept;


    ~DureeEditable();
};


#endif // DUREEEDITABLE_H
