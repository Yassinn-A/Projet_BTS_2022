/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bombardement.cpp
 * Author: snir2g1
 * 
 * Created on 9 mars 2022, 17:01
 */

#include "bombardement.h"

bombardement::bombardement(int addr):Switch(addr,GPIO::GPIO_PULL::OFF){
    detected= false;
    gpio=addr; 
}

bombardement::~bombardement() {
}

bool bombardement::detection(){
    Switch capteurIR(gpio, GPIO::GPIO_PULL::OFF);
    capteurIR.start();
    for(;;){
        bool new_detect=capteurIR.is_on();
        if(new_detect != detected){
            detected = new_detect;
            return true;
        }
    }
}

