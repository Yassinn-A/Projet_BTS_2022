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
#include <iostream>
using namespace std;

bombardement::bombardement():InputDetect({24},GPIO::GPIO_EDGE::BOTH){
    detected= false;
}

bombardement::~bombardement() {
}


void bombardement:: triggered(unsigned int gpio){
    cout<<"Test"<<endl;
}

