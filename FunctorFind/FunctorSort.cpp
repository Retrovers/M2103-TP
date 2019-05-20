/**
 *
 * @file     FunctorSort.cpp
 *
 * @authors  M. Laporte, D. Mathieu
 *
 * @date     07/12/2011
 *
 * @version  V1.0
 *
 **/
#include <string>
#include <vector>
#include <algorithm> // sort()
#include <iostream>

using namespace std;

namespace
{
    template <typename T>
    class IPredicatGen
    {
      public :
        virtual ~IPredicatGen (void) {}
        virtual bool operator () (const T &) const = 0;

    }; // ILessThanGen

    template <typename T>
    class ILessThanGen
    {
      public :
        virtual ~ILessThanGen (void) {}
        virtual bool operator () (const T &, const T &) const = 0;

    }; // ILessThanGen

    class Pers
    {
        string   myNom;
        unsigned myAge;

      public :
        Pers (const string & Nom, unsigned Age)
            : myNom (Nom), myAge (Age) {}

        const string & getNom (void) const noexcept { return myNom; }
        unsigned       getAge (void) const noexcept { return myAge; }

    private :
        ostream & display (ostream & os)  const
        {
            return os << getAge () << " - " << getNom ();

        } // display()

      public :
        friend ostream & operator << (ostream & os, const Pers & p)
        {
            return p.display (os);

        }

    }; // Pers

    class SelParTrancheAge : public IPredicatGen<Pers>{
    private:
        int myAgeMin;
        int myAgeMax;
    public:

        virtual ~SelParTrancheAge() {}

        SelParTrancheAge(const int ageMin,const int ageMax){
            this->myAgeMax = ageMax;
            this->myAgeMin = ageMin;
        }

       virtual bool operator() (const Pers & p) const {
            if (this->myAgeMin <= p.getAge() && this->myAgeMax >= p.getAge()){
                return true;
            } else {
                return false;
            }
        }
    };


    class SelParNomMin : public IPredicatGen<Pers> {
    private:
        string myNomMin;
    public:

        virtual ~ SelParNomMin() {}

        SelParNomMin(string nom){
            this->myNomMin = nom;
        }

        virtual bool operator () (const Pers & p) const{
            if (p.getNom() > this->myNomMin){
                return true;
            } else {
                return false;
            }
        }
    };

    class TriParAgeAsc : public ILessThanGen <Pers>
    {
      public :
        virtual ~TriParAgeAsc (void) noexcept {}

        virtual bool operator () (const Pers & p1, const Pers & p2)
                        const noexcept
        {
            return p1.getAge () <= p2.getAge ();

        } // operator ()

    }; // TriParAgeAsc

    class TriParNomDesc : public ILessThanGen <Pers>
    {
      public :
        virtual ~TriParNomDesc (void) noexcept {}

        virtual bool operator () (const Pers & p1, const Pers & p2)
                        const noexcept
        {
            return p1.getNom () >= p2.getNom ();

        } // operator ()

    }; // TriParNomDesc


    void functorFind (void)
    {
        cout << "FunctorFind : \n";

        typedef vector <Pers> CVPers;
        CVPers vPers;

        vPers.push_back ( Pers ("Charlotte", 21));
        vPers.push_back ( Pers ("Alfred",    12));
        vPers.push_back ( Pers ("Jean",      42));
        vPers.push_back ( Pers ("Noemie",    11));
        vPers.push_back ( Pers ("Berthe",    99));
        vPers.push_back ( Pers ("Agathe",    29));
        vPers.push_back ( Pers ("Sylvain",   42));
        vPers.push_back ( Pers ("Pierre",    75));

        for (const Pers & personne : vPers)
            cout << personne << '\n';

        CVPers::const_iterator pos;

        cout << "\nRecherche sur  43 <= age <= 75 : ";

        pos = find_if (vPers.begin (), vPers.end (), SelParTrancheAge(43, 75));// a completer
        if (vPers.end () ==pos)
            cout << "Aucun element ne correspond a ce critere\n";
        else
            cout << *pos << '\n';

        cout << "\nRecherche sur  43 <= age <= 45 : ";

        pos = find_if (vPers.begin (), vPers.end (), SelParTrancheAge(43, 45));// a completer
        if (vPers.end () == pos)
            cout << "Aucun element ne correspond a ce critere\n";
        else
            cout << *pos << '\n';

        cout << '\n';

        cout << "\nRecherche sur nom > Noemie : ";

             pos = find_if (vPers.begin (),  vPers.end (),SelParNomMin("Noemie")); // a completer

             if (vPers.end () == pos)
                 cout  << "Aucun element ne correspond a ce critere\n";
             else
                 cout << *pos << '\n';

             cout  << "\nRecherche sur nom > alfred : ";

             pos = find_if (vPers.begin (),  vPers.end (), SelParNomMin("alfred"));// a completer

             if (vPers.end () == pos)
                 cout  << "Aucun element ne correspond a ce critere\n";
             else
                 cout << *pos << '\n';

    } // functorFind()


    void functorSort (void)
    {
        cout << "FunctorSort : \n";

        typedef vector <Pers> CVPers;

        CVPers vPers;

        vPers.push_back ( Pers ("Charlotte", 21));
        vPers.push_back ( Pers ("Alfred",    12));
        vPers.push_back ( Pers ("Jean",      42));
        vPers.push_back ( Pers ("Noemie",    11));
        vPers.push_back ( Pers ("Berthe",    99));
        vPers.push_back ( Pers ("Agathe",    29));
        vPers.push_back ( Pers ("Sylvain",   42));
        vPers.push_back ( Pers ("Pierre",    75));

        cout << "\nTri par age croissant\n\n";

        sort (vPers.begin (), vPers.end (), TriParAgeAsc ());

        for (const Pers & personne : vPers)
            cout << personne << '\n';

        cout << "\nTri par nom decroissant\n\n";

        sort (vPers.begin (), vPers.end (), TriParNomDesc ());

        for (const Pers & personne : vPers)
            cout << personne << '\n';

    } // functorSort()

} // namespace

int main (void)
{
    functorFind ();

    return 0;

} // main()
