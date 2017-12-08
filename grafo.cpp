#include "grafo.h"
#include "vertice.h"
#include "arista.h"
#include "listavertices.h"
#include "listaaristas.h"
#include <iostream>

using namespace std;

Grafo::Grafo()
{
    listaVertices = new ListaVertices();
    numVertices = 0;
}

Vertice* Grafo::obtenerVertice(string nombreVertice)
{
    return listaVertices->obtener(nombreVertice);
}

bool Grafo::existeVertice(string nombreVertice)
{
    if(listaVertices->obtener(nombreVertice) != nullptr)
        return true;
    return false;
}

Vertice* Grafo::agregarVertice(string nombreVertice)
{
    if(existeVertice(nombreVertice))
        return nullptr;
    else{
        Vertice* nuevoVertice = new Vertice(nombreVertice);
        listaVertices->agregar(nuevoVertice);
        numVertices++;
        return nuevoVertice;
    }
}

Vertice* Grafo::agregarVertice(Vertice *nuevoVertice)
{
    if(existeVertice(nuevoVertice->nombre))
        return nullptr;
    else{
        listaVertices->agregar(nuevoVertice);
        numVertices++;
        return nuevoVertice;
    }
}

Vertice* Grafo::eliminarVertice(string nombreVertice)
{
    if(!existeVertice(nombreVertice))
    {
        cout << "no existe" << endl;
        return nullptr;
    }
    else{
        numVertices--;
        return listaVertices->eliminar(nombreVertice);
    }
}

Vertice* Grafo::obtenerVerticePos(int pos)
{
    return listaVertices->obtenerPos(pos);
}

int Grafo::getNumVertices()
{
    return this->numVertices;
}

Grafo* Grafo::copiarGrafo()
{
    Grafo* newGraph = new Grafo();
    for(int i = 0; i < this->numVertices; i++)
    {
        Vertice* tmp = this->obtenerVerticePos(i);
        Vertice* tmp1 = new Vertice(tmp->nombre, tmp->posX, tmp->posY);
        newGraph->agregarVertice(tmp1);
        for(int h = 0; h < tmp->listaAristas->getCantElementos(); h++)
        {
            Arista* temp = tmp->listaAristas->obtenerAristaPos(h);
            tmp1->agregarArista(temp->destino->nombre, temp->peso);
        }
    }
    return newGraph;
}

Grafo* Grafo::copiarGrafoVerts()
{
    Grafo* newGraph = new Grafo();
    for(int i = 0; i < this->numVertices; i++)
    {
        Vertice* tmp = this->obtenerVerticePos(i);
        Vertice* tmp1 = new Vertice(tmp->nombre, tmp->posX, tmp->posY);
        newGraph->agregarVertice(tmp1);
    }
    return newGraph;
}

void Grafo::BFS(string nombreOrigen)
{
    int level = 1;
    int pairCont = 0;
    this->pairsBFS = new Pair[numVertices+1];

    ListaVertices* frontier = new ListaVertices();
    ListaVertices* visitados = new ListaVertices();

    Vertice* tmp = new Vertice(nombreOrigen);
    frontier->agregar(tmp);
    visitados->agregar(tmp);
    pairsBFS[pairCont].nombre = nombreOrigen;
    pairsBFS[pairCont].level = 0;
    pairCont = 1;

    while(!frontier->isEmpty())
    {
        ListaAristas* listaAdj = new ListaAristas();
        ListaVertices* next = new ListaVertices();
        for(int u = 0; u < frontier->getCantElementos(); u++)
        {
            string nombrePadre = frontier->obtenerPos(u)->nombre;
            cout << nombrePadre << endl;
            listaAdj = obtenerVerticePos(u)->listaAristas;
            for(int v = 0; v < listaAdj->getCantElementos(); v++)
            {
                //cout << "b" << endl;
                string nombre = listaAdj->obtenerAristaPos(v)->destino->nombre;
                cout << nombre << endl;
                tmp = new Vertice(nombre);
                if(!visitados->existe(nombre))
                {
                    cout << "x" << endl;
                    visitados->agregar(tmp);
                    next->agregar(tmp);
                    pairsBFS[pairCont].level = level;
                    pairsBFS[pairCont].nombre = nombre;
                    pairsBFS[pairCont].padre = nombrePadre;
                    pairCont++;
                }
            }
        }
        frontier = next;
        level++;
    }
    cout << "test: " << level-1 << endl;
    this->bfsLevels = level-1;
}

bool Grafo::pathExists(Vertice* origen, string nombreDestino)
{
    Arista* temp = new Arista(nombreDestino, 0);
    ListaAristas* tmp = origen->listaAristas;
    if(tmp->existe(temp))
    {
        return true;
    }
    return false;
}

Grafo* Grafo::floydWarshall()
{
    Grafo* tmpGraph = this->copiarGrafo();
    int numeroVerts = tmpGraph->getNumVertices();
    int pesos[numeroVerts][numeroVerts];
    for(int i = 0; i < numeroVerts; i++)
    {
        Vertice* temp = tmpGraph->obtenerVerticePos(i);
        for(int h = 0; h < numeroVerts; h++)
        {
            Vertice* temp1 = tmpGraph->obtenerVerticePos(h);
            Arista* add = temp->obtenerArista(temp1->nombre);
            if(add != nullptr)
            {
                pesos[i][h] = add->getPeso();
            }
            else
            {
                pesos[i][h] = 99999;
            }
        }
    }
    for(int x = 0; x < numeroVerts; x++)
    {
        Vertice* pivot = tmpGraph->obtenerVerticePos(x);
        for(int y = 0; y < numeroVerts; y++)
        {
            Vertice* from = tmpGraph->obtenerVerticePos(y);
            for(int z = 0; z < numeroVerts; z++)
            {
                Vertice* to = tmpGraph->obtenerVerticePos(z);
                if(pathExists(from, pivot->nombre) && pathExists(pivot, to->nombre))
                {
                    int pesoNuevo = pesos[y][x] + pesos[x][z];
                    int pesoViejo = pesos[y][z];
                    if(pesoNuevo < pesoViejo)
                        pesos[z][y] = pesoNuevo;
                }
            }
        }
    }
    Grafo* newGraph = this->copiarGrafoVerts();
    for(int q = 0; q < newGraph->getNumVertices(); q++)
    {
        Vertice* from = newGraph->obtenerVerticePos(q);
        for(int w = 0; w < newGraph->getNumVertices(); w++)
        {
            Vertice* to = newGraph->obtenerVerticePos(q);
            if(q != w && pesos[q][w] != 99999)
            {
                from->agregarArista(to->nombre, pesos[q][w]);
            }
        }
    }
    return newGraph;
}

void Grafo::DFS(string nombreOrigen)
{
    ListaVertices* visited = new ListaVertices();
}
