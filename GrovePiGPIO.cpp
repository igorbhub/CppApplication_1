/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GrovePiGPIO.cpp
 * Author: igor
 * 
 * Created on 27 January 2016, 12:43 PM
 */

#include <iostream>
#include "GrovePiModule.h"
#include "GrovePi.h"
#include "GrovePiGPIO.h"


GrovePiGPIO::GrovePiGPIO(int const pin, GrovePi const &grove)
    : GrovePiModule(grove), pinNo(pin)
{
    setPinMode(GrovePiGPIO::IOMODE_output);
}


GrovePiGPIO::~GrovePiGPIO() {
}

int const
GrovePiGPIO::getPinNo(void) const {
    return pinNo;
}

void
GrovePiGPIO::setPinMode(int const pinMode) throw() {
    std::cout << "setting up the pin's i/o mode" << std::endl;
    int const bufLen = 5;
    unsigned char buf[5];
    buf[0] = 0x01; // Dummy1
    buf[1] = COMMAND_pMode; // Grove command pMode_cmd=5
    buf[2] = pinNo; // pin number
    buf[3] = pinMode; //IOMODE_output
    buf[4] = 0x00; // Dummy
    
    grove.sendBuf(buf, bufLen);
}

void
GrovePiGPIO::setPinState(int const onOff) throw(){
    //std::cout << "changing pin " << pinNo << " state to " << onOff << std::endl;
    int const bufLen = 5;
    unsigned char buf[5];
    buf[0] = 0x01; // Dummy1
    buf[1] = GrovePiGPIO::COMMAND_dWrite; // Grove command 1=Read; dWrite_cmd=2
    buf[2] = pinNo; // Pin number
    buf[3] = onOff; // pin state 1=ON, 0=OFF
    buf[4] = 0;
        
    grove.sendBuf(buf, bufLen);

}

