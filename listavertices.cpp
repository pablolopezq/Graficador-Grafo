#include "listavertices.h"
#include "vertice.h"
#include <iostream>
using namespace std;

ListaVertices::ListaVertices()
{
    this->cantElementos = 0;
    this->first = NULL;
    this->last = NULL;
}

NodeVertice::NodeVertice(Vertice* vertice)
{
    this->vertice = vertice;
    this->next = NULL;
    this->prev = NULL;
}

Vertice* ListaVertices::agregar(Vertice* nuevoVertice)
{
    NodeVertice* nuevo = new NodeVertice(nuevoVertice);
    if(cantElementos == 0)
    {
        first = nuevo;
        last = nuevo;
    }
    else
    {
        last->next = nuevo;
        nuevo->prev = last;
        last = nuevo;
    }
    cantElementos++;
    return nuevo->vertice;
}

Vertice* ListaVertices::obtener(string nombreVertice)
{
    NodeVertice* tmp = first;
    for(int i = 0; i < cantElementos; i++)
    {
        if(tmp->vertice->nombre == nombreVertice)
            return tmp->vertice;
        else
        {
            tmp = tmp->next;
        }
    }
    return nullptr;
}

NodeVertice* ListaVertices::obtenerNodo(string nombreVertice)
{
    NodeVertice* tmp = first;
    cont = 0;
    for(int i = 0; i < cantElementos; i++)
    {
        if(tmp->vertice->nombre == nombreVertice)
            return tmp;
        else
        {
            tmp = tmp->next;
            cont++;
        }
    }
    return nullptr;
}

Vertice* ListaVertices::eliminar(string nombreVertice)
{
    NodeVertice* tmp = obtenerNodo(nombreVertice);

    if(cantElementos == 1)
    {
        first = NULL;
        last = NULL;
    }
    else if(cont == 0)
    {
        first = tmp->next;
        tmp->next->prev = NULL;
    }
    else if(cont == cantElementos-1)
    {
        tmp->prev->next = tmp->next;
        last = tmp->prev;
    }
    else
    {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }

    //NodeVertice* eliminate = tmp;
    NodeVertice* retorno = tmp;
    cantElementos--;
    //delete eliminate;
    return retorno->vertice;
}

bool ListaVertices::existe(string nombreVertice)
{
    NodeVertice* tmp = first;
    for(int i = 0; i < cantElementos; i++)
    {
        if(tmp->vertice->nombre == nombreVertice)
            return true;
        tmp = tmp->next;
    }
    return false;
}

Vertice* ListaVertices::obtenerPos(int pos)
{
    if(pos < 0 || pos > cantElementos)
    {
        return nullptr;
    }
    else
    {
        NodeVertice* tmp = first;
        for(int i = 0; i < pos; i++)
        {
            tmp = tmp->next;
        }
        return tmp->vertice;
    }
}

bool ListaVertices::isEmpty()
{
    if(cantElementos == 0)
        return true;
    else
        return false;
}

int ListaVertices::getCantElementos()
{
    return this->cantElementos;
}
