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
#include "BackgroundGen.h"

//ROOM GEN: Impulse creator
class RoomGen : public AudioGen {
    //impulse in frequency samples
    SAMPLE* impulse;
    AudioFileHandler filer;
    Convoluter convolver;
    BackgroundGen ambience;
    
    int size, srate, channels, playhead;
    bool alreadyConvolved;
    //Vector3D color;
    
public:
    typedef AudioGen super;
    //MARK: init functions
    RoomGen(string impulse_fpath = "/Users/Ethan/syncbox/SQUEAK/sound/singles/squeak_3.wav" /*Vector3D c*/);
    RoomGen(string impulse_fpath, vector<AudioGen*> sourceList);
    RoomGen(string impulse_fpath, vector<AudioGen*> sourceList, BackgroundGen amb);
    RoomGen(string impulse_fpath, string ambience_fpath, vector<AudioGen*> sourceList);
    void rewind();
    void prepareConvolvedAudio();
    SAMPLE* getSoundInRoom(SAMPLE* s, int sSize, int *tSize);
    bool synthesize2(float *input, float *output, int numframes);

};

#endif /* defined(__SqueakEngine__Room__) */
