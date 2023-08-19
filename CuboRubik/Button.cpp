#include "Button.h"

Button::Button() {
	this->state = 0;
	this->texture = new sf::Texture();
}

void Button::drawMe(sf::RenderWindow& window) {
	window.draw(shape);
	window.draw(text);
}

void Button::setShapePosition(float x, float y) {
	sf::Vector2f position(x, y);
	this->shape.setPosition(position);
}

void Button::setShapeSize(float width, float heigth) {
	sf::Vector2f size(width, heigth);
	this->shape.setSize(size);
}

sf::Vector2f Button::getSize() const {
	return shape.getSize();
}

void Button::setColorShape(sf::Color color) {
	this->shape.setFillColor(color);
}

string Button::getText() {
	return this->text.getString();
}

void Button::setText(string text) {
	this->text.setString(text);
}

void Button::setTextPosition(float x, float y) {
	const float textPositionX = x + (this->shape.getGlobalBounds().width / 2.f) -
		this->text.getGlobalBounds().width / 2.f;
	const float textPositionY = y + (this->shape.getGlobalBounds().height / 2.f) -
		this->text.getGlobalBounds().height / 2.f;
	this->text.setPosition(textPositionX, textPositionY);
}

void Button::addLetterSize(int size) {
	this->text.setCharacterSize(size);
}

void Button::addFontText(sf::Font& font) {
	this->text.setFont(font);
}

bool Button::isChangeTexture(string nameTexture) {
	if (texture->loadFromFile(nameTexture)) {
		this->shape.setTexture(texture);
		return true;
	}
	return false;
}

int Button::getState() {
	return this->state;
}

void Button::setState(int state) {
	this->state = state;
}

bool Button::isPressed(sf::Vector2f vec, int state) {
	if (this->state == 0 && this->shape.getGlobalBounds().contains(vec)) {
		cout << this->shape.getGlobalBounds().contains(vec);
		setState(state);
		return true;
	}
	return false;
}