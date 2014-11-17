//
//  AudioGen.cpp
//  SqueakEngine
//
//  Created by Ethan Geller on 11/16/14.
//  Copyright (c) 2014 Ethan Geller. All rights reserved.
//

#include "AudioGen.h"

//MARK: INITIALIZERS
AudioGen::AudioGen(){
    //init stuff goes here
    pan = 0.5;
    volume = 1.0;
}

AudioGen::AudioGen(vector<AudioGen>priorChain){
    pan = 0.5;
    volume = 1.0;
    this->sources = priorChain;
}

AudioGen::AudioGen(float panVal){
    pan = panVal;
    volume = 1.0;
}

AudioGen::AudioGen(float panVal, float volumeVal){
    pan = panVal;
    volume = 1.0;
}

AudioGen::AudioGen(vector<AudioGen>priorChain, float panVal, float volumeVal){
    sources = priorChain;
    pan = panVal;
    volume = volumeVal;
}

//MARK: SETTERS
void AudioGen::setPan(float val){
    pan = val;
}

void AudioGen::setVolume(float val){
    volume = val;
}

//MARK: GETTERS
float AudioGen::getPan(){
    return pan;
}

float AudioGen::getVolume(){
    return volume;
}

bool AudioGen::synthesize2(float *input, float *output, int numframes){
    
    
}