#include <AudioPlayer.hpp>

AudioPlayer::AudioPlayer()
{
    #ifdef __DEBUG__
        cout << "Create AudioPlayer." << endl;
    #endif // __DEBUG__

    isOpen = false;
    isPlaying = false;
    setVolume(10);

    #ifdef __DEBUG__
        cout << "  Set members attributes:" << endl;
        cout << "  isOpen: " << isOpen << endl;
        cout << "  isPlaying: " << isPlaying << endl;
        cout << "  Volumen: " << volume << endl << endl;
    #endif // __DEBUG__
}

AudioPlayer::~AudioPlayer()
{
    #ifdef __DEBUG__
        cout << "Destroy AudioPlayer." << endl << endl;
    #endif // __DEBUG__
}

bool AudioPlayer::open(string filePath) 
{
    #ifdef __DEBUG__
        cout << "-------------------------open method-----------------------" << endl;
        cout << "  isOpen = audioFileHandler.openFromFile("+filePath+");" << endl;
    #endif // __DEBUG__
    
    isOpen = true;

    #ifdef __DEBUG__
        cout << "  isOpen: " << isOpen <<endl;
        cout << "  isPlaying: " << isPlaying << endl << endl;
    #endif // __DEBUG__

    return isOpen;
}

bool AudioPlayer::play() 
{
    if(isOpen)
    {
        #ifdef __DEBUG__
            cout << "-------------------------play method-----------------------" << endl;
            cout << "  isPlaying = audioFileHandler.play();" << endl;
        #endif // __DEBUG__

        isPlaying = true;
    } 

    #ifdef __DEBUG__
        cout << "  isOpen: " << isOpen << endl;
        cout << "  isPlaying: " << isPlaying << endl << endl;
    #endif // __DEBUG__

    return isPlaying;
}

bool AudioPlayer::stop() 
{
    if(isPlaying) 
    {
        #ifdef __DEBUG__
            cout << "------------------------stop method-----------------------" << endl;
            cout << "  isPlaying = audioFileHandler.stop();" << endl;
        #endif // __DEBUG__
        isPlaying = false;
    }

    #ifdef __DEBUG__
        cout << "  isOpen: " << isOpen << endl;
        cout << "  isPlaying: " << isPlaying << endl << endl;
    #endif // __DEBUG__

    return isPlaying;
}

void AudioPlayer::setVolume(float value) 
{
    #ifdef __DEBUG__
        cout << "----------------------setVolume method--------------------" << endl;
        cout << "  audioFileHandler.setVolume(value);" << endl;
    #endif // __DEBUG__

    volume = value;

    #ifdef __DEBUG__
        cout << "    Set audio volume to: " << volume << endl << endl;
    #endif // __DEBUG__
}

float AudioPlayer::getVolume() 
{
    #ifdef __DEBUG__
        cout << "----------------------getVolume method--------------------" << endl;
        cout << "  audioFileHandler.getVolume();"  << endl << endl;
    #endif // __DEBUG__

    return volume;
}