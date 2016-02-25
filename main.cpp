/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: igor
 *
 * Created on January 7, 2016, 11:22 AM
 */


#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>

#include <sys/ioctl.h>
#include <linux/i2c-dev.h>


using namespace std;

class GrovePiException;
#include "GrovePi.h"
#include "GrovePiException.h"
#include "GrovePiGPIO.h"
#include "GrovePiLED.h"

/*
 * 
 */
int main(int argc, char** argv) {

    int const Delay = 100000;
    GrovePi cntrl;
    
    GrovePiLED ledBlue(4, true, cntrl);
    GrovePiLED ledGreen(3, true, cntrl);
    GrovePiLED ledRed(2, true, cntrl);


    for (int i = 0; i < 1000; i++) {
        ledBlue.setPinState(1);
        usleep(Delay);
        ledBlue.setPinState(0);
        usleep(Delay);
        ledGreen.setPinState(1);
        usleep(Delay);
        ledGreen.setPinState(0);
        usleep(Delay);
        ledRed.setPinState(1);
        usleep(Delay);
        ledRed.setPinState(0);
        usleep(Delay);
    }

    return 0;
}

