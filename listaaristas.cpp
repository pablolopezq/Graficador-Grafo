#include "listaaristas.h"
#include "arista.h"
#include "vertice.h"

ListaAristas::ListaAristas()
{
    this->cantElementos = 0;
    this->first = NULL;
    this->last = NULL;
}

NodeArista::NodeArista(Arista* arista)
{
    this->arista = arista;
    this->next = NULL;
    this->prev = NULL;
}

Arista* ListaAristas::agregar(Arista *nuevaArista)
{
    NodeArista* nuevo = new NodeArista(nuevaArista);
    if(cantElementos == 0)
    {
        nuevo->next = first;
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
    return nuevo->arista;
}

NodeArista* ListaAristas::obtenerNodoArista(string nombreDestino)
{
    NodeArista* tmp = first;
    cont = 0;
    for(int i = 0; i < cantElementos; i++)
    {
        if(tmp->arista->destino->nombre == nombreDestino)
            return tmp;
        else
        {
            tmp = tmp->next;
            cont++;
        }
    }
    return nullptr;
}

Arista* ListaAristas::eliminar(string nombreDestino)
{
    NodeArista* tmp = obtenerNodoArista(nombreDestino);

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
    NodeArista* retorno = tmp;
    cantElementos--;
    //delete eliminate;
    return retorno->arista;
}

Arista* ListaAristas::obtener(string nombreDestino)
{
    NodeArista* tmp = first;
    for(int i = 0; i < cantElementos; i++)
    {
        if(tmp->arista->destino->nombre == nombreDestino)
            return tmp->arista;
        else
        {
            tmp = tmp->next;
        }
    }
    return nullptr;
}

bool ListaAristas::existe(Arista *arista)
{
    NodeArista* tmp = first;
    for(int i = 0; i < cantElementos; i++)
    {
        if(tmp->arista->destino->nombre == arista->destino->nombre)
            return true;
        tmp = tmp->next;
    }
    return false;
}

int ListaAristas::getCantElementos()
{
    return this->cantElementos;
}

Arista* ListaAristas::obtenerAristaPos(int pos)
{
    if(pos < 0 || pos > cantElementos)
    {
        return nullptr;
    }
    else
    {
        NodeArista* tmp = first;
        for(int i = 0; i < pos; i++)
        {
            tmp = tmp->next;
        }
        return tmp->arista;
    }
}
