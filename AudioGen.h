//
//  AudioGen.h
//  SqueakEngine
//
//  Created by Ethan Geller on 11/16/14.
//  Copyright (c) 2014 Ethan Geller. All rights reserved.
//

#ifndef __SqueakEngine__AudioGen__
#define __SqueakEngine__AudioGen__

#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

//Generic Unit Generator.
class AudioGen {
    //instance variables here
    //pan: 0.0 = left, 1.0 = right
    float pan;
    float* sound;
    //volume: 0.0 = silence, 1.0 = max
    float volume;
    
    //sound properties
    int size, srate, channels, playhead;
    
public:
    AudioGen();
    AudioGen(vector<AudioGen*>priorChain);
    AudioGen(float panVal);
    AudioGen(float panVal, float volumeVal);
    AudioGen(vector<AudioGen*>priorChain, float panVal, float volumeVal);
    
    virtual void setSound(float* s);
    float* getSound();
    
    void setChain(vector<AudioGen*>chain);
    vector<AudioGen*> getChain();

    void setPan(float val);
    float getPan();
    void setVolume(float val);
    float getVolume();
    
    virtual void setSize(int s);
    virtual int getSize();
    
    virtual bool synthesize2(float* input, float* output, int numframes);
    
    
protected:
    //non-recursive solution
    vector<AudioGen*> sources;
};

#endif /* defined(__SqueakEngine__AudioGen__) */
