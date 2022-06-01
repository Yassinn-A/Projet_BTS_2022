/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CameraPhoto.cpp
 * Author: Yanis
 * 
 * Created on 11 mars 2020, 14:24
 */

#include "../defs/CameraPhoto.h"

CameraPhoto::CameraPhoto() {
    this -> address = 0x30;
}

CameraPhoto::CameraPhoto(const CameraPhoto& orig) {
}

CameraPhoto::~CameraPhoto() {
}

void CameraPhoto::activer() {
	
    setAddrRegistre(DEVICECONTROL);
    ecrire(BANK2);
    setAddrRegistre(COM7);
    ecrire(SRST);
    //setAddrRegistre(0x09);
    //ecrire(0);
}

void CameraPhoto::desactiver() {
    setAddrRegistre(DEVICECONTROL);
    ecrire(BANK2);
    setAddrRegistre(0x09);
    ecrire(1);
}

void CameraPhoto::configResolution() {

    configurer(OV2640_JPEG_INIT);
	usleep(20000);
    configurer(OV2640_YUV422);
	usleep(20000);
    configurer(OV2640_JPEG);
	usleep(20000);
    setAddrRegistre(DEVICECONTROL);
    ecrire(BANK2);
	usleep(20000);
    setAddrRegistre(COM10);
    ecrire(PCLK_RST);
	usleep(20000);
    configurer(OV2640_320x240_JPEG);
}

int CameraPhoto::configurer(const sensor_reg reglist[]) {
    int err = 0;
    unsigned int reg_addr = 0;
    unsigned int reg_val = 0;
    const struct sensor_reg *next = reglist;
    while ((reg_addr != 0xff) | (reg_val != 0xff)) {
        reg_addr = next->reg;
        reg_val = next->val;
        setAddrRegistre(reg_addr);
        err = ecrire(reg_val);
        usleep(20000);
        next++;
    }
    return err;
}

void CameraPhoto::lancer_capture() {
    uint8_t CMD[2];
    CMD[0] = ARDUCHIP_FIFO | 0x80;
    CMD[1] = FIFO_CLEAR_MASK;
    ecrireSpi(0, CMD, 2);
	usleep(10000);
    CMD[0] = ARDUCHIP_FIFO | 0x80;
    CMD[1] = FIFO_START_MASK;
    ecrireSpi(0, CMD, 2);
	usleep(10000);
    verify_com();
}

int CameraPhoto::enregistrerJPEG() {
    ofstream file;
	time_t rawtime;
    tm * timeinfo;
    char buffer [16];

    time (&rawtime);
    timeinfo = localtime (&rawtime);
	strftime (buffer,16,"image%H%M%S.jpg",timeinfo);

	string filename = buffer;
	const char* leFichier = filename.c_str();
    file.open(leFichier, ios::out);
    if (!file) {
        return -1;
    }

    file.write(readbuf, taille);
    file.close();
    return 0;
}

int CameraPhoto::supprimerJPEG() {
	char cmd[50];
	strcpy(cmd,"rm *.jpg");
	system(cmd);
	return 0;
}

void CameraPhoto::prendrePhoto() {
    this ->ouvrirPortSpi(0);
	Arducam_bus_detect();
    uint8_t CMD[2];
    CMD[0] = 0x07 | 0x80;
    CMD[1] = 0x80;
    int err = ecrireSpi(0, CMD, 2);
	usleep(10000);
    CMD[0] = 0x07 | 0x80;
    CMD[1] = 0x00;
    ecrireSpi(0, CMD, 2);
	usleep(10000);
	this ->activer();
	usleep(1000);
    this ->configResolution();
	configurer(OV2640_320x240_JPEG);
    this ->lancer_capture();
    this ->retrieveIMG();
	usleep(10000);
	this->desactiver();
    //this ->enregistrerJPEG();
	this->fermerPortSpi(0);
}

void CameraPhoto::retrieveIMG() {
    uint8_t CMD[1];
    uint8_t FLAG[1];
    uint8_t image[JPEG_BUF_SIZE];
	Mesure* uneMesure = new Mesure();

    unsigned int len1, len2, len3, count = 0;


	time_t rawtime;
    tm * timeinfo;
    char buffer [16];

    time (&rawtime);
    timeinfo = localtime (&rawtime);
	strftime (buffer,16,"image%H%M%S.jpg",timeinfo);
	std::string str(buffer);

	//Récupération taille réelle image

    CMD[0] = FIFO_SIZE1;
    lireSpi(0, CMD, FLAG, 1);
    len1 = FLAG[0];

    CMD[0] = FIFO_SIZE2;
    lireSpi(0, CMD, FLAG, 1);
    len2 = FLAG[0];

    CMD[0] = FIFO_SIZE3;
    lireSpi(0, CMD, FLAG, 1);
    len3 = FLAG[0];

    count = ((len3 << 16) | (len2 << 8) | len1) & 0x07fffff;
    taille= count;

    //CMD[0]=BURST_FIFO_READ;
    CMD[0] = SINGLE_FIFO_READ;

    for (int i = 0; i < count; i++) {

        lireSpi(0, CMD, FLAG, 1);

        image[i] = FLAG[0];
        readbuf[i] = image[i];
		//////////// Ajout d'une donnée à la mesure //////////////
		uneMesure->setUnite("-IMG");
		uneMesure->addData(readbuf[i]);
    }
	this->addMesure(uneMesure);
    fermerPortSpi(0);
}

void CameraPhoto::verify_com() {
    uint8_t CMD[1];
    uint8_t FLAG[1];
    FLAG[0] = 0;
    CMD[0] = ARDUCHIP_TRIG;
    do {
        //ecrireSpi(0,CMD,1);
        lireSpi(0, CMD, FLAG, 1);
        usleep(10000);
    } while ((FLAG[0] & 0x8) != 0x8);
}

void CameraPhoto::Arducam_bus_detect(){
	unsigned char vid, pid,temp ;
	uint8_t CMD[2];
	uint8_t CMD2[1];
	uint8_t FLAG[1];
	char * theIDs;

	do {  	


		CMD[0] = ARDUCHIP_TEST1 | 0x80;
		CMD[1] = 0x55;
		int err = ecrireSpi(0, CMD, 2);

		FLAG[0] = 0;
		CMD2[0] = ARDUCHIP_TEST1;
        lireSpi(0, CMD2, FLAG, 1);

 		if (FLAG[0]  != 0x55){
			sleep(1);
  		}
	}	while (FLAG[0]  != 0x55);

	do {
		setAddrRegistre(0xff);
		ecrire(0x01);
		setAddrRegistre(OV2640_CHIPID_HIGH);
		ecrire();
		theIDs = lire();
		vid = theIDs[0];
		pid = theIDs[1];

	}  while((vid != 0x26 ) && (( pid != 0x41 ) || ( pid != 0x42 )));
}

char CameraPhoto::getPhoto(char photo[JPEG_BUF_SIZE]) {
    for (int i=0; i<JPEG_BUF_SIZE; i++){
        photo[i] = readbuf[i];
    }
    return 0;
}

int CameraPhoto::getTaille() {
    return taille;
}
