#include <cstdlib>
#include <iostream>
#include "../initCube2022-maj/defs/serialib.h"
#include <fstream>
#define JPEG_BUF_SIZE 320*240
#include "../initCube2022-maj/defs/I2C.h"

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
    commande[14]= '2';
    commande[15]= '1';
    commande[16]= '3';
    commande[17]= '4';
    commande[18]= '9';
    commande[19]= ' ';
    commande[20]= '8';
    commande[21]= '3';
    commande[22]= ' ';
    char monTableau[JPEG_BUF_SIZE];
    ifstream file;
      file.open("jpg.jpg",ios::in);
	  if(!file)
    {
      cout<<"Erreur fichier.."<<endl;
      return 0;
    }
    cout<<"\nFichier OK !."<<endl;
    file.read(monTableau,21349);
    for(int i = 0; i<21349;i++){
        cout<<(int)(unsigned char) monTableau[i]<<"/";
    }
    perror("");
    file.close();  
    cout<<"\nFichier sauvé et fermé !."<<endl;
    

  for (int i = 0; i < commande[1] + 2; i++) {
      Checksum = Checksum^commande[i];
  }
  sprintf(leChecksum, "%2X", Checksum);
  if (leChecksum[0] == 32) leChecksum[0] = '0';
  if (leChecksum[1] == 32) leChecksum[1] = '0';
  commande [23] = leChecksum[0];
  commande [24] = leChecksum[1];  
  commande [25] = 255;

    
    int retour = toto.Open("/dev/ttyUSB1",9600);
        toto.Write(commande,26); 
    
    int taille =21349;
     
    
    
  indiceEnCours=0;
    int i;
    int r=0;
    do {
         for (i=indiceEnCours;i<indiceEnCours + 98; i++) {
              trameEmission[i-indiceEnCours]=monTableau[i];
         } // colonne tableau concérnée
            indiceEnCours = i; // incrémentation de la colonne 

            Checksum = 0;
            for ( int j = 0; j < 98; j++) { //
                Checksum = Checksum^trameEmission[j]; // checksum du trameEmission concerné
            }
            sprintf(leChecksum, "%2X", Checksum);
            if (leChecksum[0] == 32) leChecksum[0] = '0';// si il y a un espace (32 en ascii) il faut le rempalacr par 0
            if (leChecksum[1] == 32) leChecksum[1] = '0';// si il y a un espace (32 en ascii) il faut le rempalacr par 0
            trameEmission [98] = leChecksum[0]; // la colonne 0 de "lecheksum" correspond a la colonne 98 de "TrameEmission"
            trameEmission [99] = leChecksum[1];// la colonne 1 de "lecheksum" correspond a la colonne 99 de "TrameEmission"
            r++;
            toto.Write(trameEmission, 100);
            for(int i=0; i<100; i++){
                cout<<(int)(unsigned char)trameEmission[i]<<"/";
            }// l'objet toto envoir trame emission de la taille 100 dans le canal serial
            cout<<endl<<"trame "<<r<<endl;
            usleep(500000);
                                                                           
        } while (indiceEnCours < taille - 98); // car si la trame est inferieure à 98 c'est la derniere qui est la seule a etre inferieure a 98 et comme taille -1 -98 = 99
        
        
        for (i=indiceEnCours; i<taille;i++){   
              trameEmission[i-indiceEnCours]=monTableau[i];// colonne tableau concérnée
        }     

            Checksum = 0;
            for (int i = 0; i < 83; i++) { //
                Checksum = Checksum^trameEmission[i]; // checksum du trameEmission concerné
            }
            sprintf(leChecksum, "%2X", Checksum);
            if (leChecksum[0] == 32) leChecksum[0] = '0';// si il y a un espace (32 en ascii) il faut le rempalacr par 0
            if (leChecksum[1] == 32) leChecksum[1] = '0'; // si il y a un espace (32 en ascii) il faut le rempalacr par 0
        trameEmission [83] = leChecksum[0]; // la colonne 0 de "lecheksum" correspond a la colonne 98 de "TrameEmission"
        trameEmission [84] = leChecksum[1]; // la colonne 1 de "lecheksum" correspond a la colonne 99 de "TrameEmission"

        toto.Write(trameEmission, 85); // l'objet toto envoir trame emission de la taille 100 dans le canal serial

        
    return 0;
}