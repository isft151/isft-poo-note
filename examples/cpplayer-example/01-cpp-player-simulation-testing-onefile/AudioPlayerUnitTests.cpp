#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include <iostream>
#include <fstream>
using namespace std;
class AudioPlayer
{
   public:
        AudioPlayer() 
        { 
            isOpen = false; 
            isPlaying = false;
            setVolume(10);
        }
        ~AudioPlayer(){}
        void open(string filePath)
        {
            //@ToDo: por ahora simulamos la apertura correcta
            ifstream file(filePath.c_str());
            if(file.good())isOpen = true;
            else log("Error: Could not open audio file!");
        }
        void play()
        {
            //@ToDo: por ahora simulamos la reproducción correcta
            if(isOpen) isPlaying = true;
            else log("Error: Audio file playback, could not open the audio file.");
        }   
        void stop()
        {
            if(isPlaying) isPlaying = false;
        }
        bool getOpenStatus()
        {
            return isOpen;
        }
        bool getPlaybackStatus()
        {
            return isPlaying;
        }
        void setVolume(float value)
        {
            volume = value;
        }
        float getVolume()
        {
            return volume;
        }

   private:
        float volume;
        bool isOpen;
        bool isPlaying;
        void log(string message, string filePath = "log.txt")
        {
            ofstream logFile;
            logFile.open(filePath, ofstream::app);
            logFile << message << endl;
            logFile.close();
        }
};
 
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
   string filePath = "./resources/orchestral.ogg";
   AudioPlayer player;
 
   // Act
   player.open(filePath);
      
   // Assert
   REQUIRE( player.getOpenStatus() == true );
}

TEST_CASE( "Incorrect opening of audio files", "[AudioPlayer open]" )
{
   // Arrange
   string filePath = "./resources/orchestral.mp3";
   AudioPlayer player;
 
   // Act
   player.open(filePath);
      
   // Assert
   REQUIRE( player.getOpenStatus() == false );
}

TEST_CASE( "Correct playing of audio files", "[AudioPlayer play]" ) 
{
    // Arrange
    string filePath = "./resources/orchestral.ogg";
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
    string filePath = "./resources/orchestral.ogg";
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
    string filePath = "./resources/orchestral.mp3";
    AudioPlayer player;

    // Act
    player.open(filePath);
    ifstream file("log.txt");

    // Assert
    REQUIRE( file.good() == true );
}