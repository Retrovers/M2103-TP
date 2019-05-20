#include <iomanip>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


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


template <typename T>
class ILessThanGen
{
   public :
     virtual ~ILessThanGen (void) {}
     virtual bool operator () (const T &, const T &) const = 0;

}; // ILessThanGen


 class TriParAgeAsc : public ILessThanGen<Pers>
 {
   public :
     virtual ~TriParAgeAsc (void) noexcept {}

     virtual bool operator () (const Pers & p1, const Pers & p2)
                     const noexcept
     {
         return p1.getAge () <= p2.getAge ();

     } // operator ()

 }; // TriParAgeAsc

 class TriParNomDesc : public ILessThanGen<Pers>
 {
   public :
     virtual ~TriParNomDesc (void) noexcept {}

     virtual bool operator () (const Pers & p1, const Pers & p2)
                     const noexcept
     {
         return p1.getNom () >= p2.getNom ();

     } // operator ()

 }; // TriParNomDesc



template <typename T, typename iter_t>
iter_t partitionnement(const ILessThanGen<T> & compare,
                       const iter_t & first,
                       const iter_t & last) {
    bool isUp = true;
    iter_t pivot;
    iter_t courant;
    int incr;

    pivot = first;
    courant = last;
    incr = -1;

    while (pivot != courant) {
        if ((!isUp && compare(*pivot, *courant))
           || (isUp && compare(*courant, *pivot))) {

            swap(*pivot, *courant);
            swap(pivot, courant);
            isUp = !isUp;
            incr = -incr;

        }
        courant = courant + incr;
    }
    return pivot;
 }



template <typename T, typename iter_t>
void quickSort (const ILessThanGen<T> & tab,
                const iter_t & beg,
                const iter_t &  end) {

    if (beg < end) {
         iter_t pos = partitionnement(tab, beg, end -1);
         quickSort(tab, beg, pos);
         quickSort(tab, pos + 1, end);
     }
}


void functorSort (void)
{
//    typedef typename /*iterator_traits*/ ::value_type Value_t;
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

    quickSort(TriParAgeAsc (), vPers.begin(), vPers.end ());

    for (const Pers & personne : vPers)
        cout << personne << '\n';

    cout << "\nTri par nom decroissant\n\n";

    quickSort (TriParNomDesc(), vPers.begin (), vPers.end ());

    for (const Pers & personne : vPers)
        cout << personne << '\n';

} // functorSort()

int main (void) {
    functorSort();
}
