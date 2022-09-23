#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

#include <iostream>
#include <fstream>
using namespace std;
class AudioPlayer
{
   public:
        AudioPlayer();

        ~AudioPlayer();
        
        void open(string filePath);
        void play();
        void stop();
        bool getOpenStatus();
        bool getPlaybackStatus();
        void setVolume(float value);
        float getVolume();

   private:
        float volume;
        bool isOpen;
        bool isPlaying;
        void log(string message, string filePath = "./log/log.txt");
};

#endif // AUDIOPLAYER_H