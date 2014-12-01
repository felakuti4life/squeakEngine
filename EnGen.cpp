//
//  EnGen.cpp
//  SqueakTester
//
//  Created by Ethan Geller on 11/22/14.
//  Copyright (c) 2014 Ethan Geller. All rights reserved.
//

#include "EnGen.h"

EnGen::EnGen(){
    isCurrentlyPlayingSound = false;
    isCurrentlyPlayingAmbience = false;
}

void EnGen::setCurrentSound(SoundSourceGen s){
    soundSize = s.getSize();
    currentSound = s.getSound();
}

void EnGen::setCurrentSound(float *snd, int size){
    soundSize = size;
    currentSound = snd;
}

void EnGen::setCurrentAmbience(BackgroundGen bgnd){
    //FIXME: this might be an inheritence issue
    ambienceSize = bgnd.getSize();
    ambientSound = bgnd.getSound();
    cout << "Ambience size: " << ambienceSize << endl;
    isCurrentlyPlayingAmbience = true;
}

void EnGen::setCurrentAmbience(float *snd, int size){
    ambienceSize = size;
    ambientSound = snd;
    isCurrentlyPlayingAmbience = true;
}

void EnGen::stopPlayingAmbience(){
    isCurrentlyPlayingAmbience = false;
}

void EnGen::playCurrentSound(){
    soundPlayhead = 0;
    isCurrentlyPlayingSound = true;
}

void EnGen::playSound(SoundSourceGen s){
    setCurrentSound(s);
    playCurrentSound();
}

bool EnGen::synthesize2(float *input, float *output, int numframes){
    
        //playing both
    if(isCurrentlyPlayingSound && isCurrentlyPlayingAmbience){
        for (int i = 0; i < numframes; i++) {
            if (soundPlayhead >= soundSize*2) {
                isCurrentlyPlayingSound = false;
            }
            if (ambiencePlayhead >= ambienceSize)
                ambiencePlayhead = 0;
        
        output[i*2] = (currentSound[soundPlayhead*2] + ambientSound[ambiencePlayhead*2]);
        output[i*2+1] =currentSound[soundPlayhead*2+1] + ambientSound[ambiencePlayhead*2+1];
        soundPlayhead++;
        ambiencePlayhead++;
            }
        }
    //ambience, no sound
    else if(isCurrentlyPlayingAmbience){
        for (int i = 0; i < numframes; i++) {
            if (ambiencePlayhead >= ambienceSize) {
                ambiencePlayhead = 0;
            }
            
            output[i*2] = ambientSound[ambiencePlayhead*2];
            output[i*2+1] =ambientSound[ambiencePlayhead*2+1];
            ambiencePlayhead++;
        }
    }
    //sound, no ambience
    else if(isCurrentlyPlayingSound){
        for (int i = 0; i < numframes; i++) {
            if (soundPlayhead >= soundSize*2) {
                isCurrentlyPlayingSound = false;
            }
            else{
                output[i*2] = currentSound[soundPlayhead*2];
                output[i*2+1] =currentSound[soundPlayhead*2+1];
                soundPlayhead++;
            }
        }
    }
        
    
    //nothing!
    else {
        for (int i = 0; i < numframes; i++) {
            output[i*2] = 0;
            output[i*2+1] = 0;
        }
    }
    return true;
}