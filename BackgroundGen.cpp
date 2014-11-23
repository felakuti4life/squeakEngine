//
//  BackgroundGen.cpp
//  SqueakEngine
//
//  Created by Ethan Geller on 11/16/14.
//  Copyright (c) 2014 Ethan Geller. All rights reserved.
//

#include "BackgroundGen.h"
#include "AudioFileHandler.h"

BackgroundGen::BackgroundGen(){}
BackgroundGen::BackgroundGen(string fpath) : SoundSourceGen(fpath){}

bool BackgroundGen::synthesize2(float *input, float *output, int numframes){
    //super::synthesize2(input, output, numframes);
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