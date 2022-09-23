#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <AudioPlayer.hpp>
#include <catch.hpp>
#include <iostream>
#include <fstream>
using namespace std;
 
TEST_CASE( "AudioPlayer create instance", "[AudioPlayer new]" ) 
{
    // Arrange
    AudioPlayer* player;

    // Act
    player = new AudioPlayer();
    bool isAudioPlayer = ( dynamic_cast<AudioPlayer*> (player) != nullptr );
    // bool isAudioPlayer = dynamic_cast<AudioPlayer*> (player);
    
    // Assert
    REQUIRE( isAudioPlayer == true );
}

TEST_CASE( "Correct opening of audio files", "[AudioPlayer open]" )
{
   // Arrange
   string filePath = "../resources/orchestral.ogg";
   AudioPlayer player;
 
   // Act
   player.open(filePath);
      
   // Assert
   REQUIRE( player.getOpenStatus() == true );
}

TEST_CASE( "Correct playing of audio files", "[AudioPlayer play]" ) 
{
    // Arrange
    string filePath = "../resources/orchestral.ogg";
    AudioPlayer player;
    player.open(filePath);

    // Act
    player.play();
    
    // Assert
    REQUIRE( player.getPlaybackStatus() == true );
}

TEST_CASE( "Correct stopping of audio files", "[AudioPlayer stop]" ) 
{
    // Arrange
    string filePath = "../resources/orchestral.ogg";
    AudioPlayer player;
    player.open(filePath);
    player.play();

    // Act
    player.stop();
    
    // Assert
    REQUIRE( player.getPlaybackStatus() == false );
}

TEST_CASE( "Correct volume set of audio file", "[AudioPlayer setVolume]" ) 
{
    // Arrange
    AudioPlayer player;

    // Act
    player.setVolume(4.5);
    
    // Assert
    REQUIRE( player.getVolume() == 4.5 );
}

TEST_CASE( "Successful creation of the log.txt file by the log method", "[AudioPlayer log]" ) 
{
    // Arrange
    string filePath = "./orchestral.mp3";//log error
    AudioPlayer player;

    // Act
    player.open(filePath);
    ifstream file("./log/log.txt");

    // Assert
    REQUIRE( file.good() == true );
}