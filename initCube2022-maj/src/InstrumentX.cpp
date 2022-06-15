#include "../defs/InstrumentX.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

InstrumentX::InstrumentX(){
    status = new Status();
    configuration = new Configuration();
}

InstrumentX::InstrumentX(const Instrument& orig) {
}

InstrumentX::~InstrumentX() {

}

void InstrumentX::activer(){
   
}

void InstrumentX::desactiver(){

}

int InstrumentX::faireMesure(char arg){
    
}

float * InstrumentX::obtenirMesure(){

}

void InstrumentX::repos(){

}

void InstrumentX::resetStatus(){

}

void InstrumentX::envoyerTrame(){

}

void InstrumentX::obtenirTempInst(){

}

void InstrumentX::obtenirMode(){

}

void InstrumentX::setCheminConfig(const char * cheminConfig){
    chemin_config = cheminConfig;
}


void InstrumentX::listToTab(list<int> liste, unsigned char tableau[128]){
    std::copy(liste.begin(), liste.end(), tableau);
}

int InstrumentX::lireAdresseI2C(){
    if(doc.load_file(chemin_config)){
        pugi::xml_node noeud_adresse = doc.child("SegmentVol").child("Charge_utile").child("Instrument");
        adresse_I2C = configuration->adresse_I2C(noeud_adresse);
        return adresse_I2C;
    }   
    return -1;
}

int InstrumentX::lireNombre_bypass(){
    if(doc.load_file(chemin_config)){
        pugi::xml_node noeud_nombre_bypass = doc.child("SegmentVol").child("Charge_utile").child("Nombre_bypass");
        nombre_ByPass = configuration->nombre_noeud(noeud_nombre_bypass);
        return nombre_ByPass;
    }   
    return -1;
}

int InstrumentX::lireAdresse_bypass(){
    if(doc.load_file(chemin_config)){
        pugi::xml_node noeud_adresse = doc.child("SegmentVol").child("Charge_utile").child("PasseTravers");
        adresse_ByPass = configuration->adresse_bypass(noeud_adresse);
        return adresse_ByPass;
    }   
    return -1;
}


int InstrumentX::lireNombre_canal(){
    if(doc.load_file(chemin_config)){
        pugi::xml_node noeud_nombre_canal = doc.child("SegmentVol").child("Charge_utile").child("Nombre_canal");
        nombre_canal = configuration->nombre_noeud(noeud_nombre_canal);
        return nombre_canal;
    }
    return -1; 
}

int InstrumentX::lireNumero_canal(){
    if(doc.load_file(chemin_config)){
        pugi::xml_node noeud_numero_canal = doc.child("SegmentVol").child("Charge_utile").child("Canal");
        numero_canal = configuration->numero_canal(noeud_numero_canal);
        return numero_canal;
    }
    return -1;
}


int InstrumentX::lireNombre_activation(){
    if(doc.load_file(chemin_config)){
        pugi::xml_node noeud_nombre_activation = doc.child("SegmentVol").child("Charge_utile").child("Nombre_activation");
        nombre_activation = configuration->nombre_noeud(noeud_nombre_activation);
        return nombre_activation;
    }
    return -1;
}

list<int> InstrumentX::lireAdresse_activation(){
    list<int> erreur;
    if(doc.load_file(chemin_config)){
        pugi::xml_node noeud_activation = doc.child("SegmentVol").child("Charge_utile").child("Activation");
        adresse_activation = configuration->valeur_adresse_ordre(noeud_activation);
        return adresse_activation;
    }
    erreur.push_back(-1);
    return erreur;
}

int InstrumentX::lireNombre_desactivation(){
    if(doc.load_file(chemin_config)){
        pugi::xml_node noeud_nombre_desactivation = doc.child("SegmentVol").child("Charge_utile").child("Nombre_desactivation");
        nombre_desactivation = configuration->nombre_noeud(noeud_nombre_desactivation);
        return nombre_desactivation;
    }
    return -1;
}

list<int> InstrumentX::lireAdresse_desactivation(){
    list<int> erreur;
    if(doc.load_file(chemin_config)){
        pugi::xml_node noeud_desactivation = doc.child("SegmentVol").child("Charge_utile").child("Desactivation");
        adresse_desactivation = configuration->valeur_adresse_ordre(noeud_desactivation);
        return adresse_desactivation;
    }
    erreur.push_back(-1);
    return erreur;
}

int InstrumentX::lireNombre_repos(){
    if(doc.load_file(chemin_config)){
        pugi::xml_node noeud_nombre_repos = doc.child("SegmentVol").child("Charge_utile").child("Nombre_repos");
        nombre_repos = configuration->nombre_noeud(noeud_nombre_repos);
        return nombre_repos;
    }
   return -1; 
}

list<int> InstrumentX::lireAdresse_repos(){
    list<int> erreur;
    if(doc.load_file(chemin_config)){
        pugi::xml_node noeud_repos = doc.child("SegmentVol").child("Charge_utile").child("Repos");
        adresse_repos = configuration->valeur_adresse_ordre(noeud_repos);
        return adresse_repos;
    }
    erreur.push_back(-1);
    return erreur;
}

int InstrumentX::lireNombre_realisation(){
    if(doc.load_file(chemin_config)){
        pugi::xml_node noeud_nombre_realisation = doc.child("SegmentVol").child("Charge_utile").child("Nombre_realisation");
        nombre_realisation = configuration->nombre_noeud(noeud_nombre_realisation);
        return nombre_realisation;
    }
    return -1;
}

list<int> InstrumentX::lireAdresse_realisation(){
    list<int> erreur;
    if(doc.load_file(chemin_config)){
        pugi::xml_node noeud_realisation = doc.child("SegmentVol").child("Charge_utile").child("Realisation");
        adresse_realisation = configuration->valeur_adresse_ordre(noeud_realisation);
        return adresse_realisation;
    }
    erreur.push_back(-1);
    return erreur;
}

int InstrumentX::lireNombre_recuperation(){
    if(doc.load_file(chemin_config)){
        pugi::xml_node noeud_nombre_recuperation = doc.child("SegmentVol").child("Charge_utile").child("Nombre_recuperation");
        nombre_recuperation = configuration->nombre_noeud(noeud_nombre_recuperation);
        return nombre_recuperation;
    }
    return -1;
}

list<int> InstrumentX::lireAdresse_recuperation(){
    list<int> erreur;
    if(doc.load_file(chemin_config)){
        pugi::xml_node noeud_recuperation = doc.child("SegmentVol").child("Charge_utile").child("Recuperation");
        adresse_recuperation = configuration->valeur_adresse_ordre(noeud_recuperation);
        return adresse_recuperation;
    }
    erreur.push_back(-1);
    return erreur;
}








