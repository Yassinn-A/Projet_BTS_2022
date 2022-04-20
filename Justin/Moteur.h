/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   moteur.h
 * Author: snir2g1
 *
 * Created on 22 mars 2022, 16:49
 */

#ifndef MOTEUR_H
#define MOTEUR_H
#include "../../NetBeansProjects/Moteur/gpio/include/cppgpio/output.hpp"
#include "Soleil.h"

using namespace GPIO;
class Soleil;
class Moteur {
public:
    Moteur();
    void tournerG();
    void tournerD();
    void veille();
    void nveille();
    void eteindre();
    void orientation();
    virtual ~Moteur();
private:
    DigitalOut* direction = new DigitalOut(19);
    DigitalOut* speed = new DigitalOut(18);
    DigitalOut* sleep = new DigitalOut(26);
    Soleil* soleil;
};

#endif /* MOTEUR_H */

