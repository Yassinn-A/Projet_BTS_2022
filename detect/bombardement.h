/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bombardement.h
 * Author: snir2g1
 *
 * Created on 9 mars 2022, 17:01
 */

#ifndef BOMBARDEMENT_H
#define BOMBARDEMENT_H
#include "/home/snir2g1/NetBeansProjects/cppGPIO/include/cppgpio/buttons.hpp"

class bombardement :public GPIO::Switch{
public:
    bombardement(int addr);
    virtual ~bombardement();
    bool detection();
private:
    
    bool detected;
    int gpio;
};

#endif /* BOMBARDEMENT_H */

