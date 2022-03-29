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
#include "./PowerControler.h"

class PowerControler;

class DetecteurParticules : public GPIO::InputDetect{
public:
    DetecteurParticules();
    virtual ~DetecteurParticules();
    void triggered(unsigned int gpio);
    PowerControler* getPowerControler(){ return powerControler; }
    void setPowerControler(PowerControler* powercontroler){ this->powerControler = powercontroler; }
private:
    bool detected;
    PowerControler * powerControler;
};

#endif /* DETECTEURPARTICULES_H */

