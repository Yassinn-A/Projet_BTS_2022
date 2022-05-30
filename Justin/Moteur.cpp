#include <iostream>
#include "../defs/Moteur.h"

using namespace std;
using namespace GPIO;

Moteur::Moteur() {
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

Moteur::~Moteur() {
    
}
