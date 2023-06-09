/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DetecteurParticules.cpp
 * Author: snir2g1
 * 
 * Created on 29 mars 2022, 13:36
 */

#include "../defs/DetecteurParticules.h"

DetecteurParticules::DetecteurParticules(SegmentVol *leSegment):InputDetect({24},GPIO::GPIO_EDGE::BOTH),Protecteur(leSegment){
    detected =false;
    
}


DetecteurParticules::~DetecteurParticules() {
}

void DetecteurParticules:: triggered(unsigned int gpio){
    rebootSave();
    sleep(1);
    leSegment->getPowerControler()->securedReboot();
}