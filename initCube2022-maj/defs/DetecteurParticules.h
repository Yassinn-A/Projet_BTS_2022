/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DetecteurParticules.h
 * Author: snir2g1
 *
 * Created on 29 mars 2022, 13:36
 */

#ifndef DETECTEURPARTICULES_H
#define DETECTEURPARTICULES_H
#include "../include/cppgpio/buttons.hpp"
#include "./Protecteur.h"

class DetecteurParticules : public Protecteur, GPIO::InputDetect{
public:
    DetecteurParticules();
    virtual ~DetecteurParticules();
    void triggered(unsigned int gpio);
private:
    bool detected;
};

#endif /* DETECTEURPARTICULES_H */

