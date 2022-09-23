#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
using namespace std;

class AudioPlayer
{
    public:
        AudioPlayer()
        {
            isOpen = false;
            isPlay = false;
            cout << "Create AudioPlayer" << endl;
        }
        ~AudioPlayer()
        {
            cout << "Destroy AudioPlayer" << endl;
        }

        bool open(string filePath)
        {
            return isOpen = audioFileHandler.openFromFile(filePath);
        }

        void play()
        {
            isOpen ? audioFileHandler.play() : showError("Error opening file");
            isPlay = true;
        }

        void stop()
        {
            isPlay ? audioFileHandler.stop() : showError("No files playing");
            isPlay = false;
        }

        void setVolume(float value)
        {
            audioFileHandler.setVolume(value);
        }
        
    private:
        sf::Music audioFileHandler;
        bool isOpen;
        bool isPlay;

        void showError(string message, string message2 = "")
        {
            cerr << message << ' ' << message2 << endl;
            exit(EXIT_FAILURE);
        }
};

#endif