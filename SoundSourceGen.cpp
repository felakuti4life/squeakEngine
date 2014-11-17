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
    sound = filer.readFile(fpath, &size, &srate);
}

float* SoundSourceGen::getSound(){
    return sound;
}