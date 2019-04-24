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
#include "Rationnel.h"

using namespace std;
using namespace nsUtil;

namespace {


    void TestCRationnel (void) {
        nsMath::Rationnel r(8 , 0);
        r.display();
    }

} // namespace

int main (void)
{
    try
    {
        TestCRationnel ();

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
