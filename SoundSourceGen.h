//
//  SoundSource.h
//  SqueakEngine
//
//  Created by Ethan Geller on 11/12/14.
//  Copyright (c) 2014 Ethan Geller. All rights reserved.
//

#ifndef __SqueakEngine__SoundSource__
#define __SqueakEngine__SoundSource__

#include <stdio.h>
#include "x-vector3d.h"
#include "AudioFileHandler.h"
#include "AudioGen.h"

class SoundSourceGen : AudioGen{
    char* sourceFpath;
    float* sound;
     Vector3D* visualDimensions;
    int playhead;
    int size, srate;
    
public:
    typedef AudioGen super;
    SoundSourceGen(char* fpath);
    float* getSound();
    
};

#endif /* defined(__SqueakEngine__SoundSource__) */
