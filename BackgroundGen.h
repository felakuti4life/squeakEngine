//
//  BackgroundGen.h
//  SqueakEngine
//
//  Created by Ethan Geller on 11/16/14.
//  Copyright (c) 2014 Ethan Geller. All rights reserved.
//

#ifndef __SqueakEngine__BackgroundGen__
#define __SqueakEngine__BackgroundGen__

#include <stdio.h>
#include "SoundSourceGen.h"


class BackgroundGen : public SoundSourceGen {
    
    
public:
    typedef SoundSourceGen super;
    BackgroundGen();
    BackgroundGen(string fpath);
    bool synthesize2(float *input, float *output, int numframes);
};

#endif /* defined(__SqueakEngine__BackgroundGen__) */
