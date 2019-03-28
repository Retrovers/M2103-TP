/**
 *
 * \file     TestCRationnel.cpp
 *
 * \authors  M. Laporte, D. Mathieu
 *
 * \date     04/11/2007
 *
 * \version  V1.0
 *
 * \brief    Test de la classe Rationnel (V1)
 *
 **/

#include <iostream>
#include <utility>         // operateurs < et == generiques

using namespace std;
using namespace rel_ops;

#include "Rationnel.h"

using namespace nsMath;

namespace 
{
    void testRationnel (void)
    {
        // Test des constructeurs par defaut et par recopie
        // Test de display()

        Rationnel r1;
        cout << "r1 = ";
        r1.display ();
        cout << '\n';

        Rationnel r2 (12, 5);
        cout << "r2 = ";
        r2.display ();
        cout << '\n';

        Rationnel r3 ( 3, 5);
        cout << "r3 = ";
        r3.display ();
        cout << '\n';

        Rationnel r4 (12, 8);
        cout << "r4 = ";
        r4.display ();
        cout << '\n';

        Rationnel r5 (12, -8);
        cout << "r5 = ";
        r5.display ();
        cout << '\n';

        Rationnel r6 (r2);

        cout << "r6 = ";
        r6.display ();
        cout << '\n';

        // Tests de < et !=

        r2.display ();
        cout << (r2 < r3 ? " <  " : " >= ");
        r3.display ();
        cout << '\n';

        r2.display ();
        cout << (r2 != r3 ? " !=  " : " == ");
        r3.display ();
        cout << '\n';

        r2.display ();
        cout << (r2 > r2 ? " >  " : " <= ");
        r2.display ();
        cout << '\n';

        r2.display ();
        cout << (r2 != r2 ? " !=  " : " == ");
        r2.display ();
        cout << '\n';

        // Test de +, -, *, /

        cout << "r2 + r3 + r4 = ";
        (r2 + r3 + r4).display ();
        cout << '\n';

        r4.display ();
        cout << " - ";
        r2.display ();
        cout << " = ";
        (r4 - r2).display ();
        cout << '\n';

        r2.display ();
        cout << " / ";
        r4.display ();
        cout << " = ";
        (r2 / r4).display ();
        cout << '\n';

        r2.display ();
        cout << " * ";
        r4.display ();
        cout << " = ";
        (r2 * r4).display ();
        cout << '\n';

    } // testRationnel()

} // namespace anonyme


int main (void)
{
    testRationnel ();

    return 0;

} // main()
