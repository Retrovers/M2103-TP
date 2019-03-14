#include <iostream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <duree.h>

using namespace NsUtil;

void testDuree(){
    std::vector <Duree *> duree;
    int secondes;
    while (true){
        std::cout << "Entrez des secondes : ";
        std::cin >> secondes;
        Duree d(secondes);
        d.display();
        std::cout << std::endl;
        duree.push_back(&d);
        std::cout << "Vecteur duree : " << std::endl;
        for (Duree * d : duree){
            std::cout << "- " << d << std::endl;
        }
    }
}


