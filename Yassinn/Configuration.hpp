#include "pugixml.hpp"
#include <iostream>
#include <list>
#include <typeinfo>

class Configuration {
public:
    void fichier_lu(const char * chemin_xml);
    void affiche_attribue_nom_valeur(pugi::xml_node noeud);
    void affiche_valeur(pugi::xml_node noeud);
    const char * type(pugi::xml_node noeud);
    const char * role(pugi::xml_node noeud);
    int identifiant(pugi::xml_node noeud);
    int adresse_I2C(pugi::xml_node noeud);
    int nombre_noeud(pugi::xml_node noeud);
    std::list<int> valeur_adresse_ordre(pugi::xml_node noeud);
    std::list<int> adresse_donnee(pugi::xml_node noeud);
    const char * mode_survie(pugi::xml_node noeud);
    const char * particules_energie(pugi::xml_node noeud);
private:
    std::list<const char *> valeur_adresse(pugi::xml_node noeud);
    std::list<const char *> valeur_ordre(pugi::xml_node noeud);
    bool fichierLu;
};