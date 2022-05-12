/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: snir2g1
 *
 * Created on 22 mars 2022, 15:05
 */
#include <cstdlib>

#include "defs/CameraPhoto.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    CameraPhoto* laCamera = new CameraPhoto();
    //I2C* leI2C = new I2C();
    char tab[JPEG_BUF_SIZE];

    laCamera->activer();

    laCamera->prendrePhoto();

    laCamera->desactiver();

    laCamera->getPhoto(tab);
  
    
  int taille = laCamera->getTaille();

    ofstream file;
    file.open("Tab.jpeg", ios::out);
    if (!file) {
        cout << "Erreur fichier.." << endl;
        return 0;
    }
    cout << "\nFichier OK !." << endl;

    file.write(tab, taille);
    perror("");
    file.close();
    cout << "\nFichier sauvé et fermé !." << endl;
    return 0;
}
 
    
    

