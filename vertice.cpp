#include "arista.h"
#include "vertice.h"
#include "listaaristas.h"

Vertice::Vertice(string nombre)
{
    this->nombre = nombre;
    this->listaAristas = new ListaAristas();
}

Vertice::Vertice(string nombre, int posX, int posY)
{
    this->nombre = nombre;
    this->posX = posX;
    this->posY = posY;
    this->listaAristas = new ListaAristas();
}

void Vertice::setNombre(string nombre)
{
    this->nombre = nombre;
}

Arista* Vertice::agregarArista(string nombreDestino, int peso)
{
    Arista* destino = new Arista(nombreDestino, peso);
    if(this->listaAristas->obtener(nombreDestino) != nullptr)
        return nullptr;
    this->listaAristas->agregar(destino);
    return destino;
}

Arista* Vertice::eliminarArista(string nombreDestino)
{
    Arista* destino = new Arista(nombreDestino, 0);
    if(!listaAristas->existe(destino))
        return nullptr;
    return this->listaAristas->eliminar(nombreDestino);
}

Arista* Vertice::obtenerArista(string nombreDestino)
{
    return this->listaAristas->obtener(nombreDestino);
}

void Vertice::setPos(int posX, int posY)
{
    this->posX = posX;
    this->posY = posY;
}
int Vertice::getPosX()
{
    return this->posX;
}
int Vertice::getPosY()
{
    return this->posY;
}
