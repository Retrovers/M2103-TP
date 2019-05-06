#include "DureeEditable.h"

DureeEditable DureeEditable(long long unsigned d = 0) : IEditable(), Duree(d){
    };

    void display(ostream & os) const {
        os << "C'est display";
    }

    DureeEditable & DureeEditable::operator ++ (void) noexcept {
        Duree::operator++();
        return *this;
    } // préincrémentation de la classe Duree
    DureeEditable  DureeEditable::operator ++ (int i)  noexcept {
        Duree::operator++(i);
        return *this;
    } // postincrémentation de la classe Duree
    DureeEditable & DureeEditable::operator -- (void) noexcept {
        Duree::operator--();
        return *this;
    } // préincrémentation de la classe Duree
    DureeEditable   DureeEditable::operator -- (int i)  noexcept {
        Duree::operator--(i);
        return *this;
    } // postincrémentation de la classe Duree

    DureeEditable & DureeEditable::operator += (const Duree & d) noexcept {
        Duree::operator+=(d);
        return *this;
    }
    DureeEditable & DureeEditable::operator -= (const Duree & d) noexcept {
        Duree::operator-=(d);
        return *this;
    }
    DureeEditable & DureeEditable::operator -= (unsigned long long Duree) noexcept {
        Duree::operator-=(Duree);
        return *this;
    }
    DureeEditable & DureeEditable::operator += (unsigned long long Duree) noexcept {
        Duree::operator+=(Duree);
        return *this;
    }
};
