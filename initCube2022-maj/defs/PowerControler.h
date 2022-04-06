/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PowerControler.h
 * Author: snir2g1
 *
 * Created on 22 mars 2022, 16:14
 */

#ifndef POWERCONTROLER_H
#define POWERCONTROLER_H
#include "./I2C.h"
class PowerControler :public I2C{
public:
    PowerControler();
    virtual ~PowerControler();    
    void securedReboot();
private:

protected:
    void setWakeupEnabled();
    void setWakeupOnChargeOff();
    void setSystemPowerSwitchOff();
    void setPowerOff();
    
};

#endif /* POWERCONTROLER_H */

