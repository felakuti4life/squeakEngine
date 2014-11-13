//
//  Convoluter.h
//  SqueakEngine
//
//  Created by Ethan Geller on 11/12/14.
//  Copyright (c) 2014 Ethan Geller. All rights reserved.
//

#ifndef __SqueakEngine__Convoluter__
#define __SqueakEngine__Convoluter__

#include <stdio.h>
#include "chuck_fft.h"

class Convoluter {
    //instance variables here
    
public:
    //TODO:
    //convolveSourceWithSpace(float* source, float* space)
    //returns float* time-domain
    float* convolveSourceWithSpace(float* source, float* response);
};


#endif /* defined(__SqueakEngine__Convoluter__) */
