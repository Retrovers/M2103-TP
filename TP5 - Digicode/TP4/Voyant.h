#ifndef VOYANT_H
#define VOYANT_H

#include <iomanip>

enum Couleur{
    rouge,
    vert
};

enum Etat {
    allume,
    eteint
};

class Voyant{
private:
    Etat etat;
    Couleur couleur;
public:
    Voyant(Couleur couleur, Etat etat);
    void allumer(void);
    void eteindre(void);
    std::string getStatut();
};

#endif // VOYANT_H
