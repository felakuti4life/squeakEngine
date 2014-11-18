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


bool RoomGen::synthesize2(float *input, float *output, int numframes){
    super::synthesize2(input, output, numframes);
    //processing here
    output = convolver.convolveSourceWithSpace(output, impulse);
    return true;
}