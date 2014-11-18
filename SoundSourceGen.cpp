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
    float* s = filer.readFile(fpath, &channels, &size, &srate);
    super::setSound(s);
    this->fpath = fpath;
    cout << "channels: " << channels << " size: " << size << " srate: " << srate << endl;
}


void SoundSourceGen::loadSound(string fpath){
    float* s = filer.readFile(fpath, &channels, &size, &srate);
    super::setSound(s);
}

void SoundSourceGen::rewind(){
    playhead = 0;
}

int SoundSourceGen::getSize(){return size;}
int SoundSourceGen::getSRate(){return srate;}
int SoundSourceGen::getChannels(){return channels;}

bool SoundSourceGen::synthesize2(float *input, float *output, int numframes){
    super::synthesize2(input, output, numframes);
    //processing here
    //cout << "size: " << playhead/size << endl;
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