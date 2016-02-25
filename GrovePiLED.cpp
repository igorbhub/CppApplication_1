/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GrovePiLED.cpp
 * Author: igor
 * 
 * Created on 18 February 2016, 12:42 PM
 */


#include "GrovePiGPIO.h"
#include "GrovePiLED.h"

GrovePiLED::GrovePiLED(int const pin, bool const initialState, const GrovePi &grove)
    : GrovePiGPIO(pin, grove)
{
}


GrovePiLED::~GrovePiLED() {
}



