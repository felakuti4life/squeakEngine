//
//  Room.cpp
//  SqueakEngine
//
//  Created by Ethan Geller on 11/12/14.
//  Copyright (c) 2014 Ethan Geller. All rights reserved.
//

#include "RoomGen.h"

//MARK: INITIALIZERS
RoomGen::RoomGen(string impulse_fpath /*Vector3D c*/){
    //this->color = c;
    impulse = filer.readFile(impulse_fpath, &channels, &size, &srate);
}

RoomGen::RoomGen(string impulse_fpath, vector<AudioGen*> sourceList){
    impulse = filer.readFile(impulse_fpath, &channels, &size, &srate);
    sources = sourceList;
    
}

RoomGen::RoomGen(string impulse_fpath, vector<AudioGen*> sourceList, BackgroundGen amb){
    impulse = filer.readFile(impulse_fpath, &channels, &size, &srate);
    sources = sourceList;
    ambience = amb;
}

RoomGen::RoomGen(string impulse_fpath, string ambience_fpath, vector<AudioGen*> sourceList){
    impulse = filer.readFile(impulse_fpath, &channels, &size, &srate);
    sources = sourceList;
    ambience = BackgroundGen(ambience_fpath);
}

void RoomGen::rewind(){
    playhead = 0;
}
void RoomGen::prepareConvolvedAudio(){
    AudioGen source = *super::getChain().back();
    int sSize = getSize();
    SAMPLE* sourceSound = source.getSound();
    SAMPLE* convolved = convolver.convolveSteroSourceWithStereoSpace(sourceSound, sSize, impulse, size);
    size += sSize;
    super::setSound(convolved);
    alreadyConvolved = true;
}

SAMPLE* RoomGen::getSoundInRoom(float *s, int sSize, int *tSize){
    *tSize = sSize + size - 1;
    return convolver.convolveSteroSourceWithStereoSpace(s, sSize, impulse, size);
}

bool RoomGen::synthesize2(float *input, float *output, int numframes){
    //ssuper::synthesize2(input, output, numframes);
    //processing here
    for (int i = 0; i < numframes; i++) {
        if (playhead >= size/2) {
            rewind();
            //return false;
        }
        if(alreadyConvolved){
            output[i*2] = super::getSound()[playhead*2];
            output[i*2+1] = super::getSound()[playhead*2+1];
        }
        playhead++;
    }
    return true;
}