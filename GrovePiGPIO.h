/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GrovePiGPIO.h
 * Author: igor
 *
 * Created on 27 January 2016, 12:43 PM
 */

#include "GrovePiModule.h"

#ifndef GROVEPIGPIO_H
#define GROVEPIGPIO_H


class GrovePiGPIO : public GrovePiModule
{
public:
    
    static int const IOMODE_input = 0;
    static int const IOMODE_output = 1;
    
    static int const COMMAND_dRead = 1;
    static int const COMMAND_dWrite = 2;
    static int const COMMAND_aRead = 3;
    static int const COMMAND_aWrite = 4;
    static int const COMMAND_pMode = 5;
    static int const COMMAND_5usec_pulse = 7;
    static int const COMMAND_accelerometer = 20;
    static int const COMMAND_rtc = 30;
    static int const COMMAND_temp_and_humidity = 40;
    
protected:
    
    int const pinNo;
    void setPinMode(int const pinMode) throw();
    
public:
    
    GrovePiGPIO(int const pin, GrovePi const &grove);

    GrovePiGPIO() = delete;
    GrovePiGPIO(const GrovePiGPIO& orig) = delete;
    virtual ~GrovePiGPIO();
    
    int const getPinNo(void) const;
    void setPinState(int const onOff) throw();
};

#endif /* GROVEPIGPIO_H */

