/**
 *
 * @file    TestFunctorAbstrait.cpp
 *
 * @authors M. Laporte, D. Mathieu
 *
 * @date    27/04/2010
 *
 * @version V1.0
 *
 * @brief   functor abstrait
 *
 **/
#include <string>
#include <iostream>
#include <cctype>  // ispunct(), islower(), isalpha()
                   // tolower(), toupper()
#include <cassert>

using namespace std;

namespace
{
    class ITraitCar {
        public:
            virtual int operator() (int i) const = 0;
            virtual ~ITraitCar(){}
    };

    class ToUpper : public ITraitCar {
        public:
            virtual int operator() (int i) const {
                return toupper(i);
            }

            virtual ~ToUpper(){}
    };

    class IgnPunct : public ITraitCar {
        public:
            virtual int operator() (int i) const {
                if ((i >= 33 && i <= 47) ||(i >= 58 && i <= 63)){
                    return 32;
                } else {
                    return i;
                }
            }

            virtual ~IgnPunct(){}

    };

    class ToLower : public ITraitCar
    {
      public :
        virtual ~ToLower (void) {}
        virtual int operator () (int i) const
        {
            return tolower (i);

        } // operateur()

    }; // CToLower

    string & moulinette (string & str, const ITraitCar & transf)
    {
        for (string::size_type i (str.size ()); i--; )
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

        // ToDo

        assert (minusc    == moulinette (ligne, ToLower()));
        assert (majusc    == moulinette (ligne, ToUpper()));
        assert (sansPunct == moulinette (ligne, IgnPunct()));

        cout << "OK\n";

    } // testFunctor ()

} // namespace anonyme

int main (void)
{
    /*      */    testFunctor ();     /*           */

    return 0;

} // main()
