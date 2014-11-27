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
#include "RoomGen.h"
#include <stdio.h>
#include <vector>

class EnGen : AudioGen {
    bool isOn, isCurrentlyPlayingSound;
    //current gens
    vector<SoundSourceGen> ObjectsInRoom;
    RoomGen currentRoom;
    
public:
    void setObjectsInRoom(vector<SoundSourceGen> v);
    void setCurrentRoom(RoomGen r);
    
    void start();
    void stop();
    void playSound(int index);
    bool synthesize2(float *input, float *output, int numframes);
};

#endif /* defined(__SqueakTester__EnGen__) */