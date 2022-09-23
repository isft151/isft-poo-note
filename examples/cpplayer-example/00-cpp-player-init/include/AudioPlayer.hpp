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
        void open(string filePath);
        void play();
        void stop();
        void setVolume(float value);
        
    private:
        float volume;
        bool isOpen;
        bool isPlaying;
        void log(string message, string filePath = "log.txt");
};

#endif // AUDIOPLAYER_H