/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mesure.h
 * Author: snir2g2
 *
 * Created on 14 mars 2019, 17:40
 */

#ifndef MESURE_H
#define MESURE_H
#include <string>
#include <list>
#include <iostream>
using namespace std;

class Mesure {
public:
    Mesure();
    Mesure(float valeur);
	Mesure(char valeur);

	virtual ~Mesure();
	/// <summary> Cette méthode permet de modifier la date et l'eheure de la mesure.
	/// <param> string dateHour : date et heure de mesure
	/// </summary>
    void setDateHour(string dateHour);
    string getUnite();
	/// <summary> Cette méthode permet de modifier une information de mesure
	/// <para> string theUnit : chaine de caractere a associer a la Mesure
	/// </summary>
    void setUnite(string theUnit);
	/// <summary> Cette méthode permet de recuperer la valeur de Mesure de type float.
	/// </summary>
    float getMesure();

	/// <summary> Cette méthode permet de recuperer la valeur de Mesure de type char.
	/// </summary>
	char getMesureC();

	/// <summary> Cette méthode permet de recuperer la list de valeurs associée à une mesure de capteur.
	/// </summary>
	list<char>  getDataListC();

    string getDateHour();
	/// <summary> Cette méthode permet d'ajouter une donnée à la liste de données d'une mesure.
	/// Les données sont au format char. Une donnée peut être constituée de plusieurs char.
	/// La gestion se fera, alors, en BigEndian.
	/// <param> char aData : 1 octet d'une donnée
	/// </summary>
	void addData(char aData);
private:
    float value;
    char valuec;
	list<char> dataList;
    string dateHour;
    string unit;

};

#endif /* MESURE_H */
