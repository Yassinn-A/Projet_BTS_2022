#include "../defs/testB.hpp"
#include <iostream>

void valeur_attribue(pugi::xml_node noeud){
    for (pugi::xml_attribute attr = noeud.first_attribute(); attr; attr = attr.next_attribute())
    {
        std::cout << " " << attr.name() << " = " << attr.value();
    }
    std::cout << "\n";
}

int main()
{
    pugi::xml_document doc;
    if (doc.load_file("test.xml")){
        std::cout << "fichier lu" << "\n";
    }else{
        std::cout << "fichier non lu" << "\n";
    }

    pugi::xml_node description = doc.child("SegmentVol").child("Charge_utile").child("Description");
    std::cout << description.name() << "\n";
    valeur_attribue(description);

    pugi::xml_node adresse = doc.child("SegmentVol").child("Charge_utile").child("Adresse");
    std::cout << adresse.name() << "\n";    
    valeur_attribue(adresse);

    pugi::xml_node Nombre_registre_config = doc.child("SegmentVol").child("Charge_utile").child("Nombre_registre_config");
    std::cout << Nombre_registre_config.name() << " = " << Nombre_registre_config.child_value() << "\n"; 

    pugi::xml_node Registre_adresse_valeur = doc.child("SegmentVol").child("Charge_utile").child("Registre_adresse_valeur");
    std::cout << Registre_adresse_valeur.name() << "\n";
    for (pugi::xml_node node = doc.child("SegmentVol").child("Charge_utile").child("Registre_adresse_valeur"); node; node = node.next_sibling("Registre_adresse_valeur")){
        valeur_attribue(Registre_adresse_valeur);
    }

    pugi::xml_node Nombre_registre_donnee = doc.child("SegmentVol").child("Charge_utile").child("Nombre_registre_donnee");
    std::cout << Nombre_registre_donnee.name() << " = " << Nombre_registre_donnee.child_value() << "\n"; 

    pugi::xml_node Registre_donnee = doc.child("SegmentVol").child("Charge_utile").child("Registre_donnee");
    std::cout << Registre_donnee.name() << "\n";
    for (pugi::xml_node node = doc.child("SegmentVol").child("Charge_utile").child("Registre_donnee"); node; node = node.next_sibling("Registre_donnee")){
        valeur_attribue(Registre_donnee);
    }

    pugi::xml_node donnees = doc.child("SegmentVol").child("Charge_utile").child("Donnees");
    std::cout << donnees.name() << "\n";    
    valeur_attribue(donnees);

    pugi::xml_node securite = doc.child("SegmentVol").child("Securite");
    std::cout << securite.name() << "\n";    
    valeur_attribue(securite);
    
}

/*
for (pugi::xml_attribute attr = tools.first_attribute(); attr; attr = attr.next_attribute())
    {
        std::cout << " " << attr.name() << " = " << attr.value();
    }
    std::cout << "\n";
*/
