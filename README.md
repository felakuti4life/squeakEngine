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
    return 0;
}
```

Playing Sounds
----------------

There are several types of unit generators included out of the box with Squeak Engine. To create a basic sound, use the `SoundSourceGen`:

```
SoundSourceGen DoorOpen = SoundSourceGen("sound/singles/door_open.wav");

//play sound once
engine.playSound(DoorClose);
```

Playing Background Music/Ambience
---------------------------------

Loading a soundfile into a `BackgroundGen` object will cause it to loop continuously until stopped:

```
BackgroundGen introMusic = BackgroundGen("sound/ambient/theme.wav");

//play music
//set up background music
engine.setCurrentAmbience(introMusic);
```

Playing a sound in a room (Convolution Reverb)
---------------------------------------------

Loading a .wav file of an impulse response into a `RoomGen` will allow you to convolve a sound with that room:

```
int doorClosetSize;
RoomGen heavenRoom = RoomGen("sound/impulses/heaven.wav");

float* doorCloseSound = heavenRoom.getSoundInRoom(dryDoorClose.getSound(), DoorClose.getSize(), &doorCloseSize);
DoorClose.setSound(doorCloseSound);
DoorClose.setSize(doorClosetSize/2);
```

This is not very elegant, though. It's a work in progress :)

Make your own unit generators!
------------------------------
To make your own unit generators in SqueakEngine, subclass the `AudioGen`. You can do all your processing by overriding the `synthesize2` method:

```
virtual bool synthesize2(float* input, float* output, int numframes);
```
