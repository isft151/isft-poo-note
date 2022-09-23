#include <iostream>
#include <string>
using namespace std;

class Hammer
{
    private:
        string quality;
        string handleMaterial;
        string headMaterial;
        string use;
        int serialNumber;        
    public:
        //método constructor: se invoca al crear una instancia u objeto
        //de esta clase
        Hammer(string q, string haM, string heM, int sN)
        {
            cout << "I build myself..." << endl  << endl;
            quality = q;
            handleMaterial = haM;
            headMaterial = heM;
            serialNumber = sN;
        }
        //método destructor: se invoca al destruir una instancia u objeto
        //de esta clase 
        ~Hammer()
        {
            cout  << endl << "I destroy myself..." << endl ;
        }
        //el martillo debería permitir que alguien lo use para otra cosa
        //en este caso a fines del ejemplo se espera un string por parámetro
        //en un caso real se podrían esperar un objeto del tipo Uso y soportar
        //un conjunto de usos permitidos y también objetivos a martillar...
        void useTo(string u)
        {
            use = u;
        }
        //este método solo se crea con un objetivo didáctico
        //para hacer visible el estado de los atributos internos que
        //a los cuales no debería accederse directamente, 
        //sino a través de un método.
        void showState()
        {
            cout << "I am a Hammer" << endl;
            cout << "Mi quality is: " << quality << endl;
            cout << "My handle is made of: " << handleMaterial << endl;
            cout << "My head is made of: " << headMaterial << endl;
            cout << "My serial number is: " << serialNumber << endl;
            cout << "They're using me to: " << use << endl;
        }
};

int main()
{
    //Creación del objeto martillo, 
    //se invoca al constructor con parámetros de la clase Martillo:
    Hammer hammerObject = Hammer("top", "walnut", "steel", 12345);

    //LLamar a la operación (método o mensaje) del objeto martillo
    hammerObject.useTo("hammer");
    hammerObject.showState();

    return 0;
}
