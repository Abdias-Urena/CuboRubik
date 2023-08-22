#pragma once
#include "textArea.h"

textArea::textArea(sf::RenderWindow& window, sf::Font& font, unsigned int fontSize, sf::Color bgColor, sf::Color textColor)
    : isSelected(false)
{
    background.setSize(sf::Vector2f(120.f, 50.f));
    background.setFillColor(bgColor);
    background.setOutlineThickness(2.f);
    background.setOutlineColor(sf::Color::Black);

    text.setFont(font);
    text.setCharacterSize(fontSize);
    text.setFillColor(textColor);

    // Set initial position for the text area
    background.setPosition(50.f, 50.f);
    text.setPosition(background.getPosition() + sf::Vector2f(10.f, 10.f));
}

void textArea::handleEvent(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
        if (background.getGlobalBounds().contains(mousePos)) {
            isSelected = true;
        }
        else {
            isSelected = false;
        }
    }
    else if (event.type == sf::Event::TextEntered && isSelected) {
        if (event.text.unicode == '\b' && !text.getString().isEmpty()) {
            // Handle backspace
            std::string currentString = text.getString();
            currentString.pop_back();
            text.setString(currentString);
        }
        else if (event.text.unicode < 128) {
            // Handle regular text input
            text.setString(text.getString() + static_cast<char>(event.text.unicode));
        }
    }
}

void textArea::setPosition(float x, float y) {
    background.setPosition(x, y);
    text.setPosition(x + 10.f, y + 10.f); // Offset for text within the background
}

void textArea::update() {
    // Add any additional update logic here
}

void textArea::render(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(text);
}
