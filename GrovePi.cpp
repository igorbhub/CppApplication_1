/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GrovePi.cpp
 * Author: igor
 * 
 * Created on 19 January 2016, 11:07 AM
 */

#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <exception>

#include <sys/ioctl.h>
#include <linux/i2c-dev.h>


using namespace std;

#include "GrovePiException.h"
#include "GrovePi.h"

const int GrovePi::defaultControllerNo(1);
const int GrovePi::defaultControllerAddr(0x04);
const string GrovePi::FileNameBase = "/dev/i2c-";

GrovePi::GrovePi() {
    makeGrovePi(defaultControllerNo, defaultControllerAddr);
}

GrovePi::GrovePi(int controllerNo) {
    makeGrovePi(controllerNo, defaultControllerAddr);
}

GrovePi::GrovePi(int controllerNo, int controllerAddr) {
    makeGrovePi(controllerNo, controllerAddr);
}
//
//GrovePi::GrovePi(const GrovePi& orig) {
//}

GrovePi::~GrovePi() {
    int rc;
    rc = close(file);
    if (rc != 0) {
        cout << "Can't close file " << file << endl;
    }
}

void
GrovePi::makeGrovePi(int ctrlNo, int ctrlAddr) throw () {
    stringstream ss;
    string s;
    int rc;

    controllerNo = ctrlNo;
    ss << FileNameBase << controllerNo;
    s = ss.str();

    file = open(s.c_str(), O_RDWR);
    if (file < 0) {
        std::cout << "Can't open file " << s << std::endl;
        std::cout << "Error: " << strerror(errno) << std::endl;
        throw (gpEx);
    }

    controllerAddr = ctrlAddr;
    rc = ioctl(file, I2C_SLAVE, controllerAddr);
    if (rc < 0) {
        std::cout << "Can't set slave address" << std::endl;
        std::cout << "Error: " << strerror(errno) << std::endl;
        throw (gpEx);
    }
}

void
GrovePi::sendBuf(unsigned char * buf, int bufLen) const throw () {
    int rc;
    int const nRepetitions = 3;
    int i = 1;

    do {
        rc = write(file, buf, bufLen);
        if (rc == bufLen) {
            return;
        } else {
            std::cout << "Can't send buffer to controller rc=" << rc << " bufLen=" << bufLen << std::endl;
            std::cout << "Error: " << strerror(errno) << std::endl;
        }
    } while (i++ < nRepetitions);
    throw (gpEx);
}
