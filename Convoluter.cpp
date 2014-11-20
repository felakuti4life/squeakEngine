//
//  Convoluter.cpp
//  SqueakEngine
//
//  Created by Ethan Geller on 11/12/14.
//  Copyright (c) 2014 Ethan Geller. All rights reserved.
//

#include "Convoluter.h"
#include "chuck_fft.h"
#include <string>
#include <stdlib.h>
//#include <sndfile.h>
#include <math.h>
#include <iostream>
using namespace std;

#define SAMPLE float
#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)

unsigned long next_power_2( unsigned long n )
{
    unsigned long nn = n;
    for( ; n &= n-1; nn = n );
    return nn * 2;
}

void convolve_fft( SAMPLE * f, int fsize, SAMPLE * g, int gsize, SAMPLE * buffy, int size )
{
    // make buffers to hold kernel and signal
    
    unsigned int fftsize = next_power_2( fsize + gsize - 1 );
    // do it
    SAMPLE * fbuf = new SAMPLE[fftsize];
    SAMPLE * gbuf = new SAMPLE[fftsize];
    SAMPLE * result = new SAMPLE[fftsize];
    // clear
    memset( fbuf, 0, sizeof(SAMPLE) * fftsize );
    memset( gbuf, 0, sizeof(SAMPLE) * fftsize );
    memset( result, 0, sizeof(SAMPLE) * fftsize );
    
    // copy in
    memcpy( fbuf, f, sizeof(SAMPLE) * fsize );
    memcpy( gbuf, g, sizeof(SAMPLE) * gsize );
    // take fft
    rfft( fbuf, fftsize/2, FFT_FORWARD );
    rfft( gbuf, fftsize/2, FFT_FORWARD );
    
    // complex
    complex * fcomp = (complex *)fbuf;
    complex * gcomp = (complex *)gbuf;
    complex * rcomp = (complex *)result;
    
    // variables
    float fre, fim, gre, gim;
    // loop
    for( int i = 0; i < fftsize/2; i++ )
    {
        // local copies
        fre = fcomp[i].re; fim = fcomp[i].im;
        gre = gcomp[i].re; gim = gcomp[i].im;
        // complex multiply
        rcomp[i].re = fre * gre - fim * gim;
        rcomp[i].im = fre * gim + fim * gre;
    }
    
    // inverse fft
    rfft(result, fftsize/2, FFT_INVERSE );
    
    // copy into buffy
    memcpy( buffy, result, sizeof(SAMPLE) * size );
}

float* Convoluter::convolveSteroSourceWithStereoSpace(float *source, int sSize, float *response, int rSize){
    //int samplesize = sizeof(SAMPLE);
    
    int fsize = sSize;
    int gsize = rSize;
    int size = fsize + gsize - 1;
    
    SAMPLE* sourcechannel1 = new SAMPLE[fsize/2];
    SAMPLE* sourcechannel2 = new SAMPLE[fsize/2];
    SAMPLE* responsechannel1 = new SAMPLE[gsize/2];
    SAMPLE* responsechannel2 = new SAMPLE[gsize/2];
    
    for(int i = 0; i < fsize/2; i++){
        sourcechannel1[i] = source[i*2];
        sourcechannel2[i] = source[i*2+1];
    }
    for (int i = 0; i < gsize/2; i ++) {
        responsechannel1[i] = response[i*2];
        responsechannel2[i] = response[i*2+1];
    }
    SAMPLE * bufferchannel1 = new SAMPLE[size/2];
    SAMPLE * bufferchannel2 = new SAMPLE[size/2];
    SAMPLE * buffer = new SAMPLE[size];
    cout << "left channel..." << endl;
    convolve_fft(sourcechannel1, fsize/2, responsechannel1, gsize/2, bufferchannel1, size/2);
    cout << "right channel..." << endl;
    convolve_fft(sourcechannel2, fsize/2, responsechannel2, gsize/2, bufferchannel2, size/2);
    cout << "joining..." << endl;
    for (int i = 0; i < size/2; i++) {
        buffer[i*2] = bufferchannel1[i];
        buffer[i*2+1] = bufferchannel2[i];
    }
    return buffer;
    
    
}
