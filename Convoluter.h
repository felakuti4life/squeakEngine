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


class Convoluter {
    //instance variables here
    
public:
    //TODO:
    //convolveSourceWithSpace(float* source, float* space)
    //returns float* time-domain
    float* convolveSteroSourceWithStereoSpace(float* source, float* response);
    
private:
    unsigned long next_power_2(unsigned long n);
};


#endif /* defined(__SqueakEngine__Convoluter__) */
