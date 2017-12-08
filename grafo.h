#ifndef GRAFO_H
#define GRAFO_H

#include <string>

using namespace std;

class Vertice;
class ListaVertices;
class ListaAristas;

struct Pair
{
    int level;
    string nombre;
    string padre;
};

class Grafo
{
private:
    int numVertices;
    ListaVertices* listaVertices;

public:
    Grafo();

    Pair* pairsBFS;
    int bfsLevels;

    Vertice* agregarVertice(string nombreVertice);
    Vertice* agregarVertice(Vertice* nuevoVertice);
    Vertice* eliminarVertice(string nombreVertice);
    Vertice* obtenerVertice(string nombreVertice);
    Vertice* obtenerVerticePos(int pos);
    bool existeVertice(string nombreVertice);
    int getNumVertices();
    void BFS(string nombreOrigen);
    //void DFS(string nombreOrigen);
    //Grafo* dijsktra();
    Grafo* copiarGrafo();
    Grafo* copiarGrafoVerts();
    Grafo* floydWarshall();
    bool pathExists(Vertice* origen, string nombreDestino);
};

#endif // GRAFO_H
