#include <iostream>
#include <AudioPlayer.hpp>

int main()
{
    AudioPlayer player;
    player.open("orchestral.ogg");
    player.play();
    player.setVolume(4);
    
    // Wait until the user presses 'enter' key
    std::cout << "    ...........Playing....press enter to stop and exit........." << std::endl;
    std::cin.ignore(10000, '\n');
    player.stop();

    return EXIT_SUCCESS;
}