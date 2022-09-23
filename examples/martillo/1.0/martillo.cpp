#include <iostream>
#include <string>
using namespace std;

class Martillo
{
    private:
        string calidad;
        string materialDelMango;
        string materialDeCabeza;
        int numeroDeSerie;
        
    public:
        //método constructor: se invoca al crear una instancia u objeto
        //de esta clase
        Martillo(string c, string mDM, string mDC, int nDS)
        {
            cout << "Me construyo..." << endl;
            calidad = c;
            materialDelMango = mDM;
            materialDeCabeza = mDC;
            numeroDeSerie = nDS;
        }
        //método destructor: se invoca al destruir una instancia u objeto
        //de esta clase 
        ~Martillo()
        {
            cout << "Me destruyo..." << endl;
        }
        
        void martillar()
        {
            cout << "Mi calidad es de: " << calidad << endl;
            cout << "Mi mango es de: " << materialDelMango << endl;
            cout << "Mi cabeza es de: " << materialDeCabeza << endl;
            cout << "Mi numero de serie es: " << numeroDeSerie << endl;
            cout << "Estoy martillando" << endl;
        }
};

int main()
{
    //Creación del objeto martillo, 
    //se invoca al constructor con parámetros de la clase Martillo:
    Martillo objetoMartillo = Martillo("primera", "nogal", "acero", 12345);

    //LLamar a la operación (método o mensaje) del objeto martillo
    objetoMartillo.martillar();

    return 0;
}
