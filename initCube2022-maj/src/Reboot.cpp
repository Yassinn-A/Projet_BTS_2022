/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reboot.cpp
 * Author: Romain
 * 
 * Created on 23 juin 2020, 17:41
 */
#include "../defs/Reboot.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <iostream>
#include <math.h>
#include <sys/ioctl.h>
using namespace std;


Reboot::Reboot():transmit(false) {
    dateHour = "0000/00/00 00:00:00";
    
    pugi::xml_document doc;
    if(doc.load_file("Save.xml")){
        pugi::xpath_node Reboot=doc.select_node("//SegmentVol/Ordinateur_de_bord/Reboot");
    
    string numberRead=Reboot.node().attribute("number").value();
    istringstream iss(numberRead);
    iss>>number;
    }
}

Reboot::Reboot(int anbreReboot, string adateHeure) {
    dateHour = adateHeure;
    number = anbreReboot;
}



Reboot::~Reboot() {

}

string Reboot::getDateHour() {
    return this->dateHour;
}

void Reboot::setDateHour(string adateHour) {
    this->dateHour = adateHour;
}

int Reboot::getNumber() {
    return this->number;
}

void Reboot::setNumber(int anumber) {
    this->number = anumber;
}

void Reboot::systemeReboot() {
    system("sudo reboot");
}

void Reboot::resetStatus(){
	dateHour = "0000/00/00 00:00:00";
    number = 0;
}

void Reboot::setTransmit(bool trans){
    transmit = trans;
}

bool Reboot::getTransmit(){
    return transmit;
}