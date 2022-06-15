#ifndef INSTRUMENTX_H
#define INSTRUMENTX_H

#include <list>
#include "Instrument.h"
#include "I2C.h"
#include "Configuration.hpp"

using namespace std;

class InstrumentX : public Instrument, public I2C{
public:

    InstrumentX();

    InstrumentX(const Instrument& orig);
	
    virtual ~InstrumentX();

	/// <summary>
	/// Cette m�thode permet d'activer l'instrument avant toute mesure ou pr�l�vement de donn�es.
	/// </summary>
    void activer();

	/// <summary>
	/// Cette m�thode permet de d�sactiver l'instrument quand il n'est pas utile afin d'�conomiser de l'�nergie.
	/// </summary>
    virtual void desactiver();

	void repos();

	void resetStatus();

	void envoyerTrame();

	void setCheminConfig(const char * cheminConfig);

	virtual int faireMesure(char arg = -1);
    virtual float* obtenirMesure();

	unsigned char * listToTab2(list<int> liste);
	void listToTab(list<int> liste, unsigned char tableau[128]);
	int tailleTab2(unsigned char * tab);

	int lireAdresseI2C();

	int lireNombre_bypass();
	int lireAdresse_bypass();

	int lireNombre_activation();
	list<int> lireAdresse_activation();

	int lireNombre_desactivation();
	list<int> lireAdresse_desactivation();

	int lireNombre_repos();
	list<int> lireAdresse_repos();

	int lireNombre_realisation();
	list<int> lireAdresse_realisation();

	int lireNombre_recuperation();
	list<int> lireAdresse_recuperation();

private:

	pugi::xml_document doc;
	const char * chemin_config;

	int adresse_I2C;

	int nombre_ByPass;
	int adresse_ByPass;

	int nombre_activation;
	list<int> adresse_activation;

	int nombre_desactivation;
	list<int> adresse_desactivation;

	int nombre_repos;
	list<int> adresse_repos;

	int nombre_realisation;
	list<int> adresse_realisation;

	int nombre_recuperation;
	list<int> adresse_recuperation;
	
	char mode_survie;
	char particules_energie;

    
protected:
	void obtenirTempInst();
	void obtenirMode();
	/// <summary>
	/// Cette m�thode envoie une requ�te � l'instrument pour conna�tre son mode de fonctionnement. (Normal, sommeil etc.)
	/// </summary>
    //virtual void obtenirMode()=0;   
	/// <summary>
	/// Cette m�thode envoie une requ�te � l'instrument pour r�cup�rer sa temp�rature interne.
	/// Remarque : Si l'instrument est dans l'�tat SLEEP, il se peut que la temp�rature soit nulle.
	/// </summary>   
    //virtual void obtenirTempInst()=0;     

    Status* status;
	Configuration * configuration;
    list<Mesure*> listedemesures;
};

#endif /* INSTRUMENTX_H */


