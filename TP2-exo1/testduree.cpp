/*
#include <iostream>
#include <iomanip>   // setw()
#include <vector>

#include "Duree.h"

using namespace std;
using namespace nsUtil;

namespace
{
    void testDuree (void)
    {
        vector <Duree> vDurees;

        ULLong_t oneDuree;
        for (cin >> oneDuree; ! cin.eof (); cin >> oneDuree)
        {
            vDurees.push_back (oneDuree);
        }
        for (const Duree & duree : vDurees)
        {
            duree.display ();
            cout << endl;
        }
        Duree d1 (0);
        d1.incr (1);
        cout << "Nbre sec. " << setw (6) << d1.getDuree ()
             << ", soit : ";
        d1.display ();
        cout << '\n';

        d1.decr (1);
        cout << "Nbre sec. " << setw (6) << d1.getDuree ()
             << ", soit : ";
        d1.display ();
        cout << '\n';

        d1.incr (3662);
        cout << "Nbre sec. " << setw (6) << d1.getDuree ()
             << ", soit : ";
        d1.display ();
        cout << '\n';

        d1.decr (10000);
        cout << "Nbre sec. " << setw (6) << d1.getDuree ()
         << ", soit : ";
        d1.display ();
        cout << '\n';

    } // testDuree()

    void testOperator(void){
        Duree dur1(60);
        Duree dur2(60);
        Duree final = dur1 + dur2;
    }

} // namespace

int main (void)
{
    //testDuree ();
    testOperator();
    return 0;

} // main()
*/
