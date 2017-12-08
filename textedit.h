#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include "Graphics.hpp"
#include "System.hpp"

class TextEdit
{
    public:
        TextEdit(int x, int y, int width);
        ~TextEdit();
        std::string getText();
        void draw(sf::RenderWindow* window);
        void checkClick(float x, float y);
        void handleEvent(const sf::Event& event, sf::RenderWindow* window);
        void handleBackspace();
        void setText(const std::string& txt);

    private:
        sf::Font font;
        float width;
        bool highlighted;
        bool focused;
        sf::RectangleShape textBox;
        sf::Text text;

};

#endif // TEXTEDIT_H
