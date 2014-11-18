//
//  AudioFileHandler.h
//  SqueakEngine
//
//  Created by Ethan Geller on 11/16/14.
//  Copyright (c) 2014 Ethan Geller. All rights reserved.
//

#ifndef __SqueakEngine__AudioFileReader__
#define __SqueakEngine__AudioFileReader__

#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>
#include <math.h>

#include "chuck_fft.h"

#include <iostream>
#include <string>
using namespace std;

// our sample
#define SAMPLE float
#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)


class AudioFileHandler {
    
public:
    SAMPLE * readFile(const string & filename, int *channels, int * size, int * srate);
    bool writeFile(const string & filename, SAMPLE * buffy, int size, int srate);
    
};

#endif /* defined(__SqueakEngine__AudioFileReader__) */
