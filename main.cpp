#include <iostream>
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
#include "grafo.h"
#include "vertice.h"
#include "arista.h"
#include "listavertices.h"
#include "listaaristas.h"
#include "userinterface.h"
#include "lineshape.h"

using namespace std;
/*
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Graficador", sf::Style::Default);
    window.clear(sf::Color::White);

    sf::CircleShape circle(30);
    TextEdit* originTextBox = new TextEdit(25,50,80);
    sf::RectangleShape line(sf::Vector2f(600,10));
    sf::LineShape testLine(sf::Vector2f(10,0), sf::Vector2f(500,500));
    circle.setFillColor(sf::Color(0,130,19));
    circle.setOutlineColor(sf::Color::Black);
    circle.setOutlineThickness(5);
    line.setFillColor(sf::Color::Black);
    line.rotate(90);
    line.setPosition(150, 0);

    while(window.isOpen())
    {
        window.draw(line);
        window.draw(testLine);
        originTextBox->draw(&window);
        //originTextBox = new TextEdit(25, 100, 80);
        //originTextBox->draw(&window);
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if(event.type == sf::Event::MouseButtonPressed)
            {
                originTextBox->checkClick(event.mouseButton.x, event.mouseButton.y);
                cout << "Vertice agregado" << endl;
                //circle.setPosition(event.mouseButton.x - 30, event.mouseButton.y - 30);
                //window.draw(circle);
            }
            else{
                originTextBox->handleEvent(event, &window);
            }
        }
        window.display();
    }
    return 0;
}
*/
/*
int main()
{
    Grafo* grafoPrincipal = new Grafo();
    grafoPrincipal->agregarVertice("A");
    grafoPrincipal->agregarVertice("B");
    grafoPrincipal->agregarVertice("C");
    grafoPrincipal->obtenerVertice("A")->agregarArista("B", 2);
    if(grafoPrincipal->obtenerVertice("A")->eliminarArista("B")->destino->nombre == "B")
        cout << "yay" << endl;
    else
        cout << "boo" << endl;
    return 0;
}
*/

int main()
{
    userInterface* interface = new userInterface();
    //interface->drawWindow();
    interface->loop();
    return 0;
}

