#include <iostream>
#include <vector>

class Module;
class Prof {
private :
    std::string myName;
    std::vector <Module *> matiere;
public:
    void display(void);

    void addModule(Module* module);
    std::string getName(void){
        return myName;
    }
    void setName(const std::string& name){
        myName = name;
    }
};

class Module {
private :
    std::string myName;
    std::vector<Prof *> enseignant;
public :
    void display (void);

    void addProf (Prof* prof);

    std::string getName(void){
        return myName;
    }
    void setName(const std::string& name){
        myName = name;
    }
};

void Module::display(void){
    for (Prof * prof : enseignant){
        std::cout << prof->getName();
    }
}
void Module::addProf(Prof* prof){
    enseignant.push_back(prof);
}
void Prof::display(void){
    for (Module * module : matiere){
        std::cout << module->getName();
    }
}
void Prof::addModule(Module* module){
    matiere.push_back(module);
}
