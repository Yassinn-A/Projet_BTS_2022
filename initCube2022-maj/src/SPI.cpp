/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SPI.cpp
 * Author: linux
 * 
 * Created on 25 mars 2020, 23:05
 * Modified on avril 2022
 */

#include "../defs/SPI.h"

SPI::SPI() {
   //spi_cs0_fd = open("/dev/spidev0.0", O_RDWR);
}

SPI::SPI(const SPI& orig) {
}

SPI::~SPI() {
}

int SPI::ouvrirPortSpi(int spi_device)
{
    int status_value = -1;
    int *spi_cs_fd;
    spi_device = 0;
    spi_mode = SPI_MODE_1;
    spi_bitsPerWord = 8;
    spi_speed = 4000000;		
    spi_cs_fd = &spi_cs0_fd;
    //*spi_cs_fd = open("/dev/spidev0.0", O_RDWR);
	spi_cs0_fd = open("/dev/spidev0.0", O_RDWR);;
    return spi_cs0_fd;
}

int SPI::fermerPortSpi(int spi_device) 
{
    spi_device = 0;
    int status_value = -1;
    int *spi_cs_fd;
    spi_cs_fd = &spi_cs0_fd;
    status_value = close(*spi_cs_fd);
    return(status_value);
}

int SPI::ecrireSpi(int spi_device, uint8_t CMD[2],int Length) 
{
    spi_device = 0;
    struct spi_ioc_transfer spi;
    int i = 0;
    int retVal = -1;
    int spi_cs_fd;
    spi_cs_fd = spi_cs0_fd;
	memset(&spi, 0, sizeof(spi));
    spi.tx_buf = (unsigned long)CMD;		
	spi.rx_buf = (unsigned) NULL;
    spi.len = Length;
    spi.delay_usecs = 0;
    spi.speed_hz = spi_speed;
    spi.bits_per_word = spi_bitsPerWord;
    spi.cs_change = 0;		
    retVal = ioctl(spi_cs_fd, SPI_IOC_MESSAGE(1), &spi);
    return retVal;
}

int SPI::lireSpi(int spi_device,uint8_t CMD[1],uint8_t FLAG[1],int Length)
{
    spi_device = 0;
    struct spi_ioc_transfer spi[2];
    int i = 0;
    int retVal = -1;
    int spi_cs_fd;
    spi_cs_fd = spi_cs0_fd;	
	memset(&spi, 0, sizeof(spi));
	spi[0].tx_buf = (unsigned long) CMD;	
    spi[0].rx_buf = (unsigned )NULL;		
    spi[0].len = 1;
    spi[0].delay_usecs = 0;
    spi[0].speed_hz = spi_speed;
    spi[0].bits_per_word = spi_bitsPerWord;
    spi[0].cs_change = 0;	

	spi[1].tx_buf = (unsigned) NULL;	
    spi[1].rx_buf = (unsigned long )FLAG;		
    spi[1].len = Length;
    spi[1].delay_usecs = 0;
    spi[1].speed_hz = spi_speed;
    spi[1].bits_per_word = spi_bitsPerWord;
    spi[1].cs_change = 0;
    retVal = ioctl(spi_cs_fd, SPI_IOC_MESSAGE(2), &spi);
    return retVal;
}
