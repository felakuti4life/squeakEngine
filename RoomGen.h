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
//#include "x-vector3d.h"
#include <vector>
#include <string>
using namespace std;
#include "AudioGen.h"
#include "AudioFileHandler.h"
#include "Convoluter.h"

//ROOM GEN: Impulse creator
class RoomGen : public AudioGen {
    //impulse in frequency samples
    float* impulse;
    AudioFileHandler filer;
    Convoluter convolver;
    int size, srate;
    //Vector3D color;
    
public:
    typedef AudioGen super;
    //TODO: init functions
    RoomGen(string impulse_fpath /*Vector3D c*/);
    RoomGen(string impulse_fpath, vector<AudioGen*> sourceList);
    bool synthesize2(float *input, float *output, int numframes);

};

#endif /* defined(__SqueakEngine__Room__) */