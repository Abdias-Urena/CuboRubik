#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Button {
private:
	sf::RectangleShape shape;
	sf::Text text;
	sf::Texture* texture;
	int state;

public:
	Button();

	//Methods Shape
	void setShapePosition(float, float);
	void setShapeSize(float, float);
	void setColorShape(sf::Color);
	bool isChangeTexture(string);
	sf::Vector2f getSize()const;

	//Methods State
	int getState();
	void setState(int);

	//Methods Text
	string getText();
	void setText(string);
	void setTextPosition(float, float);
	void addLetterSize(int);
	void addFontText(sf::Font&);
	void addFillColorText(sf::Color);

	//Generals Methods
	void drawMe(sf::RenderWindow&);
	bool isPressed(sf::Vector2f, int);

};