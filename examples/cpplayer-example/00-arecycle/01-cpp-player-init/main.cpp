#include <iostream>
#include <AudioPlayer.hpp>

int main()
{
    AudioPlayer player;
    player.open("./resources/orchestral.ogg");
    player.play();
    player.setVolume(4);
    
    // Wait until the user presses 'enter' key
    cout << "...........Playing....press enter to stop and exit........." << endl;
    cin.ignore(10000, '\n');
    player.stop();
    player.stop();
    return EXIT_SUCCESS;
}