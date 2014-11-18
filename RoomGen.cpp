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
    AudioGen source = **super::getChain().end();
    size = size + source.getSize();
    convolver.convolveSourceWithSpace(source.getSound(), impulse);
}

bool RoomGen::synthesize2(float *input, float *output, int numframes){
    super::synthesize2(input, output, numframes);
    //processing here
    for (int i = 0; i < numframes; i++) {
        if (playhead >= size) {
            rewind();
            //return false;
        }
        output[i*2] = super::getSound()[playhead*2];
        output[i*2+1] = super::getSound()[playhead*2+1];
        //cout << output[i] << endl;
        playhead++;
    }
    return true;
}