#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

namespace  {
    class Pers /* : public IEditable */
        {
            string   myNom;
            unsigned myAge;

          public :
            Pers (const string & nom, unsigned age)
                  : myNom (nom), myAge (age) {}

            const string & getNom (void) const noexcept { return myNom; }
            unsigned       getAge (void) const noexcept { return myAge; }

          private :
            ostream & display (ostream & os)  const
            {
                return os << getAge () << " - " << getNom ();

            } // display()

          public :    // ajouté pour faciliter les essais

            friend ostream & operator << (ostream & os, const Pers & p)
            {
                return p.display (os);
            }

        }; // Pers

    class ILessThanGen {
    public:
        virtual bool operator () (const Pers & pers1, const Pers & pers2) = 0;
        virtual ~ILessThanGen(){}
    };

    class TriParAgeAsc : public ILessThanGen {
    public:
        virtual bool  operator() (const Pers & pers1, const Pers & pers2){
            if (pers1.getAge() < pers2.getAge()){
                return true;
            } else {
                return false;
            }
        }
        virtual ~TriParAgeAsc() {}
    };

    class TriParNomDesc : public ILessThanGen {
       public:
        virtual bool operator() (const Pers & pers1,const Pers & pers2){
            if (pers1.getNom() > pers2.getNom()){
                return true;
            } else {
                return false;
            }
        }
        virtual ~TriParNomDesc() {}
    };

    template <typename T, typename Iter_t>
    void selectSort (Iter_t deb, Iter_t fin, T isl)
    {
        if (fin <= deb) return;

        for ( ; deb < fin - 1; ++deb)
        {
            Iter_t rgMin = deb;
            for (Iter_t j (deb + 1); j < fin; ++j)
                if (isl (*j, *rgMin)) rgMin = j;
            swap (*deb, *rgMin);
        }

    } // selectSort()


    void testLessThanAbstrGen (void)
    {
        cout << "LessThanAbstrGen : \n";

        typedef vector <Pers> CVPers;
        typedef CVPers::size_type IndPers_t;
        CVPers vPers;

        vPers.push_back (Pers ("Charlotte", 21));
        vPers.push_back (Pers ("Alfred",    12));
        vPers.push_back (Pers ("Jean",      42));
        vPers.push_back (Pers ("Noemie",    11));
        vPers.push_back (Pers ("Berthe",    99));
        vPers.push_back (Pers ("Agathe",    29));
        vPers.push_back (Pers ("Sylvain",   42));
        vPers.push_back (Pers ("Pierre",    75));

        cout << "\nTri par age croissant\n\n";

        selectSort (vPers.begin(), vPers.end(), TriParAgeAsc());

        for (const Pers & personne : vPers)
            cout << personne << '\n';

        cout << "\nTri par nom decroissant\n\n";

        selectSort (vPers.begin (), vPers.end (), TriParNomDesc ());

        for (const Pers & personne : vPers)
            cout << personne << '\n';

    } // testLessThanAbstrGen()

}

int main(){
    testLessThanAbstrGen();
    return  0;
}
