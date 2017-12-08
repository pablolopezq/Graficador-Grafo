#ifndef VERTICE_H
#define VERTICE_H

#include <string>

using namespace std;

class ListaAristas;
class Arista;

class Vertice
{
public:
    Vertice(string nombre);
    Vertice(string nombre, int posX, int posY);

    void setNombre(string nombre);
    void setPos(int posX, int posY);
    int getPosX();
    int getPosY();
    Arista* agregarArista(string nombreDestino, int peso);
    Arista* eliminarArista(string nombreDestino);
    Arista* obtenerArista(string nombreDestino);

    string nombre;
    ListaAristas* listaAristas;
    int posX;
    int posY;
};

#endif // VERTICE_H
