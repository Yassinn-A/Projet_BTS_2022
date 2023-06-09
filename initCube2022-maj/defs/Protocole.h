/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Protocole.h
 * Author: snir2g2
 *
 * Created on 18 mars 2019, 08:36
 */

#ifndef PROTOCOLE_H
#define PROTOCOLE_H

#include <stdio.h>
#include <string>
#include <chrono>
#include <thread>
#include <list>
#include <vector>
#include <map>
#include <iterator>


#include "../defs/Message.h"
#include "../defs/TypeMisEtat.h"
#include "../defs/TypeAppareil.h"
#include "../defs/TypeCommande.h"
#include "../defs/TypeAck.h"
#include "Commande.h"

class Protocole : public TypeCommande, public TypeMisEtat, public TypeAppareil, public TypeAck {
public:
    Protocole();
    Protocole(const Protocole& orig);
    virtual ~Protocole();
    /**
     * accesseur au tableau de 100 octets � transmettre ou re�us
     */
    char *getTableau();
    int getNbrePaquets();
    int getNumPaquet();
    list<vector<char>> getReceived();
    /**
     * modificateur au tableau de 100 octets � transmettre ou re�us
     * compl�t� par des 0 si n�cessaire
     * 
     */
    void setTableau(char laDataRecu[100]);
    void setNbrePaquets(int n);
    void setNumPaquet(int n);
    /// <param name="arecu">M�thode permettant d'ajouter un paquet de donn�es � la liste des donn�es re�ues.</param>
    void addReceived(char recu [100]);
    void detramerMessage();

    /// <summary>
    /// m�thode d'extraction du code message dans le tableau d'octets re�us
    /// premi�re m�thode appel�e lors de la r�ception d'une salve.
    /// retourne le code message si OK
    /// retourne le code erreur ERR_CHECKSUM si probl�me de checksum
    /// retourne le code erreur ERR_FORMAT si la trame de commence pas par ~
    /// Le type Message est soit :
    /// -TypeCommande::MISSION
    /// -TypeCommande::MEASURE
    /// -TypeCommande::STATUS
    /// </summary>
    string extraireTypeMessage(int &pos);

    /// <summary>
    /// M�thode d'extraction du nombre de paquets et du num�ro de paquet.
    /// Compl�te les attributs correspondants de Protocole.
    /// </summary>
    /// <param name="apos">Position du dernier caract�re du code message.</param>
    void extraireNombrePaquets(int &pos);

    /// <summary>
    /// M�thode qui calcule le nombre de paquets dans une salve re�ue.
    /// </summary>
    int calculerNbrePaquetsSalve();

    /// <summary>
    /// M�thode d'extraction du type de donn�es dans le tableau d'octets re�us
    /// � ex�cuter apr�s extraireTypeMessage et test de la valeur de retour
    /// Le type de donn�es d�pend du type de message :
    /// Si TypeMessage = TypeCommande::MISSION, le type de donn�es est, pour cet incr�ment TypeMisEtat::TEMPCELSIUS.
    /// Si TypeMessage = TypeCommande::MEASURE, le type de donn�es peut �tre, pour cet incr�ment :
    /// - TypeMisEtat::TEMPCELSIUS,
    /// - TypeMisEtat::PIXEL.
    /// </summary>
    /// <param name="pos">position du type de donn�es de Mission</param>
    string extraireTypeDataMission(int &pos);

    /// M�thode d'extraction des donn�es d'une mission dans le tableau d'octets re�us
    /// � utiliser apr�s  extraireTypeDataMission
    /// <param name="datas"> liste des donn�es de la mission</param>
    /// <param name="dateHours"> liste des dates/heures de pr�l�vement</param>
    /// <param name="dateHours"> position des donn�es de Mission</param>
    int extraireDataMission(list<float> &datas, list<string> &dateHours, int &pos, string typeMission);

    /// M�thode permettant de supprimer le paquet trait� dans la liste des paquets
    /// recus
    /// Elle DOIT �tre utilis�e apr�s traitement du paquet.
    void supprimerPaquet();

    void envoieACK(string ACK);
    //thread tEnvoieACK(string ACK);

protected:
    /**
     * d�claration des constantes d'erreur
     */
    static string ERR_CHECKSUM;
    static string ERR_FORMAT;
    /**
     * d�claration de constantes protocole
     */
    static int pause;

    /**
     * nombre de paquets constituant l'information
     */
    int nbrePaquets;
    /**
     * num�ro du paquet v�hiculant l'information
     */
    int numPaquet;
    /**
     * tableau de 100 octets � transmettre (compl�t� par des 0)
     */
    char tableau[100];
    list<vector<char>> received;
	map <string,int> decoupePaquets;

    void calculerChecksum(char & PF, char & pf);
    bool verifierChecksum();
    void tramerMission(Message* message, int nbrePaquets, int numPaquet);
    void tramerStatus(Message* message, int nbrePaquets, int numPaquet);
    void tramerStatus(Message* message, list<string> appareils, int nbrePaquets, int numPaquet);
    void tramerMesure(Message* message, int nbrePaquets, int numPaquet);
    unsigned char calculerNombrePaquets(Message * message);
    void extraireCommande(char reception[]);
    void extraireParametres(char reception[]);
    /// Cette m�thode permet d'ajouter les donn�es de l'ordinateur de bord � la trame.
    /// </summary>
    /// <param name="aposition">Position o� doivent �tre ins�r�es les informations.</param>
    void ajouterDataOrdiBord(Message* amessage, unsigned int &aposition);

    /// <summary>
    /// Cette m�thode permet d'ajouter les donn�es de la batterie � la trame.
    /// </summary>
    /// <param name="aposition">Position o� doivent �tre ins�r�es les informations.</param>
    void ajouterDataBattery(Message* amessage, unsigned int &aposition);

    /// <summary>
    /// Cette m�thode permet d'ajouter les donn�es d'�tat de l'instrument � la trame.
    /// </summary>
    /// <param name="aposition">Position o� doivent �tre ins�r�es les informations.</param>
    void ajouterStatusInst(Message* amessage, unsigned int &aposition);

    /// <summary>
    /// Cette m�thode permet d'ajouter les donn�es de temp�rature du cube et de reboot (nombre et date du dernier) � la trame.
    /// </summary>
    /// <param name="amessage">Contenant des informations.</param>
    /// <param name="aposition">Position o� doivent �tre ins�r�es les informations.</param>
    void ajouterStatusCube(Message* amessage, unsigned int &aposition);

    void tramerMessageStart();
                
        
        Commande*commande= new Commande;
    //Commande* commande;
};

#endif /* PROTOCOLE_H */


