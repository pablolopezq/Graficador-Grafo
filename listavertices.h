#ifndef LISTAVERTICES_H
#define LISTAVERTICES_H

#include <string>

using namespace std;

class Vertice;

struct NodeVertice
{
    Vertice* vertice;
    NodeVertice* next;
    NodeVertice* prev;

    NodeVertice(Vertice* vertice);
};

class ListaVertices
{
private:
    int cantElementos;
    NodeVertice* first;
    NodeVertice* last;
    int cont;

public:
    ListaVertices();

    Vertice* agregar(Vertice* nuevoVertice);
    Vertice* eliminar(string nombreVertice);
    Vertice* obtener(string nombreVertice);
    NodeVertice* obtenerNodo(string nombreVertice);
    Vertice* obtenerPos(int pos);
    bool existe(string nombreVertice);
    bool isEmpty();
    int getCantElementos();
};

#endif // LISTAVERTICES_H
