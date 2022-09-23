#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#pragma once
#include <cppset/LibraryLoader.h>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
using namespace std;

class AudioPlayer
{
    public:
        AudioPlayer();
        ~AudioPlayer();
        bool open(string filePath);
        void play();
        void stop();
        void setVolume(float value);
    private:
        LibraryLoader loader;
        sf::Music audioFileHandler;
        bool isOpen;
        bool isPlay;

        void showError(string message, string message2);
};

#endif