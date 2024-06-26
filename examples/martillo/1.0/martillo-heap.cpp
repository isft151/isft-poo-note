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
            setCalidad(c);
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

        //getter de calidad
        string getCalidad() const {
            return calidad;
        }

        //setter de calidad
        void setCalidad(string calidad_) {
            calidad = calidad_ + " guachin";
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
    Martillo* objetoMartillo = new Martillo("primera", "nogal", "acero", 12345);

    //LLamar a la operación (método o mensaje) del objeto martillo
    objetoMartillo->martillar();

    //NO ANDA CALIDAD ES PRIVADA
    // objetoMartillo.calidad = "primera";
    //A TRAVÉS DE UN SETTER
    objetoMartillo->setCalidad("primera");

    objetoMartillo->martillar();

    delete objetoMartillo;
    return 0;
}
