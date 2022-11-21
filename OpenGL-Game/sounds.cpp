#include <AL/al.h>
#include "sounds.h"
#include "playsound.h"

Sound::Sound(const std::string& fname)
    :filename(fname)
{
    LoadSound(fname);
    bufferData = getBuffer();
    sourceData = getSource();
}

Sound::Sound()
{
    filename = "";
}

void Sound::play()
{
    alSourcePlay(sourceData);
    ALint state = AL_PLAYING;
    while(state == AL_PLAYING)
    {
        alGetSourcei(sourceData, AL_SOURCE_STATE, &state);
    }
}

void Sound::quit()
{
    alDeleteSources(1, &sourceData);
    alDeleteSources(1, &bufferData);
}

//Sound crunchStep = Sound("resources\\sounds\\crunchstep.wav");
