#include <iostream>
#include <string>
using namespace std;

class Martillo
{
    private:
        string calidad;
        string materialDelMango;
        string materialDeCabeza;
        string uso;
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
        //el martillo debería permitir que alguien lo use para otra cosa
        //en este caso a fines del ejemplo se espera un string por parámetro
        //en un caso real se podrían esperar un objeto del tipo Uso y soportar
        //un conjunto de usos permitidos y también objetivos a martillar...
        void usarPara(string u)
        {
            uso = u;
        }
        //este método solo se crea con un objetivo didáctico
        //para hacer visible el estado de los atributos internos que
        //a los cuales no debería accederse directamente, 
        //sino a través de un método.
        void mostrarEstado()
        {
            cout << "Soy un martillo " << endl;
            cout << "Mi calidad es de: " << calidad << endl;
            cout << "Mi mango es de: " << materialDelMango << endl;
            cout << "Mi cabeza es de: " << materialDeCabeza << endl;
            cout << "Mi numero de serie es: " << numeroDeSerie << endl;
            cout << "Me están usando para: " << uso << endl;
        }
};

int main()
{
    //Creación del objeto martillo, 
    //se invoca al constructor con parámetros de la clase Martillo:
    Martillo objetoMartillo = Martillo("primera", "nogal", "acero", 12345);

    //LLamar a la operación (método o mensaje) del objeto martillo
    objetoMartillo.usarPara("martillar");
    objetoMartillo.mostrarEstado();

    return 0;
}
