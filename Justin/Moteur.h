#ifndef MOTEUR_H
#define MOTEUR_H
#include "../include/cppgpio/output.hpp"
#include "../defs/Soleil.h"

using namespace GPIO;
class Soleil;
class Moteur {
public:
    Moteur();
    void tournerG();
    void tournerD();
    void veille();
    void nveille();
    void eteindre();
    virtual ~Moteur();
private:
    DigitalOut* direction = new DigitalOut(19);
    DigitalOut* speed = new DigitalOut(18);
    DigitalOut* sleep = new DigitalOut(26);
    Soleil* soleil;
};

#endif /* MOTEUR_H */

