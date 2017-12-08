#include "arista.h"
#include "vertice.h"

Arista::Arista(string nombre, int peso)
{
    this->destino = new Vertice(nombre);
    this->peso = peso;
}

void Arista::setPeso(int peso)
{
    this->peso = peso;
}

int Arista::getPeso()
{
    return this->peso;
}
