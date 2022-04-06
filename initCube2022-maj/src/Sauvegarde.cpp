/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sauvegarde.cpp
 * Author: Romain
 * 
 * Created on 23 juin 2020, 17:42
 */

#include <climits>
#include <sstream>
#include "../defs/Sauvegarde.h"

Sauvegarde::Sauvegarde() {
}

Sauvegarde::Sauvegarde(const Sauvegarde& orig) {
}

Sauvegarde::~Sauvegarde() {
}

bool Sauvegarde::creerSauvegarde(SegmentVol* segmentVol){
	 pugi::xml_document doc;
 
 auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version")    = "1.0";
    declarationNode.append_attribute("encoding")   = "ISO-8859-1";
    declarationNode.append_attribute("standalone") = "yes";
    pugi::xml_node Segment = doc.append_child("SegmentVol");
    pugi::xml_node Instrument = Segment.append_child("Instrument");
    if(pugi::xml_node Mission = Segment.append_child("Mission")){
		pugi::xml_attribute periodicity = Mission.append_attribute("periodicity");
		periodicity.set_value(segmentVol->getMission()->getPeriodicity());
    
		pugi::xml_attribute duration = Mission.append_attribute("duration");
		duration.set_value(segmentVol->getMission()->getDuration());
		pugi::xml_attribute date= Mission.append_attribute("date");
		date.set_value(segmentVol->getMission()->getStartTime().c_str());
		pugi::xml_attribute type_mesure=Mission.append_attribute("type__mesure");
		type_mesure.set_value(segmentVol->getMission()->getMeasureType().c_str());
    }
    if(pugi::xml_node Ordinateur_de_bord = Segment.append_child("Ordinateur_de_bord")){
		pugi::xml_node Reboot = Ordinateur_de_bord.append_child("Reboot");
		pugi::xml_attribute number = Reboot.append_attribute("number");
		number.set_value(segmentVol->getOrdinateur()->getReboot()->getNumber());
		pugi::xml_attribute dateHour = Reboot.append_attribute("dateHour");
		dateHour.set_value( (segmentVol->getOrdinateur()->getReboot()->getDateHour()).c_str());
		pugi::xml_node Batterie = Segment.append_child("Batterie");
	}
  
	 if(doc.save_file("Save.xml")){
		return true;
	 }
	 else return false;
}

bool Sauvegarde::chargerContexte(SegmentVol* segmentVol){
	pugi::xml_document doc;
	char xmlFile[] = "Save.xml";
	if (doc.load_file(xmlFile)) {
		pugi::xpath_node Mission = doc.select_node("//SegmentVol/Mission");
		string theDataRead = Mission.node().attribute("periodicity").value();
        istringstream iss(theDataRead);
		int theData;
		iss>>theData;
		segmentVol->getMission()->setPeriodicity(theData);
		theDataRead = Mission.node().attribute("duration").value();
		iss = istringstream(theDataRead);
		iss>>theData;
		segmentVol->getMission()->setDuration(theData);
		theDataRead = Mission.node().attribute("date").value();
		segmentVol->getMission()->setStartTime(theDataRead);
		theDataRead = Mission.node().attribute("type__mesure").value();
		segmentVol->getMission()->setMeasureType(theDataRead);


		pugi::xpath_node Reboot = doc.select_node("//SegmentVol/Ordinateur_de_bord/Reboot");
		theDataRead = Reboot.node().attribute("number").value();
        iss = istringstream(theDataRead);
		iss>>theData;
		segmentVol->getOrdinateur()->getReboot()->setNumber(theData);
		theDataRead = Reboot.node().attribute("dateHour").value();
		segmentVol->getOrdinateur()->getReboot()->setDateHour(theDataRead);

		supprimerSaugegarde();
		return true;
	}

	else return false;
}
bool Sauvegarde::supprimerSaugegarde(){
	if( remove( "Save.xml" ) != 0 )
		return false;
	 else
		return true;
}

bool Sauvegarde::enregistrerMesures(list<Mesure *> lesMesures) { // initialement prévu : bool Sauvegarde::enregistrerMesure(Mesure mesure);
	this->lesMesures = lesMesures;
    pugi::xml_document doc;
    char commandeCreer[256];
    char xmlFile[] = "Save.xml";
    sprintf(commandeCreer, "touch %s", xmlFile);
	list<Mesure*>::iterator it = lesMesures.begin();
    if (doc.load_file(xmlFile)) {
		pugi::xpath_node leSegment = doc.select_node("//SegmentVol");
		pugi::xml_node lInstrument = leSegment.node().child("Instrument");
		if (!lesMesures.empty())
		{
			int i =0;
			for (it=lesMesures.begin();it!=lesMesures.end();it++)
			{
				i++;
				pugi::xml_node uneMesure = lInstrument.append_child("Mesure");
				pugi::xml_attribute laValeur =  uneMesure.append_attribute("id");
				laValeur.set_value(i);
			}

			doc.save_file(xmlFile);
		}
        return true;
    } else {
        return false;
    }
}

bool Sauvegarde::ajouterAMission() { // initialement prévu : bool Sauvegarde::ajouterAMission(Mesure mesure);
    return 0;
}

unsigned char Sauvegarde::lireID() {
    pugi::xml_document doc;
    char xmlFile[] = "../config/initcube.xml";
    unsigned char cubeId;
    if (doc.load_file(xmlFile)) {
        pugi::xpath_node nodeId = doc.select_node("//initcube/description/id");
        string intermediateId = nodeId.node().child_value();
        istringstream iss(intermediateId);
        int nb;
        iss >> nb;
        cubeId = (unsigned char) nb;
    } else {
        cubeId = 0;
    }
    return cubeId;
}