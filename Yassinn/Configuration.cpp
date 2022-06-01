#include "../defs/Configuration.hpp"
#include <iostream>
#include <list>
#include <typeinfo>

void Configuration::fichier_lu(const char * chemin_xml){
    pugi::xml_document doc;
    if (doc.load_file(chemin_xml)){
        fichierLu = true;
    }else{
        fichierLu = false;
    }
}
void Configuration::affiche_attribue_nom_valeur(pugi::xml_node noeud){
    for (pugi::xml_attribute attr = noeud.first_attribute(); attr; attr = attr.next_attribute())
    {
        std::cout << " " << attr.name() << " = " << attr.value();
    }
    std::cout << "\n";
}

void Configuration::affiche_valeur(pugi::xml_node noeud){
    for (pugi::xml_attribute attr = noeud.first_attribute(); attr; attr = attr.next_attribute())
    {
        std::cout << attr.value();
    }
    std::cout << "\n";
}

const char * Configuration::type(pugi::xml_node noeud){
    return noeud.attribute("typ").value();
}

const char * Configuration::role(pugi::xml_node noeud){
    return noeud.attribute("role").value();
}

int Configuration::identifiant(pugi::xml_node noeud){
    return noeud.attribute("id").as_int();
}

int Configuration::adresse_I2C(pugi::xml_node noeud){
    return noeud.attribute("I2C").as_int();
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
    for (pugi::xml_node node = noeud; node; node = node.next_sibling(node.name())){
        //return noeud.attribute("I2C").as_int();
        tab.push_back(node.attribute("adresse").as_int());
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

/*OBSOLETE
Cree une liste compose d'un ou de plusieurs couples adresse registre
*/
std::list<const char *> Configuration::valeur_adresse(pugi::xml_node noeud){
    std::list<const char *> tab;
    for (pugi::xml_node node = noeud; node; node = node.next_sibling(node.name())){
        tab.push_back(node.first_attribute().value());
    }
    return tab;
}

/*OBSOLETE
Cree une liste compose d'un ou de plusieurs couples valeurs registre
*/
std::list<const char *> Configuration::valeur_ordre(pugi::xml_node noeud){
    std::list<const char *> tab;
    for (pugi::xml_node node = noeud; node; node = node.next_sibling(node.name())){
        tab.push_back(node.first_attribute().next_attribute().value());
    }
    return tab;
}





