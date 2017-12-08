#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <Window.hpp>
#include <Graphics/Export.hpp>
#include <Graphics.hpp>
#include <Graphics/Drawable.hpp>
#include <Graphics/CircleShape.hpp>
#include <Graphics/RenderWindow.hpp>
#include <Window/VideoMode.hpp>
#include <Window/WindowStyle.hpp>
#include <Window/Event.hpp>
#include "textedit.h"
#include "lineshape.h"
#include "grafo.h"
#include "vertice.h"
#include "arista.h"
#include "listavertices.h"
#include "listaaristas.h"
#include <iostream>
#include <string>

using namespace std;

class userInterface
{
private:
    sf::RenderWindow window;
    sf::CircleShape circle;
    sf::RectangleShape line;
    sf::RectangleShape bottomLine;
    sf::Font font;
    sf::Text text;
    TextEdit* verticeTextBox;
    TextEdit* aristaOrigenTextBox;
    TextEdit* aristaDestinoTextBox;
    TextEdit* pesoTextBox;
    sf::RectangleShape botonAgregarVertice;
    sf::RectangleShape botonEliminarVertice;
    sf::RectangleShape botonAgregarAristaDir;
    sf::RectangleShape botonAgregarAristaNoDir;
    sf::RectangleShape botonEliminarArista;
    sf::RectangleShape botonDijkstra;
    sf::RectangleShape botonFW;
    sf::RectangleShape botonDFS;
    sf::RectangleShape botonBFS;
    bool addVertice;
    string nombreVertice;
    Grafo* grafoPrincipal;

public:
    userInterface();

    void drawWindow();
    void drawGraph();
    void loop();
    void addVertCheckClick(float x, float y);
    void elimVerCheckClick(float x, float y);
    void addDirEdgeCheckClick(float x, float y);
    void elimEdgeCheckClick(float x, float y);
    void addNonDirEdgeCheckClick(float x, float y);
    void dfsCheckClick(float x, float y);
    void bfsCheckClick(float x, float y);
    void fwCheckClick(float x, float y);
    void dijkstraCheckClick(float x, float y);
};

#endif // USERINTERFACE_H
