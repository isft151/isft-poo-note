#include <AudioPlayer.hpp>

AudioPlayer::AudioPlayer() 
{ 
    isOpen = false; 
    isPlaying = false;
    setVolume(10);
}

AudioPlayer::~AudioPlayer(){}

void AudioPlayer::open(string filePath)
{
    //@ToDo: por ahora simulamos la apertura correcta
    ifstream file(filePath.c_str());
    if(file.good())isOpen = true;
    else log("Error: Could not open audio file!");
}

void AudioPlayer::play()
{
    //@ToDo: por ahora simulamos la reproducción correcta
    if(isOpen) isPlaying = true;
    else log("Error: Audio file playback, could not open the audio file.");
}

void AudioPlayer::stop()
{
    if(isPlaying) isPlaying = false;
}

bool AudioPlayer::getOpenStatus()
{
    return isOpen;
}

bool AudioPlayer::getPlaybackStatus()
{
    return isPlaying;
}

void AudioPlayer::setVolume(float value)
{
    volume = value;
}

float AudioPlayer::getVolume()
{
    return volume;
}

void AudioPlayer::log(string message, string filePath)
{
    ofstream logFile;
    logFile.open(filePath, ofstream::app);
    logFile << message << endl;
    logFile.close();
}