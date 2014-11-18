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
#include <string>
#include <math.h>
//#include "x-vector3d.h"
#include "AudioFileHandler.h"
#include "AudioGen.h"

class SoundSourceGen : public AudioGen{
    AudioFileHandler filer;
    string fpath;
    //Vector3D* visualDimensions;
    int playhead;
    int size, srate, channels;
    
public:
    typedef AudioGen super;
    SoundSourceGen(string fpath);
    void loadSound(string fpath);
    void rewind();
    bool synthesize2(float *input, float *output, int numframes);
    
    int getSize();
    int getSRate();
    int getChannels();
};

#endif /* defined(__SqueakEngine__SoundSource__) */
