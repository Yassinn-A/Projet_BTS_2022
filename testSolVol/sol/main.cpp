#include <cstdlib>
#include <iostream>
#include "../initCube2022-maj/defs/serialib.h"
#define JPEG_BUF_SIZE 320*240
#include <iostream>
#include<string>
#include<sstream>

using namespace std;

/*
 * 
 */
int main() {
    serialib toto;
    char bufferRcpt[128];
    char monTableau[JPEG_BUF_SIZE];

    int retour = toto.Open("/dev/ttyUSB0", 9600);
    int taille = toto.ReadString(bufferRcpt, 255, 100);

    string laTrame = string(bufferRcpt, bufferRcpt[1]);
    cout << laTrame << endl;
    std::size_t found = laTrame.find(" "); //va servir a trouver le premier espace
    cout << found << " indice du premier espace " << endl;
    size_t position_deuxieme = laTrame.find(" ", 13 + 1); // position_deuxieme correspond a l'endroit 
    cout << position_deuxieme << " indice du deuxieme espace " << endl;
    string nbOctetImage = laTrame.substr(13, position_deuxieme - 13); // c'est la position entre la case 13 et la prochaine position 
    cout << nbOctetImage << " nombre d'octets de l'image dans la trame " << endl;
    cout << taille << " taille de la trame" << endl;



    // calcule nbr de trames
    stringstream ss;
    int num;
    ss << nbOctetImage;
    ss >> num;
    bool reste;
    int nombre_de_trames;
    int res = num % 98;
    if (res == 0) {
        nombre_de_trames = num / 98;
        reste = false;
    } else {
        nombre_de_trames = (num / 98) + 1;
        reste = true;
    }
    cout << "nombre de trames "<<nombre_de_trames << endl;
    
    int nbr=0;
    if(reste==true){
        for (int j = 0; j < nombre_de_trames-1; j++){
            unsigned int nombre = toto.Read(bufferRcpt, 100);
            //for (int i = 0; i < 98; i++) {
                //monTableau[i] = bufferRcpt[i];
            //}
            cout<<"Trame n "<<j+1<<endl;
            nbr = j+1;
        }
        unsigned int nombre = toto.Read(bufferRcpt, 100);
        //for (int j = 0; j<res;j++) {
            //monTableau[i] = bufferRcpt[i];
        //}
            cout<<"Trame n "<<nbr+1<<endl;
    }
    else{
       for (int j = 0; j < nombre_de_trames; j++){
        unsigned int nombre = toto.Read(bufferRcpt, 100);
        //for (int i = 0; i < 98; i++) {
            //monTableau[i] = bufferRcpt[i];
        //}
        cout<<"Trame n "<<j+1<<endl; 
        }
    }

    return 0;
}

