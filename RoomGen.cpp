//
//  Room.cpp
//  SqueakEngine
//
//  Created by Ethan Geller on 11/12/14.
//  Copyright (c) 2014 Ethan Geller. All rights reserved.
//

#include "RoomGen.h"

RoomGen::RoomGen(char* impulse_fpath, int size, int srate, Vector3D c){
    this->color = c;
    impulse = filehandler.readFile(impulse_fpath, &size, &srate);
}

bool RoomGen::synthesize2(float *input, float *output, int numframes){
    super::synthesize2(input, output, numframes);
    //processing here
    output = convoluter.convolveSourceWithSpace(output, impulse);
    return true;
}