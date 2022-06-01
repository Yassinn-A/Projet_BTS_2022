/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mesure.cpp
 * Author: snir2g2
 * 
 * Created on 14 mars 2019, 17:40
 */

#include "../defs/Mesure.h"

Mesure::Mesure() {
    unit = "Celsius";
}

Mesure::~Mesure() {
}

Mesure::Mesure(float valeur){
    value = valeur;
}

Mesure::Mesure(char valeur){
    valuec = valeur;
}

void Mesure::setDateHour(string dateHour) {
    this->dateHour = dateHour;
}

string Mesure::getUnite() {
    return unit;
} 

void Mesure::setUnite(string theUnit){
	unit = theUnit;
}

string Mesure::getDateHour() {
    return dateHour;
}

float Mesure::getMesure() {
    return value;
}

char Mesure::getMesureC() {
    return valuec;
}

/// <summary> Cette méthode permet de recuperer la list de valeurs associée à une mesure de capteur.
/// </summary>
list<char>  Mesure::getDataListC(){
	return dataList;
}

void Mesure::addData(char aData){
	dataList.push_back (aData);
}
