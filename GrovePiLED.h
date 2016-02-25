/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GrovePiLED.h
 * Author: igor
 *
 * Created on 18 February 2016, 12:42 PM
 */

#ifndef GROVEPILED_H
#define GROVEPILED_H

#include "GrovePiGPIO.h"

class GrovePiLED : public GrovePiGPIO {
private:
    bool state;  // ON (=true) or OFF
    
public:
    GrovePiLED(int const pinNo, bool const initialState, const GrovePi &grove);
    
    GrovePiLED() = delete;
    GrovePiLED(const GrovePiLED& orig) = delete;
    virtual ~GrovePiLED();
    
private:

};

#endif /* GROVEPILED_H */

