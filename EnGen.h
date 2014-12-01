//
//  EnGen.h
//  SqueakTester
//
//  Created by Ethan Geller on 11/22/14.
//  Copyright (c) 2014 Ethan Geller. All rights reserved.
//

#ifndef __SqueakTester__EnGen__
#define __SqueakTester__EnGen__
#include "AudioGen.h"
#include "SoundSourceGen.h"
#include "BackgroundGen.h"
#include "RoomGen.h"
#include <stdio.h>
#include <vector>
using namespace std;

class EnGen : AudioGen {
    bool isCurrentlyPlayingSound, isCurrentlyPlayingAmbience;
    //current gens
    vector<SoundSourceGen> ObjectsInRoom;
    float* currentSound;
    float* ambientSound;
    int soundSize, ambienceSize, soundPlayhead, ambiencePlayhead;
    
public:
    EnGen();
    void setCurrentSound(SoundSourceGen s);
    void setCurrentSound(float* snd, int size);
    void setCurrentAmbience(BackgroundGen bgnd);
    void setCurrentAmbience(float* snd, int size);
    void stopPlayingAmbience();
    void playCurrentSound();
    void playSound(SoundSourceGen s);
    bool synthesize2(float *input, float *output, int numframes);
};

#endif /* defined(__SqueakTester__EnGen__) */
