/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GrovePiModule.h
 * Author: igor
 *
 * Created on 21 February 2016, 11:39 AM
 */

#ifndef GROVEPIMODULE_H
#define GROVEPIMODULE_H

#include "GrovePi.h"


class GrovePiModule {
public:
    
    GrovePiModule(const GrovePi &grove);
    
    GrovePiModule() = delete;
    GrovePiModule(const GrovePiModule& orig) = delete;
    virtual ~GrovePiModule();
    
protected:
    const GrovePi &grove;

};

#endif /* GROVEPIMODULE_H */

