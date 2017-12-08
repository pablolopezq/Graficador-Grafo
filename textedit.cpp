#include "textedit.h"

TextEdit::TextEdit(int x, int y, int width) : width(width), focused(false)
{
    textBox = sf::RectangleShape(sf::Vector2f(width, 25));
    textBox.setPosition(sf::Vector2f(x, y));
    font = sf::Font();
    font.loadFromFile("/home/pablo/Graficador/Anton.ttf");
    text = sf::Text("",font,16);
    text.setPosition(sf::Vector2f(x+5, y+4));
    text.setColor(sf::Color::Black);
    textBox.setOutlineColor(sf::Color::Black);
    textBox.setOutlineThickness(3);
}

TextEdit::~TextEdit()
{

}

void TextEdit::draw(sf::RenderWindow* window)
{
    window->draw(textBox);
    window->draw(text);
}

void TextEdit::checkClick(float x, float y)
{
    focused = false;
    textBox.setOutlineColor(sf::Color::Black);
    sf::FloatRect rect(textBox.getGlobalBounds());
    if(rect.contains(x, y))
    {
        textBox.setOutlineColor(sf::Color(0, 130, 19));
        focused = true;
    }
}

void TextEdit::handleBackspace()
{
    if(!text.getString().isEmpty())
    {
        std::string str = text.getString().toAnsiString();
        str = str.substr(0, str.size() - 1);
        text.setString(sf::String(str));
    }
}

std::string TextEdit::getText()
{
    return text.getString().toAnsiString();
}

void TextEdit::handleEvent(const sf::Event& event, sf::RenderWindow* window)
{
    if(focused)
        if(event.type == sf::Event::TextEntered)
            if(event.text.unicode > 0x1f && event.text.unicode != 0x7f) // not a control character?
                text.setString(text.getString() + sf::String(event.text.unicode));

    if(event.type == sf::Event::MouseButtonPressed)
        checkClick(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);

    if(focused)
        if(event.type == sf::Event::KeyPressed)
            if(event.key.code == sf::Keyboard::BackSpace)
                handleBackspace();
}

void TextEdit::setText(const std::string& txt)
{
    text.setString(txt);
}
