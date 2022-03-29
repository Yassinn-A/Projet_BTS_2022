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

PowerControler::PowerControler(){
}
PowerControler::~PowerControler() {
}

void PowerControler::securedReboot(){   
    setAddrEsclave(0x14);
    setWakeupEnabled();
    setWakeupOnChargeOff();
    setSystemPowerSwitchOff();
    setPowerOff();
    system("sudo shutdown -h now");  
}

void PowerControler::setWakeupEnabled(){
    char buf[4];
    setAddrRegistre(0xC2);
    ecrireNbr(1,0,0,0);
    buf[0] =0xC2 ;
    lireNbr(3,buf);
    ecrireNbr(4,0x25,0x01,0xDB);
    ecrireNbr(1,0,0,0);
    buf[0] =0xC2 ;
    lireNbr(3,buf);
}

void PowerControler::setWakeupOnChargeOff(){
    char buf[4];
    setAddrRegistre(0x63);
    ecrireNbr(3,0x00,0xFF,0);
    ecrireNbr(1,0,0,0);
    buf[0] =0x63 ;
    lireNbr(2,buf);   
}

void PowerControler::setSystemPowerSwitchOff(){
    setAddrRegistre(0x64);
    ecrireNbr(3,0x00,0xFF,0);    
}

void PowerControler::setPowerOff(){
    setAddrRegistre(0x62);
    ecrireNbr(3,0x05,0xFA,0); 
}


