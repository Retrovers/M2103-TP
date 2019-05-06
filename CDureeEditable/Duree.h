/**
 *
 * \file    Duree.h
 *
 * \authors M. Laporte
 *
 * \date    02/04/2018
 *
 * \version V2.0
 *
 * \brief  déclarations de la classe Duree (avec constructeurs et
 *         destructeur)
 *
 **/

 #ifndef __DUREE_H__
 #define __DUREE_H__

#include <iostream>

namespace nsUtil
{
    typedef unsigned long long ULLong_t;

    class Duree
    {
    protected:
        ULLong_t       myDuree;
        short unsigned mySeconds;
        short unsigned myMinutes;
        short unsigned myHours;
        ULLong_t       myDays;

        void normaliser (void);

      protected:
        void display (std::ostream & os) const;

      public :
         explicit Duree  (const ULLong_t duree = ULLong_t (0));
         Duree  (const Duree & duree);
         virtual ~Duree (void) {}

        ULLong_t getDuree (void) const;
        void setDuree (ULLong_t d);

        Duree & operator ++ (void) noexcept; // préincrémentation de la classe Duree
        Duree & operator -- (void) noexcept; // préincrémentation de la classe Duree
        Duree   operator -- (int)  noexcept; // postincrémentation de la classe Duree
        Duree   operator ++ (int)  noexcept; // postincrémentation de la classe Duree

        Duree  operator +  (const Duree & d) const;
        Duree  operator -  (const Duree & d) const;
        Duree  operator +  (const ULLong_t & d) const;
        Duree  operator -  (const ULLong_t & d) const;

        Duree & operator += (const Duree & d) noexcept;
        Duree & operator -= (const Duree & d) noexcept;

        Duree & operator += (const ULLong_t & d) noexcept;
        Duree & operator -= (const ULLong_t & d) noexcept;

        bool  operator >  (const Duree & d) const;
        bool  operator <  (const Duree & d) const;
        bool  operator != (const Duree & d) const;
        bool  operator == (const Duree & d) const;

    }; // Duree

} // nsUtil

#endif /* __DUREE_H__ */
