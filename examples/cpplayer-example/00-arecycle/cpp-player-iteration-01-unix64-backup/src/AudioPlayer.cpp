#include <AudioPlayer.hpp>

AudioPlayer::AudioPlayer()
{
    isOpen = false;
    isPlay = false;
    cout << "Create AudioPlayer" << endl;
}

AudioPlayer::~AudioPlayer()
{
    cout << "Destroy AudioPlayer" << endl;
}

void AudioPlayer::showError(string message, string message2 = "")
{
    cerr << message << ' ' << message2 << endl;
    exit(EXIT_FAILURE);
}

bool AudioPlayer::open(string filePath) 
{
    return isOpen = audioFileHandler.openFromFile(filePath);
}

void AudioPlayer::play() 
{
    isOpen ? audioFileHandler.play() : showError("Error opening file");
    isPlay = true;
}

void AudioPlayer::stop() 
{
    isPlay ? audioFileHandler.stop() : showError("No files playing");
    isPlay = false;
}

void AudioPlayer::setVolume(float value) 
{
    audioFileHandler.setVolume(value);
}
