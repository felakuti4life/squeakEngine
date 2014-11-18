//
//  Room.cpp
//  SqueakEngine
//
//  Created by Ethan Geller on 11/12/14.
//  Copyright (c) 2014 Ethan Geller. All rights reserved.
//

#include "RoomGen.h"


RoomGen::RoomGen(string impulse_fpath /*Vector3D c*/){
    //this->color = c;
    impulse = filer.readFile(impulse_fpath, &channels, &size, &srate);
}

RoomGen::RoomGen(string impulse_fpath, vector<AudioGen*> sourceList){
    impulse = filer.readFile(impulse_fpath, &channels, &size, &srate);
    sources = sourceList;
    
}
void RoomGen::rewind(){
    playhead = 0;
}
void RoomGen::prepareConvolvedAudio(){
    AudioGen source = *super::getChain().back();
    size = size + source.getSize();
    float* convolved = convolver.convolveSourceWithSpace(source.getSound(), impulse);
    super::setSound(convolved);
    alreadyConvolved = true;
}

bool RoomGen::synthesize2(float *input, float *output, int numframes){
    //ssuper::synthesize2(input, output, numframes);
    //processing here
    for (int i = 0; i < numframes; i++) {
        if (playhead >= size) {
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