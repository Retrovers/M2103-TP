/**
 *
 * \file     TestDureeRelops.cpp
 *
 * \authors  M. Laporte, D. Mathieu
 *
 * \date     01/02/2008
 *
 * \version  V1.0
 *
 * \brief    Test des operateurs de comparaison
 *
 **/
#include <iostream>
#include <iomanip>         // boolalpha
#include <utility>

using namespace std;
using namespace rel_ops;

#include "Duree.h"

using namespace nsUtil;

#define classdef typedef

namespace 
{
    void testDuree (void)
    {
        Duree d1 (3661);
        Duree d2 (2661);
        Duree d3 (3661);
        cout << boolalpha;
        /*         */
        d1.display ();
        cout << " <  ";
        d2.display ();
        cout << " : " << (d1 <  d2) << '\n';

        d2.display ();
        cout << " <  ";
        d1.display ();
        cout << " : " << (d2 <  d1) << "\n\n";
        /*         */

        /*         */
        d1.display ();
        cout << " >  ";
        d2.display ();
        cout << " : " << (d1 >  d2) << '\n';

        d2.display ();
        cout << " >  ";
        d1.display ();
        cout << " : " << (d2 >  d1) << "\n\n";
        /*         */

        /*         */
        d1.display ();
        cout << " <= ";
        d2.display ();
        cout << " : " << (d1 <= d2) << '\n';

        d2.display ();
        cout << " <= ";
        d1.display ();
        cout << " : " << (d2 <= d1) << "\n\n";
        /*         */

        /*         */
        d1.display ();
        cout << " >= ";
        d2.display ();
        cout << " : " << (d1 >= d2) << '\n';

        d2.display ();
        cout << " >= ";
        d1.display ();
        cout << " : " << (d2 >= d1) << "\n\n";
        /*         */

        /*         */
        d1.display ();
        cout << " == ";
        d2.display ();
        cout << " : " << (d1 == d2) << '\n';

        d2.display ();
        cout << " == ";
        d1.display ();
        cout << " : " << (d2 == d1) << "\n\n";
        /*         */

        /*         */
        d1.display ();
        cout << " == ";
        d3.display ();
        cout << " : " << (d1 == d3) << '\n';
        /*         */

        /*         */
        d1.display ();
        cout << " != ";
        d2.display ();
        cout << " : " << (d1 != d2) << '\n';
        /*         */

        /*         */
        d1.display ();
        cout << " != ";
        d3.display ();
        cout << " : " << (d1 != d3) << '\n';
        /*         */

        cout << noboolalpha;

    } // testDuree()

} // namespace anonyme

int main (void)
{
    testDuree ();

    return 0;

} // main()
