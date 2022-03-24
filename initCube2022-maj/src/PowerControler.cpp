/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PowerControler.cpp
 * Author: snir2g1
 * 
 * Created on 22 mars 2022, 16:14
 */

#include "../defs/PowerControler.h"
#include <iostream>
using namespace std;

PowerControler::PowerControler():InputDetect({24},GPIO::GPIO_EDGE::BOTH),I2C() {
}


PowerControler::~PowerControler() {
}

void PowerControler::securedReboot(){
    char buf[4];
    setAddrEsclave(0x14);
    //Ligne 1 : trame 1
    setAddrRegistre(0xC2);
    ecrireNbr(1,0,0,0);
    buf[0] =0xC2 ;
    lireNbr(3,buf);
    //Ligne 1 : trame 2
    ecrireNbr(4,0x25,0x01,0xDB);
    //Ligne 1 : trame 3
    ecrireNbr(1,0,0,0);
    buf[0] =0xC2 ;
    lireNbr(3,buf);
    //Ligne 2 : trame 1
    setAddrRegistre(0x63);
    ecrireNbr(3,0x00,0xFF,0);
    //Ligne 2 : trame 2
    ecrireNbr(1,0,0,0);
    buf[0] =0x63 ;
    lireNbr(2,buf);
    //Ligne 3
    setAddrRegistre(0x64);
    ecrireNbr(3,0x00,0xFF,0);
    //Ligne 4
    setAddrRegistre(0x62);
    ecrireNbr(3,0x05,0xFA,0);
    //Ligne pour eteindre le terminal
    system("sudo shutdown -h now");
    
}

void PowerControler:: triggered(unsigned int gpio){
    securedReboot();
}
