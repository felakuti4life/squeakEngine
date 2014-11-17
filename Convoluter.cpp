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
    // sanity check
    //FIXME: where does assert live?
    //assert((fsize + gsize - 1) == size);
    
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
    
    // invers fft
    rfft(result, fftsize/2, FFT_INVERSE );
    
    // copy into buffy
    memcpy( buffy, result, sizeof(SAMPLE) * size );
}

float* Convoluter::convolveSourceWithSpace(float *source, float *response){
    int floatsize = sizeof(float);
    int fsize = sizeof(source)/floatsize;
    int gsize = sizeof(response)/floatsize;
    int size = fsize + gsize - 1;
    
    SAMPLE * buffer = new SAMPLE[size];
    
    convolve_fft(source, fsize, response, gsize, buffer, size);
    return buffer;
    
    
}
