/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: snir2g1
 *
 * Created on 14 février 2022, 17:41
 */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <iostream>
#include <math.h>
#include <sys/ioctl.h>

using namespace std;


int main(void)
{
        unsigned char buf[4];
        int fd;
        ssize_t fd2;
        fd = open("/dev/i2c-1",O_RDWR);
        int addr = 0x14;        
        ioctl(fd, I2C_SLAVE, addr);
        //Ligne 1 : trame 1
        buf[0] =0xC2 ;
        if (write(fd, buf, 1) != 1) {
        }
        fd2 = read(fd,buf,3);
        //Ligne 1: trame 2
        buf[0]=0xC2;
        buf[1]=0x25;
        buf[2]=0x01;
        buf[3]=0xDB;
        if (write(fd, buf, 4) !=4){
		}	
		//Ligne 1 : trame 3
		buf[0]=0xC2;
		if (write(fd, buf, 1) != 1) {
        }
        fd2 = read(fd,buf,3);
        //Ligne 2: trame 1
        buf[0]=0x63;
        buf[1]=0x00;
        buf[2]=0xFF;
        if (write(fd, buf, 3) !=3){
		}
		//Ligne 2 : trame 2
		buf[0] =0x63 ;
        if (write(fd, buf, 1) != 1) {
        }
        fd2 = read(fd,buf,2);
        //Ligne 3
        buf[0]=0x64;
        buf[1]=0x00;
        buf[2]=0xFF;
        if (write(fd, buf, 3) !=3){
		}
		//Ligne 4
		buf[0]=0x62;
        buf[1]=0x05;
        buf[2]=0xFA;
        if (write(fd, buf, 3) !=3){
		}
		//Ligne pour quitter le terminal
		system("sudo shutdown -h now");
}
