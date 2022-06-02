/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Protecteur.cpp
 * Author: snir2g1
 * 
 * Created on 6 avril 2022, 15:30
 */

#include <iostream>
#include <ctime>
#include "../defs/Protecteur.h"
using namespace std;

Protecteur::Protecteur(SegmentVol *leSegment){
    
    this->leSegment = leSegment;
}

Protecteur::~Protecteur(){   
}


void Protecteur::rebootSave(){
    //incrementation reboot
    leSegment->getOrdinateur()->getReboot()->setNumber(leSegment->getOrdinateur()->getReboot()->getNumber()+1);
    //maj date du reboot
    string date;
    leSegment->getHorloge()->lire();
    date = leSegment->getHorloge()->getDateHeure();
    leSegment->getOrdinateur()->getReboot()->setDateHour(date);
    //sauvegarde infos
    leSegment->getSave()->creerSauvegarde(leSegment);
}

