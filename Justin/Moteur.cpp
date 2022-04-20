#include <iostream>
#include "Moteur.h"

using namespace std;
using namespace GPIO;

Moteur::Moteur() {
    soleil=new Soleil();
}
void Moteur::tournerG(){
    direction->on();
    speed->on(std::chrono::nanoseconds (200000000));
    sleep->on();
}

void Moteur::tournerD(){
    direction->off();
    speed->on(std::chrono::nanoseconds (200000000));
    sleep->on();
}

void Moteur::veille(){
    sleep->off();
}

void Moteur::nveille(){
    sleep->on();
}

void Moteur::eteindre(){
    speed->off();
}

void Moteur::orientation(){
    int luminosite1 = soleil->luminosity1(); //récupère valeur capteur 1
    int luminosite2 = soleil->luminosity2();//récupère valeur capteur 2
    if(luminosite1!=luminosite2+20 ||luminosite1!=luminosite2-20 ){ 
        int lum1 = soleil->luminosity1(); //lum1 = valeur capteur 1
        int lum2 = soleil->luminosity2();//lum2 = valeur capteur 2
        if(lum1>lum2+20 || lum1>lum2-20){//si capteur 1 > +ou- 20 capteur2
            lum1 = soleil->luminosity1();//lum1 change
            lum2 = soleil->luminosity2();//lum2 change
            tournerG();
            while((lum1>lum2+20) ||(lum1<lum2-20) ){
                cout<< "ACapteur 1: "<< lum1<<endl;
                cout<< "ACapteur 2: "<<lum2<<endl;
                lum1 = soleil->luminosity1(); //lum1 = valeur capteur 1
                lum2 = soleil->luminosity2();//lum2 = valeur capteur 2
                cout<< "PCapteur 1: " << lum1<<endl;
                cout<< "PCapteur 2: "<< lum2<<endl;
            }
            tournerD();
        }
        if(lum2>lum1+20 || lum2>lum1-20){
            lum1 = soleil->luminosity1();
            lum2 = soleil->luminosity2();
            tournerD();
            while((lum2>lum1+20) ||(lum2<lum1-20) ){
                cout<< "ACapteur 3: "<< lum1<<endl;
                cout<< "ACapteur 4: "<<lum2<<endl;
                lum1 = soleil->luminosity1();
                usleep(1000);
                lum2 = soleil->luminosity2();
                cout<< "PCapteur 3: "<< lum1<<endl;
                cout<< "PCapteur 4: "<<lum2<<endl;
            }
            tournerG();
        }

        luminosite1 = soleil->luminosity1();
        luminosite2 = soleil->luminosity2();
    }
}

Moteur::~Moteur() {
    
}