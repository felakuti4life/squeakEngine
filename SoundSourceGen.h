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
    
    
public:
    typedef AudioGen super;
    SoundSourceGen(string fpath);
    void loadSound(string fpath);
    void rewind(int pos = 0);
    bool synthesize2(float *input, float *output, int numframes);
    
    void setPlaybackRate(float f);
    float getPlaybackRate();
    
    int getSize();
    int getSRate();
    int getChannels();
    
    void cleanup();
    
protected:
    AudioFileHandler filer;
    string fpath;
    //Vector3D* visualDimensions;
    float playhead;
    int size, srate, channels;
    float playbackRate = 1;
};

#endif /* defined(__SqueakEngine__SoundSource__) */
