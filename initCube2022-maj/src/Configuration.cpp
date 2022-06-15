#include "../defs/Configuration.hpp"
#include <iostream>
#include <list>
#include <typeinfo>



const char * Configuration::type(pugi::xml_node noeud){
    return noeud.attribute("type").value();
}

const char * Configuration::role(pugi::xml_node noeud){
    return noeud.attribute("role").value();
}

int Configuration::identifiant(pugi::xml_node noeud){
    return noeud.attribute("id").as_int();
}

int Configuration::adresse_I2C(pugi::xml_node noeud){
    return noeud.attribute("adresse_I2C").as_int();
}

int Configuration::adresse_bypass(pugi::xml_node noeud){
    return noeud.attribute("by_pass").as_int();
}


/*
Retourne le nombre compris dans la balise
*/
int Configuration::nombre_noeud(pugi::xml_node noeud){
    return atoi(noeud.child_value());
}

/*
Type : liste de int
Cree une liste compose d'un ou de plusieurs couples adresse ordre
*/
std::list<int> Configuration::valeur_adresse_ordre(pugi::xml_node noeud){
    std::list<int> tab;
    tab.push_back(noeud.attribute("adresse").as_int());
    for (pugi::xml_node node = noeud; node; node = node.next_sibling(node.name())){
        tab.push_back(node.attribute("ordre").as_int());
    }
    return tab;
}

/*
Type : liste de int
Cree une liste compose d'un ou des adresses de donnee
*/
std::list<int> Configuration::adresse_donnee(pugi::xml_node noeud){
    std::list<int> tab;
    for (pugi::xml_node node = noeud; node; node = node.next_sibling(node.name())){
        tab.push_back(node.attribute("adresse").as_int());
    }
    return tab;
}

const char * Configuration::mode_survie(pugi::xml_node noeud){
    return noeud.attribute("mode_survie").value();
}

const char * Configuration::particules_energie(pugi::xml_node noeud){
    return noeud.attribute("particules_energie").value();
}






