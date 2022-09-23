// #define __DEBUG__
#include <iostream>
#include <AudioPlayer.hpp>

int main()
{
    AudioPlayer player;
    player.open("resources/orchestral.ogg");
    player.play();
    player.setVolume(4);
    
    // Wait until the user presses 'enter' key
    std::cout << "Press enter to exit..." << std::endl;
    std::cin.ignore(10000, '\n');
    player.stop();

    return EXIT_SUCCESS;
}