#ifndef BATTERIE_H
#define BATTERIE_H
#include "I2C.h"

#define   STATUS_CMD            0x40
#define   CHARGE_LEVEL_CMD      0x41
#define   BATTERY_TEMPERATURE_CMD       0x47 
#define   BATTERY_VOLTAGE_CMD   0x49 
#define   BATTERY_CURRENT_CMD   0x4b 
#define   IO_VOLTAGE_CMD        0x4d 
#define   IO_CURRENT_CMD        0x4b //IO_CURRENT_CMD  = 0x4f //test cournt batterie
#define   VALEUR_CHARGE_MIN     0


class Batterie : public I2C {
public:
    Batterie();
    virtual ~Batterie();
    int obtenirStatus();
    void resetStatus();
    unsigned char getChargingLevel();
    float getVoltage();
    short getAmperage();
    bool getInCharge();
    float getTemperature();
    short getCapacity();
    int niveauCharge();
private:
    unsigned char chargingLevel;
    float voltage;
    short amperage;
    bool inCharge;
    float temperature;
    short capacity;
    int obtenirNiveau();
    int obtenirCourant();
    int obtenirTemperature();
    int obtenirCharge();
    int obtenirTension();
    
};

#endif /* BATTERIE_H */
