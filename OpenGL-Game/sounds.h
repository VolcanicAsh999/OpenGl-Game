#pragma once
#include <AL/al.h>
#include <string>

class Sound {
public:
    Sound(char* fname);
    Sound();
    void play();
    void playAsThread();
    void quit();
    const std::string& filename;
    ALuint sourceData;
    ALuint bufferData;
};

//Sound crunchStep;
