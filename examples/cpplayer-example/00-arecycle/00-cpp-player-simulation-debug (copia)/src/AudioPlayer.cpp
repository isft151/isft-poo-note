#include <AudioPlayer.hpp>

AudioPlayer::AudioPlayer()
{
    #ifdef __DEBUG__
        cout << "------------------------Start Constructor Section------------------------------" << endl;
        cout << "Create AudioPlayer." << endl;
    #endif // __DEBUG__
    
    #ifdef __DEBUG__
        // cout << "-----------------------------------------------------------" << endl;
        cout << "  Set members attributes:" << endl;
    #endif // __DEBUG__
    setVolume(10);
    isOpen = false;
    isPlaying = false;
    #ifdef __DEBUG__
        cout << "  Set members attributes:" << endl;
        cout << "  isOpen: " << isOpen <<endl;
        cout << "  isPlaying: " << isPlaying <<endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "------------------------End Constructor Section------------------------------" << endl << endl;
        cout << "------------------------Start Operation's Section------------------------------" << endl << endl;
    #endif // __DEBUG__
}

AudioPlayer::~AudioPlayer()
{
    #ifdef __DEBUG__
        cout << "------------------------End Operation's Section------------------------------" << endl << endl;      
        cout << "------------------------Start Destructor Section------------------------------" << endl;
        cout << "Destroy AudioPlayer." << endl;
        cout << "------------------------End Destructor Section------------------------------" << endl << endl;
    #endif // __DEBUG__
}

void AudioPlayer::showError(string message, string message2 = "")
{
    cerr << message << ' ' << message2 << endl;
    exit(EXIT_FAILURE);
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
        cout << "  isPlaying: " << isPlaying <<endl;
        cout << "-----------------------------------------------------------" << endl << endl;
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
    else
    {
        showError("Error: There is no open audio file!");
    }

    #ifdef __DEBUG__
        cout << "  isOpen: " << isOpen <<endl;
        cout << "  isPlaying: " << isPlaying <<endl;
        cout << "-----------------------------------------------------------" << endl << endl;
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
    else
    {
        showError("Error: No audio file is playing!");
    }

    #ifdef __DEBUG__
        cout << "  isOpen: " << isOpen <<endl;
        cout << "  isPlaying: " << isPlaying <<endl;
        cout << "-----------------------------------------------------------" << endl << endl;
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
        cout << "    Set audio volume to: " << volume <<endl;
        cout << "----------------------------------------------------------" << endl << endl;
    #endif // __DEBUG__
}
