#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class textArea {
public:
    textArea(sf::RenderWindow& window, sf::Font& font, unsigned int fontSize, sf::Color bgColor, sf::Color textColor);

    void handleEvent(sf::Event event);
    void update();
    void render(sf::RenderWindow& window);
    void setPosition(float x, float y);

private:
    sf::RectangleShape background;
    sf::Text text;
    bool isSelected;
};

