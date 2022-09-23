#include <AudioPlayer.hpp>

AudioPlayer::AudioPlayer()
{
    isOpen = false;
    isPlay = false;
    #ifdef __DEBUG__
        cout << "Create AudioPlayer" << endl;
    #endif // __DEBUG__
}

AudioPlayer::~AudioPlayer()
{
    #ifdef __DEBUG__
        cout << "Destroy AudioPlayer" << endl;
    #endif // __DEBUG__
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
    isOpen ? audioFileHandler.play() : showError("Error: There is no open audio file!");
    isPlay = true;
}

void AudioPlayer::stop() 
{
    isPlay ? audioFileHandler.stop() : showError("Error: No audio file is playing!");
    isPlay = false;
}

void AudioPlayer::setVolume(float value) 
{
    audioFileHandler.setVolume(value);
}
