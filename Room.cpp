//
//  Room.cpp
//  SqueakEngine
//
//  Created by Ethan Geller on 11/12/14.
//  Copyright (c) 2014 Ethan Geller. All rights reserved.
//

#include "Room.h"

Room::Room(char* impulse_fpath, int size, int srate, Vector3D c){
    this->color = c;
    impulse = this->fileHandler.readFile(impulse_fpath, &size, &srate);
}