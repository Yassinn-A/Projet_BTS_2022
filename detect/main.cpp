/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: snir2g1
 *
 * Created on 9 mars 2022, 14:04
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <fcntl.h>

#include "bombardement.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    bombardement *detecteur=new bombardement(24);
    if(detecteur->detection()==true){
        cout<<"Detection d'un rayon infrarouge"<<endl;
    }
    delete detecteur;
    return 0;
}

