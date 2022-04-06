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

Protecteur::Protecteur(){
    leSegment = new SegmentVol();
}

Protecteur::~Protecteur(){   
}


void Protecteur::rebootSave(){
    //incrementation reboot
    leSegment->getReboot()->setNumber(leSegment->getReboot()->getNumber()+1);
    //maj date du reboot
    time_t now = time(0);
    char* date = ctime(&now);
    leSegment->getReboot()->setDateHour(date);
    //sauvegarde infos
    leSegment->getSave()->creerSauvegarde(leSegment);
}

