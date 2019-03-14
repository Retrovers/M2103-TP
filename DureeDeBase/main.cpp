#include <iostream>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

class Duree {
private:
    unsigned long long myDuree, mySeconds, myMinutes , myHours, myDay;

    void normaliser(void){
        mySeconds = myDuree;
        myMinutes = mySeconds / 60;
        mySeconds = mySeconds % 60;
        myHours = myMinutes / 60;
        myMinutes = myMinutes % 60;
        myDay = myHours / 24;
        myHours = myHours % 24;
    }

public :
    Duree(const unsigned long long& Duree){
           myDuree = Duree;
           normaliser();
    }
    int getDuree(void){
        return myDuree;
    }
    void display(void){
        cout << setw(3)
                  << myDay << " jour(s) "
                  << myHours << " heure(s) "
                  << myMinutes << " minutes(s) "
                  << mySeconds << " seconde(s)";

    }
    void incr(const unsigned long long& delta){
        myDuree += delta;
        normaliser();
    }
    void decr(const unsigned long long& delta){
        if (myDuree < delta) {
            myDuree = 0;
            normaliser();
        } else {
            myDuree -= delta;
            normaliser();
        }
    }
};

void testDureeDeBase(){
    /* cout << "Entrez un nombre de secondes : ";
    int secondes;
    cin >> secondes;
    Duree d (secondes);
    d.display();
    cout << endl << "My duree : " << d.getDuree() << endl;
    */

    /*
    ifstream testDuree("FichDurees.txt");
    int secondes;
    while(testDuree >> secondes ){
        Duree d (secondes);
        cout << "My duree : " << d.getDuree() << endl;
        d.display();
        cout << endl << endl;
    }
    */

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
}

int main()
{
    testDureeDeBase();
    return 0;
}

