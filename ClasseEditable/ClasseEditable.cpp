/**
 *
 * \file   : ClasseEditable.cpp
 *
 * \author :
 *
 * \date   :
 *
**/

#include <iostream>
#include <exception>

#include "CstCodErr.h"
#include "CException.h"
#include "IEditable.hpp"

using namespace std;
using namespace nsUtil;


class CA : public IEditable {
public :
    void display(ostream & os) const {
        os << "CA";
    }
};

class CB : public IEditable {
public :
    void display(ostream & os) const {
        os << "CB";
    }
};

namespace
{
    void contenu (const IEditable & ed) {
        cout << ed << endl;
    }

    void testClasseEditable(){
        CA a;
        CB b;
        contenu(a);
        contenu(b);
    }
} // namespace

int main (int argc, char * argv [])
{
    try
    {
        testClasseEditable();

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
namespace  {

}
