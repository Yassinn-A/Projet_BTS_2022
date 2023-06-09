/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reboot.h
 * Author: Romain
 *
 * Created on 23 juin 2020, 17:41
 */

#ifndef REBOOT_H
#define REBOOT_H

#include <string>
#include "pugixml.hpp"
#include <list>
#include <sstream>

using namespace std;

class Reboot {
public:
    Reboot();
    Reboot(int anbreReboot, string adateHeure);
    virtual ~Reboot();
    int getNumber();
    string getDateHour();
    void setDateHour(string adateHour);
    void setNumber(int anumber);
	void resetStatus();
    void systemeReboot();
    void setTransmit(bool trans);
    bool getTransmit();
private:
    string dateHour;
    int number;
    bool transmit;
};

#endif /* REBOOT_H */


