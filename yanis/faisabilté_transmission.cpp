#include <cstdlib>
#include <iostream>
#include "./defs/serialib.h"
#include "../CameraPhoto/defs/CameraPhoto.h"

using namespace std;

/*
 * 
 */
int main() {
    bool finish =false;
    short Checksum = 0;
    char leChecksum[2];
    int indiceEnCours;
    char trameEmission[100];
    serialib toto;
    char commande [128];
    commande[0]= 1;
    commande[1]= 21;
    commande[2]= 'M';
    commande[3]= 'E';
    commande[4]= 'A';
    commande[5]= 'S';
    commande[6]= 'U';
    commande[7]= 'R';
    commande[8]= 'E';
    commande[9]= '-';
    commande[10]= 'I';
    commande[11]= 'M';
    commande[12]= 'G';
    commande[13]= ' ';
    commande[14]= '1';
    commande[15]= '2';
    commande[16]= '2';
    commande[17]= '9';
    commande[18]= '6';
    commande[19]= ' ';
    commande[20]= '4';
    commande[21]= '6';
    commande[22]= ' ';
    


  for (int i = 0; i < commande[1] + 2; i++) {
      Checksum = Checksum^commande[i];
  }
  sprintf(leChecksum, "%2X", Checksum);
  if (leChecksum[0] == 32) leChecksum[0] = '0';
  if (leChecksum[1] == 32) leChecksum[1] = '0';
  commande [23] = leChecksum[0];
  commande [24] = leChecksum[1];  
  commande [25] = 255;

    
    int retour = toto.Open("/dev/serial0",9600);
        toto.Write(commande,100); 
   

    CameraPhoto* laCamera = new CameraPhoto();

    char monTableau[JPEG_BUF_SIZE];

    laCamera->activer();

    laCamera->prendrePhoto();

    laCamera->desactiver();

    laCamera->getPhoto(monTableau);
    
    int taille = laCamera->getTaille();
     
    
    
  indiceEnCours=0;
    int i;
    
    do {
         for (i=indiceEnCours; i<indiceEnCours,i<indiceEnCours + 98; i++) {
              trameEmission[i-indiceEnCours]=monTableau[i];} // colonne tableau concérnée
            indiceEnCours = i+1; // incrémentation de la colonne 

            Checksum = 0;
            for ( i = 0; i < trameEmission[1] + 2; i++) { //
                Checksum = Checksum^trameEmission[i]; // checksum du trameEmission concerné
            }
            sprintf(leChecksum, "%2X", Checksum);
            if (leChecksum[0] == 32) leChecksum[0] = '0';// si il y a un espace (32 en ascii) il faut le rempalacr par 0
            if (leChecksum[1] == 32) leChecksum[1] = '0';// si il y a un espace (32 en ascii) il faut le rempalacr par 0
            trameEmission [98] = leChecksum[0]; // la colonne 0 de "lecheksum" correspond a la colonne 98 de "TrameEmission"
            trameEmission [99] = leChecksum[1];// la colonne 1 de "lecheksum" correspond a la colonne 99 de "TrameEmission"
            
            toto.Write(trameEmission, 100); // l'objet toto envoir trame emission de la taille 100 dans le canal serial

                                                                           
        } while (indiceEnCours < taille - 99); // car si la trame est inferieure à 98 c'est la derniere qui est la seule a etre inferieure a 98 et comme taille -1 -98 = 99
        
        
        for (i=indiceEnCours; i<taille-1;i++){   
                 for (i=indiceEnCours; i<indiceEnCours,i<indiceEnCours + 98; i++) {
              trameEmission[i-indiceEnCours]=monTableau[i];} // colonne tableau concérnée
                 

            Checksum = 0;
            for (int i = 0; i < trameEmission[1] + 2; i++) { //
                Checksum = Checksum^trameEmission[i]; // checksum du trameEmission concerné
            }
            sprintf(leChecksum, "%2X", Checksum);
            if (leChecksum[0] == 32) leChecksum[0] = '0';// si il y a un espace (32 en ascii) il faut le rempalacr par 0
            if (leChecksum[1] == 32) leChecksum[1] = '0'; // si il y a un espace (32 en ascii) il faut le rempalacr par 0
        trameEmission [taille - indiceEnCours] = leChecksum[0]; // la colonne 0 de "lecheksum" correspond a la colonne 98 de "TrameEmission"
        trameEmission [taille - indiceEnCours + 1] = leChecksum[1]; // la colonne 1 de "lecheksum" correspond a la colonne 99 de "TrameEmission"

        toto.Write(trameEmission, taille - indiceEnCours + 2); // l'objet toto envoir trame emission de la taille 100 dans le canal serial

    }

    Checksum = 0;
    for (int i = 0; i < trameEmission[1] + 2; i++) {
        Checksum = Checksum^trameEmission[i];
    }
    sprintf(leChecksum, "%2X", Checksum);
    if (leChecksum[0] == 32) leChecksum[0] = '0';
    if (leChecksum[1] == 32) leChecksum[1] = '0';
    trameEmission [23] = leChecksum[0];
    trameEmission [24] = leChecksum[1];
    toto.WriteString(trameEmission);

    return 0;
}

