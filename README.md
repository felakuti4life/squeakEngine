squeakEngine
============
by Ethan Geller and Andrew Forsyth

ver 0.1.1

Engine for audio-driven adventure games. Features basic graph functionality (chaining), FFT convolution, and easy audio file loading.

For an example of a project that uses SqueakEngine, check out [Squeak](https://github.com/felakuti4life/squeak).

Special thanks to Gary Scavone for maintaining RtAudio, and to Ge Wang for all his guidance.

A WORD OF WARNING
-----------------
Documentation is on the way, as soon as a few critical bugs are fixed.

Setup
----

SqueakEngine works with [RtAudio](https://www.music.mcgill.ca/~gary/rtaudio/). The RtAudio source is included in the SqueakEngine repository. However, any audio API that gives you a callback method will work with SqueakEngine.

the SqueakEngine is primarily controlled through an EnGen object:

`EnGen engine;`

The EnGen handles the scheduling. Set it up in your audio callback function by calling the `synthesize2` method:

```
int callback(void *outputBuffer, void *inputBuffer, unsigned int numFrames,
             double streamTime, RtAudioStreamStatus status, void *data) {
    float *input = (float *) inputBuffer;
    float *output = (float *) outputBuffer;
    
    engine.synthesize2(input, output, numFrames);
    memcpy(g_buffer, output, numFrames*2);
    return 0;
}
```
