/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   I2C.h
 * Author: snir2g1
 *
 * Created on 14 mars 2019, 16:14
 */

#ifndef I2C_H
#define I2C_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>
#include <linux/i2c-dev.h>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <list>
#include <iterator>
#include <sstream>
#include <math.h>
#include <syslog.h>

using namespace std;

class I2C {
public:
    I2C();
    virtual ~I2C();
    void setAddrEsclave(unsigned char addr);
    void configurerAddrEsclave(int chemin);
    void setAddrEsclaveByPass(unsigned char addr);
    void configurerAddrEsclaveByPass(int chemin);
    void setAddrRegistre(unsigned char reg);
    int ecrire();
    char* lire();
    char lire1();
    char* lireNbr(int nbrRegistre,char* addrRead);
    int ecrire(char avaleur);
    int ecrireNbr(int nbrRegistre,char avaleur,char avaleur2,char avaleur3);
    int ouvrirAcces();
    void fermerAcces(int chemin);
    int ecrireAdresseRegistre(unsigned char tableau[128], int tailleTableau);
    int lireRegistre(unsigned char tableau[128], int tailleTableau);
    int setfd(int file_descriptor);
protected:
    int fd;
    unsigned char addressBypass;
    unsigned char address;
    unsigned char addrRegistre;
    char valeur[5];

};

#endif /* I2C_H */

