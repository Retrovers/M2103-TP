#ifndef RATIONNEL_H
#define RATIONNEL_H


namespace nsMath {

    class Rationnel {
    private :
        int myNum;
        int myDenom;

        void simplifier();

    public:
        Rationnel(const int& Num = 0, const int& Denom = 0);
        Rationnel (const Rationnel& copy);
        void display();

        Rationnel operator+(const Rationnel& rat);
        Rationnel operator-(const Rationnel& rat);
        Rationnel operator*(const Rationnel& rat);
        Rationnel operator/(const Rationnel& rat);

        bool operator<(const Rationnel& rat);
        bool operator==(const Rationnel& rat);
    };
}

namespace  {
    int PGCD(int a, int b);
}

#endif // RATIONNEL_H
