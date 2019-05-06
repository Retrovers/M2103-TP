#include <iostream>

#include "CException.h"


using namespace std;
using namespace nsUtil;


namespace  {

    class CExcFille : public CException {
        public:
        CExcFille(const string & libelle,
                  const unsigned codErr) : CException(libelle, codErr) {

        }

        void display (ostream & os) const {
            os << "Il y a une erreur mon bro";
        }
    };


    void testCException(){
        throw CExcFille("LOL", 12);
    }

}


int main ()
{
    try
    {
        testCException();
    }
    catch (const CException & e)
    {
        cerr << e << '\n';
        return e.getCodErr ();
    }
    catch (const exception & e)
    {
        cerr << "Exception standard : " << e.what() << '\n';
        return KExcStd;
    }
    catch (...)
    {
        cerr << "Exception inconnue\n";
        return KExcInconnue;
    }
    return KNoExc;

} // main()
