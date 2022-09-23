#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#define __DEBUG__

#include <iostream>
#include <string>
using namespace std;

class AudioPlayer
{
    public:
        AudioPlayer();
        ~AudioPlayer();
        bool open(string filePath);
        bool play();
        bool stop();
        void setVolume(float value);
        float getVolume();
        
    private:
        int audioFileHandler; //only for the debug example
        float volume;
        bool isOpen;
        bool isPlaying;
};

#endif