/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CameraPhoto.h
 * Author: Yanis
 *
 * Created on 11 mars 2020, 14:24
 */

#ifndef CAMERAPHOTO_H
#define CAMERAPHOTO_H

#include "I2C.h"
#include "Instrument.h"
#include "ov2640_regs.h"
#include "SPI.h"
#include <fstream>
#include <ctime>

#define ARDUCHIP_TEST1          0x00
#define ARDUCHIP_TRIG      		0x41
#define ARDUCHIP_FRAMES         0x01
#define ARDUCHIP_MODE           0x02
#define MCU2LCD_MODE            0x00
#define CAM2LCD_MODE            0x01
#define LCD2MCU_MODE            0x02
#define LOW_POWER_MODE          0x40 //0 = Normal mode,1 = Low power mode
#define ARDUCHIP_TIM            0x03
#define HREF_LEVEL_MASK    		0x01 
#define VSYNC_LEVEL_MASK   		0x02  
#define LCD_BKEN_MASK      		0x04
#define ARDUCHIP_FIFO      		0x04
#define FIFO_CLEAR_MASK    		0x01
#define FIFO_START_MASK    		0x02
#define FIFO_RDPTR_RST_MASK             0x10
#define FIFO_WRPTR_RST_MASK             0x20
#define ARDUCHIP_GPIO			0x06 
#define GPIO_RESET_MASK			0x01  						
#define GPIO_PWDN_MASK			0x02 
#define GPIO_PWREN_MASK			0x04
#define BURST_FIFO_READ			0x3C
#define SINGLE_FIFO_READ		0x3D 
#define FIFO_SIZE1			0x42
#define FIFO_SIZE2			0x43
#define FIFO_SIZE3			0x44
#define DEVICECONTROL                   0xff
#define BANK1                           0x00
#define BANK2                           0x01
#define COM7							0x12
#define SRST							0x80
#define COM10							0x15
#define PCLK_RST						0x00
#define CMD_BUF_SIZE 512
#define JPEG_BUF_SIZE 2*1024*1024 //320*240

using namespace std;

class CameraPhoto : public Instrument, public I2C, public SPI {
public:
    CameraPhoto();
    CameraPhoto(const CameraPhoto& orig);
    virtual ~CameraPhoto();
	/// <summary> Cette méthode est héritéé d'Instrument et permet d'activer la caméra.
	/// </summary>
    void activer();
	/// <summary> Cette méthode permet de capturer une photo. Le résultat obtenu est un tableau d'octets.
	/// </summary>
    void prendrePhoto();
    void desactiver();
    char getPhoto(char photo[JPEG_BUF_SIZE]); 
    int getTaille();
	/// <summary> Cette méthode permet d'enregistrer la photo au format jpg avec un nom au format imageHHMMSS.jpg
	/// Elle sera appelée lorsque la commande contiendra le code clé -SAVE.
	/// </summary>
    int enregistrerJPEG();
	/// <summary> Cette méthode permet de supprimer tous les fichiers au format *.jpg
	/// </summary>
	int supprimerJPEG();

	int faireMesure(char arg = -1); ////////
    float* obtenirMesure();////////////
    
private:
	void Arducam_bus_detect();
    void configResolution();
    int configurer(const struct sensor_reg reglist[]);
    void retrieveIMG();
    void lancer_capture();
    void verify_com();
    char readbuf[JPEG_BUF_SIZE];
    int taille;
    
};

#endif /* CAMERAPHOTO_H */



