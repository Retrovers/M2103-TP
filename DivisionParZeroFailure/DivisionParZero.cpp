/**
 *
 * \file   : SqueletteMain.cpp
 *
 * \author :
 *
 * \date   :
 *
**/

#include <iostream>
#include <exception>
#include <vector>

#include "CstCodErr.h"
#include "CException.h"

using namespace std;
using namespace nsUtil;

namespace
{
    int divisionEntiere(unsigned i1, unsigned i2) throw (CException) {
        int i;
        if (i2 == 0){
            throw CException("CstExcDivZero");
        } else {
            i = i1 / i2;
        }

        return i;
    }
    void testDivisionParZero (void)
    {
        vector <unsigned> denom = {9,8,0,7,6,5,4,3,2,1};
        vector <unsigned> nume =  {1,2,3,4,5,6,7,8,9,10};

        for (unsigned i = 0; i < denom.size(); ++i){
            cout << nume[i] << " / " << denom[i] << " = " << divisionEntiere(nume[i], denom[i]) << endl;
        }


    } // testDivisionParZero ()

} // namespace

int main (void)
{
    try
    {
        testDivisionParZero ();

        return KNoExc;
    }
    catch (const CException & e)
    {
        cerr << "Erreur        : " << e.getLibelle () << '\n'
             << "Code d'erreur = " << e.getCodErr ()  << '\n';
        return e.getCodErr();
    }
    catch (const exception & e)
    {
        cerr << "Exception standard : " << e.what () << '\n';
        return KExcStd;
    }
    catch (...)
    {
        cerr << "Exception inconnue\n";
        return KExcInconnue;
    }

} // main()
