/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Protecteur.h
 * Author: snir2g1
 *
 * Created on 06 avril 2022, 15:30
 */

#ifndef PROTECTEUR_H
#define PROTECTEUR_H

#include "SegmentVol.h"
using namespace std;

class SegmentVol;

class Protecteur {
public:
    Protecteur(SegmentVol *leSegment);
    virtual ~Protecteur();
    void rebootSave();
    SegmentVol* leSegment;

private:

};

#endif /* PROTECTEUR_H */