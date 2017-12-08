#ifndef LISTAARISTAS_H
#define LISTAARISTAS_H

#include <string>

using namespace std;

class Arista;

struct NodeArista
{
    Arista* arista;
    NodeArista* next;
    NodeArista* prev;

    NodeArista(Arista* arista);
};

class ListaAristas
{
private:
    int cantElementos;
    NodeArista* first;
    NodeArista* last;
    int cont;

public:
    ListaAristas();

    Arista* obtener(string nombreDestino);
    Arista* agregar(Arista* nuevaArista);
    Arista* eliminar(string nombreDestino);
    Arista* obtenerAristaPos(int pos);
    bool existe(Arista* arista);
    NodeArista* obtenerNodoArista(string nombreDestino);
    int getCantElementos();
};

#endif // LISTAARISTAS_H
