/**
 *
 * @file    TestFunctorAbstraitCorr.cpp
 *
 * @authors M. Laporte
 *
 * @date    07/05/2018
 *
 * @version V1.0
 *
 * @brief   functor abstrait
 *
 **/
#include <string>
#include <iostream>
#include <cctype>    // ispunct(), islower(), isalpha()
                     // tolower(), toupper()
#include <cassert>

using namespace std;

namespace
{
    class ITraitCar
    {

      protected:
        mutable unsigned myCpt = 0;
      public :
        virtual ~ITraitCar (void) {}
        virtual int operator () (int caract) const = 0;

    }; // ITraitCar

    class ToLower  : public ITraitCar
    {
      public :
        virtual ~ToLower (void) {}
        virtual int operator () (int caract) const noexcept
        {
            ++myCpt;
            return tolower (caract);

        } // operateur()

    }; // ToLower

    class ToUpper : public ITraitCar
    {
      public :
        virtual ~ToUpper (void) {}
        virtual int operator () (int caract) const noexcept
        {
            myCpt++;
            return toupper (caract);

        } // operateur()

    }; // ToUpper

    class IgnPunct : public ITraitCar
    {
      public :
        virtual ~IgnPunct (void) {}
        virtual int operator () (int caract) const noexcept
        {
            if (ispunct(caract)) {
                myCpt++;
                return ' ';
            } else {
                return caract;
            }

        } // operateur()

    }; // IgnPunct

    string & moulinette (string & str, const ITraitCar & transf)
    {
        for (string::size_type i (str.size()); i--; )
            str [i] = transf (str [i]);

        return str;

    } // moulinette()

    void testFunctor (void)
    {
        cout << "Functor abstrait : ";

        string ligne     ("azert:;,.?GFDSQ");
        string minusc    ("azert:;,.?gfdsq");
        string majusc    ("AZERT:;,.?GFDSQ");
        string sansPunct ("AZERT     GFDSQ");

        assert (minusc    == moulinette (ligne, ToLower ()));
        assert (majusc    == moulinette (ligne, ToUpper ()));
        assert (sansPunct == moulinette (ligne, IgnPunct()));

        cout << "OK\n";

    } // testFunctor()

} // namespace

int main (void)
{
    /*      */    testFunctor ();     /*           */

    return 0;

} // main()

