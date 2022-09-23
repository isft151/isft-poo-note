#include <AudioPlayer.h>

AudioPlayer::AudioPlayer()
{
    isOpen = false;
    isPlay = false;
    audioFileHandler = new sf::Music();
}

AudioPlayer::~AudioPlayer()
{
    delete audioFileHandler;
}

void AudioPlayer::showError(string message, string message2 = "")
{
    cerr << message << ' ' << message2 << endl;
    exit(EXIT_FAILURE);
}

bool AudioPlayer::open(string filePath) 
{
    return isOpen = audioFileHandler->openFromFile(filePath);
}

void AudioPlayer::play() 
{
    isOpen ? audioFileHandler->play() : showError("Error opening file");
    isPlay = true;
}

void AudioPlayer::stop() 
{
    isPlay ? audioFileHandler->stop() : showError("No files playing");
    isPlay = false;
}

void AudioPlayer::setVolume(float value) 
{
    audioFileHandler->setVolume(value);
}
