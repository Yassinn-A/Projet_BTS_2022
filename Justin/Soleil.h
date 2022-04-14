/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Soleil.h
 * Author: snir2g1
 *
 * Created on 13 avril 2022, 16:10
 */

#ifndef SOLEIL_H
#define SOLEIL_H
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

class Soleil {
public:
    Soleil();
    virtual ~Soleil();
    int luminosity1();
    int luminosity2();
private:

};

#endif /* SOLEIL_H */

