//
//  SoundSource.cpp
//  SqueakEngine
//
//  Created by Ethan Geller on 11/12/14.
//  Copyright (c) 2014 Ethan Geller. All rights reserved.
//

#include "SoundSourceGen.h"

SoundSourceGen::SoundSourceGen(char* fpath){
    super::AudioGen();
    sound = filehandler.readFile(fpath, &size, &srate);
}