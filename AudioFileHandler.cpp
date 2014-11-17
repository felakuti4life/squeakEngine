//
//  AudioFileReader.cpp
//  SqueakEngine
//
//  Created by Ethan Geller on 11/16/14.
//  Copyright (c) 2014 Ethan Geller. All rights reserved.
//

#include "AudioFileHandler.h"

SAMPLE * AudioFileHandler::readFile(const string & filename, int * size, int * srate)
{
    // handle
    SNDFILE * sf = NULL;
    // info
    SF_INFO info;
    // because the doc says
    info.format = 0;
    // ...
    SAMPLE * buffer = NULL;
    // zero out
    *size = 0;
    *srate = 0;
    
    // open it
    sf = sf_open(filename.c_str(), SFM_READ, &info);
    // check it
    if( !sf )
    {
        // error message
        cout << "error: cannot open '" << filename << "'" << endl;
        return NULL;
    }
    
    // make sure it's mono
    if(info.channels > 1)
    {
        // error message
        cout << "error: '" << filename << "' is not MONO" << endl;
        goto done;
    }
    
    // allocate the whole thing!
    buffer = new SAMPLE[info.frames];
    // check it
    if( !buffer )
    {
        // error message
        cout << "error: out of memory... frak" << endl;
        goto done;
    }
    
    // read it
    if( sf_read_float( sf, buffer, info.frames ) != info.frames )
    {
        // error message
        cout << "error: can't read file..." << endl;
        // free
        delete [] buffer; buffer = NULL;
        goto done;
    }
    
    // set size
    *size = info.frames;
    // set srate
    *srate = info.samplerate;
    
done:
    // close sf
    if( sf ) sf_close( sf );
    
    return buffer;
}

bool AudioFileHandler::writeFile(const string & filename, SAMPLE * buffy, int size, int srate)
{
    // handle
    SNDFILE * sf = NULL;
    // info
    SF_INFO info;
    // result
    bool result = false;
    
    // fill in
    info.samplerate = srate;
    info.channels = 1;
    info.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
    info.frames = 0;
    
    // open
    sf = sf_open( filename.c_str(), SFM_WRITE, &info );
    // check
    if( !sf )
    {
        // error message
        cout << "error: can't open '" << filename << "' for write" << endl;
        goto done;
    }
    
    // write it
    if( sf_write_float( sf, buffy, size ) != size )
    {
        // error message
        cout << "error: can't write to file..." << endl;
        goto done;
    }
    
    // set flag
    result = true;
    
done:
    if( sf ) sf_close( sf );
    
    return result;
}

