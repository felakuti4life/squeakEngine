//
//  Room.h
//  SqueakEngine
//
//  Created by Ethan Geller on 11/12/14.
//  Copyright (c) 2014 Ethan Geller. All rights reserved.
//

#ifndef __SqueakEngine__Room__
#define __SqueakEngine__Room__

#include <stdio.h>
#include "x-vector3d.h"
#include "AudioFileHandler.h"
class Room {
    //impulse in frequency samples
    float* impulse;
    
    Vector3D* color;
    
public:
    //TODO: init functions
    Room(char* impulse_fpath, int size, int srate);
private:
    AudioFileHandler fileHandler;
};

#endif /* defined(__SqueakEngine__Room__) */
