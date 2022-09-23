#include <AudioPlayer.hpp>

AudioPlayer::AudioPlayer()
{
    setVolume(10);
    isOpen = false;
    isPlaying = false;
}

AudioPlayer::~AudioPlayer()
{
}

void AudioPlayer::open(string filePath) 
{
	ifstream file(filePath.c_str());
	if(file.good())
    {
        isOpen = true;
    }
    else
    {
        log("Error openning audiofile!");
    }
    
}

void AudioPlayer::play() 
{
    if(isOpen)
    {
        isPlaying = true;
    }
    else
    {
        log("Error playing audiofile!");
    }
}

void AudioPlayer::stop() 
{
    if(isPlaying) 
    {
        isPlaying = false;
    }
    else
    {
        log("File already stopped!");
    }
}

void AudioPlayer::setVolume(float value) 
{
    volume = value;
}

void AudioPlayer::log(string message, string filePath)
{
    ofstream logFile;
    logFile.open(filePath, ofstream::app);
    logFile << message << endl;
    logFile.close();
}
