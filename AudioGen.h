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
using namespace std;
class AudioGen {
    //instance variables here
    //pan: 0.0 = left, 1.0 = right
    float pan;
    //volume: 0.0 = silence, 1.0 = max
    float volume;
public:
    AudioGen();
    AudioGen(vector<AudioGen>priorChain);
    AudioGen(float panVal);
    AudioGen(float panVal, float volumeVal);
    AudioGen(vector<AudioGen>priorChain, float panVal, float volumeVal);
    bool synthesize2(float* input, float* output, int numframes);
    void setPan(float val);
    float getPan();
    void setVolume(float val);
    float getVolume();
    
protected:
    vector<AudioGen> sources;
};

#endif /* defined(__SqueakEngine__AudioGen__) */
