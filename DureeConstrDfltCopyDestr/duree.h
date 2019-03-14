#ifndef DUREE_H
#define DUREE_H


#include <iostream>
#include <iomanip>
#include <iostream>
#include <fstream>

namespace NsUtil {
    class Duree {

    private:

        unsigned long long myDuree, mySeconds, myMinutes , myHours, myDay;

        void normaliser(void);

    public :
        Duree(const unsigned long long& Duree);

        int getDuree(void);

        void display(void);

        void incr(const unsigned long long& delta);

        void decr(const unsigned long long& delta);

        ~Duree();
    };
}

#endif // DUREE_H
