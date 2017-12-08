#include "userinterface.h"
#include <sstream>

userInterface::userInterface()
{    
    this->line.setSize(sf::Vector2f(600,10));
    this->line.rotate(90);
    this->line.setPosition(150, 0);
    this->line.setFillColor(sf::Color::Black);

    this->bottomLine.setSize(sf::Vector2f(800, 10));
    this->bottomLine.setPosition(sf::Vector2f(0, 500));
    this->bottomLine.setFillColor(sf::Color::Black);

    this->circle.setRadius(30);
    this->circle.setFillColor(sf::Color::White);
    this->circle.setOutlineColor(sf::Color::Black);
    this->circle.setOutlineThickness(5);

    this->font.loadFromFile("/home/pablo/Graficador/Anton.ttf");
    this->text.setFont(font);
    this->text.setCharacterSize(20);
    this->text.setColor(sf::Color::Black);

    this->verticeTextBox = new TextEdit(30, 50, 80);
    this->aristaOrigenTextBox = new TextEdit(30, 200, 80);
    this->aristaDestinoTextBox = new TextEdit(30, 265, 80);
    this->pesoTextBox = new TextEdit(30, 460, 80);

    this->botonAgregarAristaDir.setSize(sf::Vector2f(80,20));
    this->botonAgregarAristaNoDir.setSize(sf::Vector2f(80,20));
    this->botonAgregarVertice.setSize(sf::Vector2f(80,20));
    this->botonEliminarArista.setSize(sf::Vector2f(80,20));
    this->botonEliminarVertice.setSize(sf::Vector2f(80,20));
    this->botonDFS.setSize(sf::Vector2f(80,20));
    this->botonBFS.setSize(sf::Vector2f(80,20));
    this->botonDijkstra.setSize(sf::Vector2f(80,20));
    this->botonFW.setSize(sf::Vector2f(80,20));

    this->botonAgregarAristaDir.setFillColor(sf::Color::Transparent);
    this->botonAgregarAristaNoDir.setFillColor(sf::Color::Transparent);
    this->botonAgregarVertice.setFillColor(sf::Color::Transparent);
    this->botonEliminarArista.setFillColor(sf::Color::Transparent);
    this->botonEliminarVertice.setFillColor(sf::Color::Transparent);
    this->botonDFS.setFillColor(sf::Color::Transparent);
    this->botonDijkstra.setFillColor(sf::Color::Transparent);
    this->botonFW.setFillColor(sf::Color::Transparent);
    this->botonBFS.setFillColor(sf::Color::Transparent);

    this->botonAgregarAristaDir.setOutlineColor(sf::Color::Black);
    this->botonAgregarAristaNoDir.setOutlineColor(sf::Color::Black);
    this->botonAgregarVertice.setOutlineColor(sf::Color::Black);
    this->botonEliminarArista.setOutlineColor(sf::Color::Black);
    this->botonEliminarVertice.setOutlineColor(sf::Color::Black);
    this->botonDFS.setOutlineColor(sf::Color::Black);
    this->botonBFS.setOutlineColor(sf::Color::Black);
    this->botonDijkstra.setOutlineColor(sf::Color::Black);
    this->botonFW.setOutlineColor(sf::Color::Black);

    this->botonAgregarAristaDir.setOutlineThickness(3);
    this->botonAgregarAristaNoDir.setOutlineThickness(3);
    this->botonAgregarVertice.setOutlineThickness(3);
    this->botonEliminarArista.setOutlineThickness(3);
    this->botonEliminarVertice.setOutlineThickness(3);
    this->botonDFS.setOutlineThickness(3);
    this->botonDijkstra.setOutlineThickness(3);
    this->botonFW.setOutlineThickness(3);
    this->botonBFS.setOutlineThickness(3);

    this->botonAgregarAristaDir.setPosition(sf::Vector2f(30, 310));
    this->botonAgregarAristaNoDir.setPosition(sf::Vector2f(30, 350));
    this->botonAgregarVertice.setPosition(sf::Vector2f(30, 90));
    this->botonEliminarArista.setPosition(sf::Vector2f(30, 390));
    this->botonEliminarVertice.setPosition(sf::Vector2f(30, 130));
    this->botonDFS.setPosition(sf::Vector2f(200, 520));
    this->botonBFS.setPosition(sf::Vector2f(300, 520));
    this->botonFW.setPosition(sf::Vector2f(400, 520));
    this->botonDijkstra.setPosition(sf::Vector2f(500, 520));

    grafoPrincipal = new Grafo();

    this->window.create(sf::VideoMode(800,600), "Graficador", sf::Style::Default);
}

void userInterface::drawWindow()
{
    this->window.clear(sf::Color::Cyan);

    this->window.draw(line);
    this->window.draw(bottomLine);

    this->text.setCharacterSize(20);

    this->text.setString("Vertice");
    this->text.setPosition(sf::Vector2f(40, 20));
    this->window.draw(text);

    this->text.setString("Origen");
    this->text.setPosition(sf::Vector2f(40, 170));
    this->window.draw(text);

    this->text.setString("Destino");
    this->text.setPosition(sf::Vector2f(35, 235));
    this->window.draw(text);

    this->text.setString("Peso");
    this->text.setPosition(sf::Vector2f(45, 430));
    this->window.draw(text);

    this->text.setCharacterSize(15);

    this->text.setString("Add");
    this->text.setPosition(sf::Vector2f(55, 90));
    this->window.draw(text);

    this->text.setString("Elim");
    this->text.setPosition(sf::Vector2f(55, 130));
    this->window.draw(text);
    this->text.setPosition(sf::Vector2f(55, 390));
    this->window.draw(text);

    this->text.setString("Dir");
    this->text.setPosition(sf::Vector2f(55, 310));
    this->window.draw(text);

    this->text.setString("Non-Dir");
    this->text.setPosition(sf::Vector2f(45, 350));
    this->window.draw(text);

    this->text.setString("DFS");
    this->text.setPosition(sf::Vector2f(230, 520));
    this->window.draw(text);

    this->text.setString("BFS");
    this->text.setPosition(sf::Vector2f(325, 520));
    this->window.draw(text);

    this->text.setString("FW");
    this->text.setPosition(sf::Vector2f(430, 520));
    this->window.draw(text);

    this->text.setString("Dijsktra");
    this->text.setPosition(sf::Vector2f(515, 520));
    this->window.draw(text);
}

void userInterface::drawGraph()
{
    for(int i = 0; i < grafoPrincipal->getNumVertices(); i++)
    {
        Vertice* tmp = grafoPrincipal->obtenerVerticePos(i);
        this->circle.setPosition(tmp->getPosX(), tmp->getPosY());
        this->window.draw(circle);
        this->text.setString(tmp->nombre);
        this->text.setPosition(tmp->getPosX()+25, tmp->getPosY()+20);
        this->text.setCharacterSize(24);
        window.draw(text);
    }

    for(int i = 0; i < grafoPrincipal->getNumVertices(); i++)
    {
        Vertice* tmp = grafoPrincipal->obtenerVerticePos(i);
        for(int i = 0; i < tmp->listaAristas->getCantElementos(); i++)
        {
            Arista* temp = tmp->listaAristas->obtenerAristaPos(i);
            sf::LineShape aristaLine(sf::Vector2f(tmp->getPosX()+30,tmp->getPosY()+30), sf::Vector2f(grafoPrincipal->obtenerVertice(temp->destino->nombre)->getPosX()+30,grafoPrincipal->obtenerVertice(temp->destino->nombre)->getPosY()+30));
            window.draw(aristaLine);
            cout << tmp->nombre << " to " << temp->destino->nombre << endl;
        }
    }
}

void userInterface::addVertCheckClick(float x, float y)
{
    botonAgregarVertice.setOutlineColor(sf::Color::Black);
    sf::FloatRect rect(botonAgregarVertice.getGlobalBounds());
    if(rect.contains(x, y))
    {
        nombreVertice = verticeTextBox->getText();
        botonAgregarVertice.setOutlineColor(sf::Color(0, 130, 19));
        addVertice = true;
    }
}

void userInterface::elimVerCheckClick(float x, float y)
{
    botonEliminarVertice.setOutlineColor(sf::Color::Black);
    sf::FloatRect rect(botonEliminarVertice.getGlobalBounds());
    if(rect.contains(x, y))
    {
        this->nombreVertice = this->verticeTextBox->getText();
        this->grafoPrincipal->eliminarVertice(nombreVertice);
        for(int i = 0; i < grafoPrincipal->getNumVertices(); i++)
        {
            Vertice* tmp = grafoPrincipal->obtenerVerticePos(i);
            if(tmp->obtenerArista(nombreVertice) != nullptr)
                tmp->eliminarArista(nombreVertice);
        }
    }
}

void userInterface::addDirEdgeCheckClick(float x, float y)
{
    stringstream g(pesoTextBox->getText());
    int w = 0;
    g >> w;
    sf::FloatRect rect(botonAgregarAristaDir.getGlobalBounds());
    if(rect.contains(x, y))
    {
        this->grafoPrincipal->obtenerVertice(this->aristaOrigenTextBox->getText())->agregarArista(this->aristaDestinoTextBox->getText(), w);
    }
}

void userInterface::addNonDirEdgeCheckClick(float x, float y)
{
    stringstream g(pesoTextBox->getText());
    int w = 0;
    g >> w;
    string nombreDestino = this->aristaDestinoTextBox->getText();
    string nombreOrigen = this->aristaOrigenTextBox->getText();
    sf::FloatRect rect(botonAgregarAristaNoDir.getGlobalBounds());
    if(rect.contains(x, y))
    {
        this->grafoPrincipal->obtenerVertice(nombreOrigen)->agregarArista(nombreDestino, w);
        this->grafoPrincipal->obtenerVertice(nombreDestino)->agregarArista(nombreOrigen, w);
    }
}

void userInterface::elimEdgeCheckClick(float x, float y)
{
    sf::FloatRect rect(botonEliminarArista.getGlobalBounds());
    if(rect.contains(x, y))
    {
        this->grafoPrincipal->obtenerVertice(this->aristaOrigenTextBox->getText())->eliminarArista(this->aristaDestinoTextBox->getText());
    }
}

void userInterface::dfsCheckClick(float x, float y)
{
    botonDFS.setOutlineColor(sf::Color::Black);
    sf::FloatRect rect(botonDFS.getGlobalBounds());
    if(rect.contains(x, y))
    {
        string name = verticeTextBox->getText();
        grafoPrincipal->BFS(name);

        int num = grafoPrincipal->bfsLevels;
        int nom = grafoPrincipal->getNumVertices();
        for(int q = 0; q < num; q++)
        {
            cout << "Nivel " << q << endl;
            for(int w = 0; w < nom; w++)
            {
                if(grafoPrincipal->pairsBFS[w].level == q)
                {
                    cout << grafoPrincipal->pairsBFS[w].nombre << endl;
                }
            }
        }
    }
}

void userInterface::bfsCheckClick(float x, float y)
{
    botonBFS.setOutlineColor(sf::Color::Black);
    sf::FloatRect rect(botonBFS.getGlobalBounds());
    if(rect.contains(x, y))
    {

    }
}

void userInterface::loop()
{
    while(this->window.isOpen())
    {
        this->drawWindow();
        this->drawGraph();
        this->verticeTextBox->draw(&(this->window));
        this->aristaDestinoTextBox->draw(&(this->window));
        this->aristaOrigenTextBox->draw(&(this->window));
        this->pesoTextBox->draw(&(this->window));
        this->window.draw(botonAgregarAristaDir);
        this->window.draw(botonAgregarAristaNoDir);
        this->window.draw(botonAgregarVertice);
        this->window.draw(botonEliminarVertice);
        this->window.draw(botonEliminarArista);
        this->window.draw(botonDFS);
        this->window.draw(botonDijkstra);
        this->window.draw(botonFW);
        this->window.draw(botonBFS);

        sf::Event event;

        while(this->window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                this->window.close();
            }
            else if(event.type == sf::Event::MouseButtonPressed)
            {
                if(!addVertice)
                {
                    this->verticeTextBox->checkClick(event.mouseButton.x, event.mouseButton.y);
                    this->aristaDestinoTextBox->checkClick(event.mouseButton.x, event.mouseButton.y);
                    this->aristaOrigenTextBox->checkClick(event.mouseButton.x, event.mouseButton.y);
                    this->pesoTextBox->checkClick(event.mouseButton.x, event.mouseButton.y);
                    this->addVertCheckClick(event.mouseButton.x, event.mouseButton.y);
                    this->elimVerCheckClick(event.mouseButton.x, event.mouseButton.y);
                    this->addDirEdgeCheckClick(event.mouseButton.x, event.mouseButton.y);
                    this->addNonDirEdgeCheckClick(event.mouseButton.x, event.mouseButton.y);
                    this->elimEdgeCheckClick(event.mouseButton.x, event.mouseButton.y);
                    this->dfsCheckClick(event.mouseButton.x, event.mouseButton.y);
                    this->bfsCheckClick(event.mouseButton.x, event.mouseButton.y);
                }

                else
                {
                    if(event.mouseButton.x > 190)
                    {
                        if(grafoPrincipal->agregarVertice(nombreVertice) != nullptr)
                        {
                            grafoPrincipal->obtenerVertice(nombreVertice)->setPos(event.mouseButton.x-30, event.mouseButton.y-30);
                        }
                        addVertice = false;
                    }
                }
            }
            else
            {
                verticeTextBox->handleEvent(event, &window);
                aristaDestinoTextBox->handleEvent(event, &window);
                aristaOrigenTextBox->handleEvent(event, &window);
                pesoTextBox->handleEvent(event, &window);
            }
        }
        window.display();
    }
}
