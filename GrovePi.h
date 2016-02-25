/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GrovePi.h
 * Author: igor
 *
 * Created on 19 January 2016, 11:07 AM
 */

#ifndef GROVEPI_H
#define GROVEPI_H

#include <string>

#include "GrovePiException.h"

class GrovePi {
private:
    int file; // controller device file descriptor
    int controllerNo;
    int controllerAddr;
    static const std::string FileNameBase;
    void makeGrovePi(int controllerNo, int controllerAddr) throw();
    
    static const int defaultControllerAddr;
    static const int defaultControllerNo;
public:
    GrovePi();
    GrovePi(int const controllerNo);
    GrovePi(int controllerNo, int controllerAddr);
    //GrovePi(const GrovePi& orig);
    virtual ~GrovePi();
    
    GrovePiException gpEx;
    
    void sendBuf(unsigned char * buf, int bufLen) const throw();
};

#endif /* GROVEPI_H */

