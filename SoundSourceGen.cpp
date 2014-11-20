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
    //playbackRate = 1;
    cout << "loading" << fpath << ":\n" << "channels: " << channels << " size: " << size << " srate: " << srate << endl;
}


void SoundSourceGen::loadSound(string fpath){
    float* s = filer.readFile(fpath, &channels, &size, &srate);
    super::setSound(s);
}

void SoundSourceGen::rewind(int pos){
    playhead = pos;
}

void SoundSourceGen::setPlaybackRate(float f){
    playbackRate = f;
}

float SoundSourceGen::getPlaybackRate(){
    return playbackRate;
}

int SoundSourceGen::getSize(){return size;}
int SoundSourceGen::getSRate(){return srate;}
int SoundSourceGen::getChannels(){return channels;}

bool SoundSourceGen::synthesize2(float *input, float *output, int numframes){
    super::synthesize2(input, output, numframes);
    for (int i = 0; i < numframes; i++) {
        if (playhead >= size*channels) {
            rewind();
            return false;
        }
        output[i*2] = super::getSound()[(int)playhead*2];
        output[i*2+1] = super::getSound()[(int)playhead*2+1];
        //cout << output[i] << endl;
        playhead+= playbackRate;
    }
    return true;
}

