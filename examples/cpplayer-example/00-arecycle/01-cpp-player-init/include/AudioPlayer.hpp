#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

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
        
    private:
        float volume;
        bool isOpen;
        bool isPlaying;
        void log(string message, string filepath = "log.txt");
};

#endif // AUDIOPLAYER_H