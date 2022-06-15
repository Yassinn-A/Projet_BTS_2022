#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "pugixml.hpp"
#include <iostream>
#include <list>
#include <typeinfo>

class Configuration {
public:
    const char * type(pugi::xml_node noeud);
    const char * role(pugi::xml_node noeud);
    int identifiant(pugi::xml_node noeud);
    int adresse_I2C(pugi::xml_node noeud);
    int adresse_bypass(pugi::xml_node noeud);
    int nombre_noeud(pugi::xml_node noeud);
    std::list<int> valeur_adresse_ordre(pugi::xml_node noeud);
    std::list<int> adresse_donnee(pugi::xml_node noeud);
    const char * mode_survie(pugi::xml_node noeud);
    const char * particules_energie(pugi::xml_node noeud);
private:

};

#endif /* CONFIGURATION_H */