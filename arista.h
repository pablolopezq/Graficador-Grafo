#ifndef ARISTA_H
#define ARISTA_H

#include <string>

using namespace std;

class Vertice;

class Arista
{
public:
    Arista(string nombreDestino, int peso);

    Vertice* destino;
    int peso;

    void setPeso(int peso);
    int getPeso();
};

#endif // ARISTA_H
