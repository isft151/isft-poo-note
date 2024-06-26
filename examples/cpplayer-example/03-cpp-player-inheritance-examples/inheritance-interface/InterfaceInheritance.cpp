#include <iostream>
#include <fstream>
#include <typeinfo>
using namespace std;
//Player Interface:
class Player
{
    public:
        virtual void open(string filePath) = 0;
        virtual void play() = 0;
        virtual void stop() = 0;
        virtual void setVolume(float value) = 0;
};

//Pitchable Interface:
class Pitchable
{
    public:
        virtual void setPitch(float pitch) = 0;
};

//VLC concrete class
class VLC : public Player, public Pitchable
{
    public:
        VLC() 
        { 
            cout << "The VLC constructor was invoked." << endl;
            isOpen = false; 
            isPlaying = false;
            setVolume(10);
        }
        ~VLC()
        {
            cout << "The VLC destructor was invoked." << endl;
        }
    //Player Interface:
        void open(string filePath)
        {
            //@ToDo: por ahora simulamos la apertura correcta
            isOpen = true;
            cout << "The audiofile: " << filePath << " is open." << endl;
        }
        void play()
        {
            //@ToDo: por ahora simulamos la reproducción correcta
            if(isOpen) isPlaying = true;
            cout << "The audiofile is playing." << endl;
        }   
        void stop()
        {
            //@ToDo: por ahora simulamos la detención correcta
            if(isPlaying) isPlaying = false;
            cout << "The audiofile is stopped." << endl;
        }
        void setVolume(float value)
        {
            volume = value;
            cout << "The volume value is: " << volume << endl;
        }
    //Pitchable Interface:
        void setPitch(float value)
        {
            pitch = value;
            cout << "The pitch value is: " << pitch << endl;
        }

    private:
        bool isOpen;
        bool isPlaying;
        float volume;
        float pitch;
};

void testPlayer(Player& player)
{
    cout << "Start test of Player: " << endl;
    player.play();
    cout << "End test of Player" << endl;
    cout << endl;
}

int main()
{
    //NO SE PUEDE CREAR UN OBJETO O INSTANCIA DE UNA INTERFAZ:
    //Player player;//NO!
    
    VLC vlcPlayer;
    cout << endl;
    vlcPlayer.open("./resources/orchestral.ogg");
    vlcPlayer.play();
    vlcPlayer.setVolume(13);
    cout << endl;

    testPlayer(vlcPlayer);
    return EXIT_SUCCESS;
} 