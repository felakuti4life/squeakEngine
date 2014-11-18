//
//  SoundSource.cpp
//  SqueakEngine
//
//  Created by Ethan Geller on 11/12/14.
//  Copyright (c) 2014 Ethan Geller. All rights reserved.
//

#include "SoundSourceGen.h"


SoundSourceGen::SoundSourceGen(string fpath){
    super::AudioGen();
    sound = filer.readFile(fpath, &channels, &size, &srate);
    this->fpath = fpath;
}

float* SoundSourceGen::getSound(){
    return sound;
}

void SoundSourceGen::setSound(string fpath){
    sound = filer.readFile(fpath, &channels, &size, &srate);
}

void SoundSourceGen::rewind(){
    playhead = 0;
}

bool SoundSourceGen::synthesize2(float *input, float *output, int numframes){
    super::synthesize2(input, output, numframes);
    //processing here
    cout << "counter: " << playhead << endl;
    for (int i = 0; i < numframes * 2; i++) {
        if (playhead >= size*channels) {
            rewind();
            //return false;
        }
        output[i] = sound[playhead];
        //cout << output[i] << endl;
        playhead++;
    }
    return true;
}