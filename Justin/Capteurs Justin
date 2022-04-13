#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>
#include <linux/i2c-dev.h>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <list>
#include <iterator>
#include <sstream>
#include <math.h>

using namespace std;

unsigned char ADC_DEFAULT_IIC_ADDR = 0X04;//adresse par défaut

unsigned char CANAL_CAPT1 = 0;//numéro canal
unsigned char CANAL_CAPT2 = 1;//numéro canal

unsigned char REG_RAW_DATA_START = 0X10;//registre données du début
unsigned char REG_VOL_START = 0X20;//registre voltage du début
unsigned char REG_RTO_START = 0X30;//registre ratio du début

unsigned char REG_SET_ADDR = 0XC0;//registre modifier l'adresse

int main()
{

    int fd = 1;//indice du fichier
        char valeur1[5]; //Tableau taille 5
        char valeur2[5]; //Tableau taille 5
        unsigned char address = ADC_DEFAULT_IIC_ADDR;
        unsigned char addrRegistre1= REG_RAW_DATA_START + CANAL_CAPT1;
        unsigned char addrRegistre2= REG_RAW_DATA_START + CANAL_CAPT2;
    fd = open("/dev/i2c-1", O_RDWR);//ouvrir le fichier avec les droits
        ioctl(fd, I2C_SLAVE, address);//appel d'entrées/sorties
        write(fd, &addrRegistre1, 1);//écrire addrRegistre taille 1 char
        write(fd, &addrRegistre2, 1);//écrire addrRegistre taille 1 char
        int ret1 = read(fd, valeur1, 2);//lire valeur taille 2 char
        int ret2 = read(fd, valeur2, 2);//lire valeur taille 2 char
        cout<<"Nbre valeurs lues = "<<ret1<<endl;//affiche Nbre valeurs lues
        cout<<"Nbre valeurs lues = "<<ret2<<endl;//affiche Nbre valeurs lues
        cout<<"Valeur lue = "<<(int)valeur1[0]<<" "<<(int)valeur1[1]<<endl;//affiche Valeur lue de la premiere case du tableau et la deuxieme case du tableau
        cout<<"Valeur lue = "<<(int)valeur2[0]<<" "<<(int)valeur2[1]<<endl;//affiche Valeur lue de la premiere case du tableau et la deuxieme case du tableau
        return 0;
}
