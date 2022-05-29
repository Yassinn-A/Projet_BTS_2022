#include "../defs/SegmentVol1.h"
#include "../defs/Moteur.h"
#include "../defs/Soleil.h"
#include "../defs/Batterie.h"
#include <iostream>

using namespace std;   
    
SegmentVol::SegmentVol() {
    soleil=new Soleil();
    moteur = new Moteur();
    batterie =new Batterie();
}

void SegmentVol::orientation(){
    int luminosite1 = soleil->luminosity1(); //récupère valeur capteur 1
    int luminosite2 = soleil->luminosity2();//récupère valeur capteur 2
	bool rotationR=false, rotationL=false;

		if((luminosite1>luminosite2+20 ) && (!rotationL)) {//si capteur 1 > +ou- 20 capteur2
				moteur->tournerG();
				rotationL = true;
				rotationR=false;
				while(luminosite1>luminosite2+20) {
					cout<< "PCapteur 1: " << luminosite1<<endl;
					cout<< "PCapteur 2: "<< luminosite2<<endl;
					luminosite1 = soleil->luminosity1();//lum1 = valeur capteur 1
					usleep(10000);
					luminosite2 = soleil->luminosity2();//lum2 = valeur capteur 2

				}
				moteur->tournerD();
				rotationL = false;
			}
		else if ((luminosite1<luminosite2-20) && ( !RotationR)) {

				moteur->tournerD();
				rotationR = true;
				rotationL = false;
				while(luminosite1<luminosite2-20 ){
					cout<< "ACapteur 3: "<< luminosite1<<endl;
					cout<< "ACapteur 4: "<<luminosite2<<endl;
					luminosite1 = soleil->luminosity1();
					usleep(10000);
					luminosite2 = soleil->luminosity2();
				}
				moteur->tournerG();
				rotationR=false;
			}
		else {
			moteur->eteindre();
			rotationL = false;
			rotationR=false;
		}

        luminosite1 = soleil->luminosity1();
        luminosite2 = soleil->luminosity2();
		usleep(500000);
    
}

void SegmentVol::lancement(){
    batterie->obtenirStatus();
    batterie->getChargingLevel();
    cout<< (int)batterie->getChargingLevel()<< " %" << endl;
    if((int)batterie->getChargingLevel()<=30){
        orientation();
    }
    else{
        moteur->eteindre();
    }
}

thread SegmentVol::tlancement(){
    return thread([this]{
        lancement();
    });
}

SegmentVol::~SegmentVol() {
}
