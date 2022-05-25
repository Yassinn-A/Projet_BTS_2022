#ifndef SEGMENTVOL_H
#define SEGMENTVOL_H
#include <thread>
#include <mutex>
#include "../defs/Batterie.h"
#include "../defs/Moteur.h"
#include "../defs/Soleil.h"


class SegmentVol {
public:
    SegmentVol();
    void orientation();
    void lancement();
    std::thread torientation();
    std::thread tlancement();
    virtual ~SegmentVol();
private:
    Soleil* soleil;
    Batterie* batterie;
    Moteur* moteur;
};

#endif /* SEGMENTVOL_H */
