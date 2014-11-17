//
//  SoundSource.h
//  SqueakEngine
//
//  Created by Ethan Geller on 11/12/14.
//  Copyright (c) 2014 Ethan Geller. All rights reserved.
//

#ifndef __SqueakEngine__SoundSource__
#define __SqueakEngine__SoundSource__

#include <stdio.h>
#include "x-vector3d.h"

class SoundSource {
    float* source;
     Vector3D* visualDimensions;
    
public:
    //TODO:
    
    float* getSound();
    
};

#endif /* defined(__SqueakEngine__SoundSource__) */
