/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   I2C.cpp
 * Author: snir2g1
 * 
 * Created on 14 mars 2019, 16:14
 */
#include <iostream>
#include "../defs/I2C.h"

I2C::I2C() {
}

I2C::~I2C() {
}

int I2C::ouvrirAcces() {
    int fd = 1;
    fd = open("/dev/i2c-1", O_RDWR);
    if (fd < 0) {
        openlog("I2C : ", LOG_PID, LOG_LOCAL0);
        syslog(LOG_ERR, "open");
        closelog();
    } else {
        return fd;
    }
    return -1;
}

void I2C::setAddrEsclave(unsigned char addr) {
    address = addr;
}

void I2C::configurerAddrEsclave(int chemin) {
    if (ioctl(chemin, I2C_SLAVE, address) < 0) {
        openlog("I2C : ", LOG_PID, LOG_LOCAL0);
        syslog(LOG_ERR, "ioctl");
        closelog();
    }
}

void I2C::setAddrRegistre(unsigned char reg) {
    addrRegistre = reg;
}

int I2C::ecrire() {
    int cheminAcces = ouvrirAcces();
    int ret;
    configurerAddrEsclave(cheminAcces);
    ret = write(cheminAcces, &addrRegistre, 1);
    if (ret <= 0) {
        openlog("I2C : ", LOG_PID, LOG_LOCAL0);
        syslog(LOG_ERR, "write");
        closelog();
    } else {
        fermerAcces(cheminAcces);
        return ret;
    }
    fermerAcces(cheminAcces);
    return -1;
}

char* I2C::lire() {
    int cheminAcces = ouvrirAcces();
    configurerAddrEsclave(cheminAcces);
    int ret = read(cheminAcces, valeur, 2);
    if (ret <= 0) {
        openlog("I2C : ", LOG_PID, LOG_LOCAL0);
        syslog(LOG_ERR, "%d read", ret);
        closelog();
        fermerAcces(cheminAcces);
    } else {
        fermerAcces(cheminAcces);
        return valeur;
    }

    return NULL;
}

char I2C::lire1() {
    int cheminAcces = ouvrirAcces();
    configurerAddrEsclave(cheminAcces);
    int ret = read(cheminAcces, valeur, 1);
    if (ret <= 0) {
        openlog("I2C : ", LOG_PID, LOG_LOCAL0);
        syslog(LOG_ERR, "%d read", ret);
        closelog();
        fermerAcces(cheminAcces);
    } else {
        fermerAcces(cheminAcces);
        return valeur[0];
    }

    return 0;
}

void I2C::fermerAcces(int chemin) {
    close(chemin);
}

int I2C::ecrire(char avaleur) {
    int cheminAcces = ouvrirAcces();
    char configuration[2] = {addrRegistre, avaleur};
    int ret = 1;
    configurerAddrEsclave(cheminAcces);
    ret = write(cheminAcces, configuration, 2);
    if (ret <= 0) {
        openlog("I2C : ", LOG_PID, LOG_LOCAL0);
        syslog(LOG_ERR, "write");
        closelog();
    } else {
        fermerAcces(cheminAcces);
        return ret;
    }
    fermerAcces(cheminAcces);
    return -1;
}
int I2C::ecrireNbr(int nbrRegistre,char avaleur,char avaleur2,char avaleur3){
    //**************************
    if(nbrRegistre==1){
        ecrire();
    }
    //**************************
    if(nbrRegistre==2){
        ecrire(avaleur)
    }
    //**************************
    if(nbrRegistre==3){
        int cheminAcces = ouvrirAcces();
        char configuration[3] = {addrRegistre, avaleur, avaleur2};
        int ret = 1;
        configurerAddrEsclave(cheminAcces);
        ret = write(cheminAcces, configuration, 3);
        if (ret <= 0) {
            openlog("I2C : ", LOG_PID, LOG_LOCAL0);
            syslog(LOG_ERR, "write");
            closelog();
        } else {
            fermerAcces(cheminAcces);
            return ret;
        }
        fermerAcces(cheminAcces);
        return -1;
    }
    //**************************
    if(nbrRegistre==4){
        int cheminAcces = ouvrirAcces();
        char configuration[4] = {addrRegistre, avaleur, avaleur2, avaleur3};
        int ret = 1;
        configurerAddrEsclave(cheminAcces);
        ret = write(cheminAcces, configuration, 4);
        if (ret <= 0) {
            openlog("I2C : ", LOG_PID, LOG_LOCAL0);
            syslog(LOG_ERR, "write");
            closelog();
        } else {
            fermerAcces(cheminAcces);
            return ret;
        }
        fermerAcces(cheminAcces);
        return -1;
    }
}

char* I2C::lireNbr(int nbrRegistre,char addrRead){

    //*****************************
    if(nbrRegistre==2){
        int cheminAcces = ouvrirAcces();
        configurerAddrEsclave(cheminAcces);
        int ret = read(cheminAcces, addrRead, 2);
        if (ret <= 0) {
            openlog("I2C : ", LOG_PID, LOG_LOCAL0);
            syslog(LOG_ERR, "%d read", ret);
            closelog();
            fermerAcces(cheminAcces);
        } else {
            fermerAcces(cheminAcces);
            return valeur;
        }
        return NULL;
    }
    //*****************************
    if(nbrRegistre==3){
        int cheminAcces = ouvrirAcces();
        configurerAddrEsclave(cheminAcces);
        int ret = read(cheminAcces, addrRead, 3);
        if (ret <= 0) {
            openlog("I2C : ", LOG_PID, LOG_LOCAL0);
            syslog(LOG_ERR, "%d read", ret);
            closelog();
            fermerAcces(cheminAcces);
        } else {
            fermerAcces(cheminAcces);
            return valeur;
        }
        return NULL;
    }
}
    
