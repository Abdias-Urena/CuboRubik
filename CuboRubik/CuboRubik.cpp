#include <iostream>
#include "Button.h"
#include "textArea.h"

using namespace std;

int main()
{
	sf::RenderWindow win1;
	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 653,
		(sf::VideoMode::getDesktopMode().height / 2) - 364);

	//WINDOW-1
	win1.create(sf::VideoMode(1300, 700), "Play", sf::Style::Titlebar | sf::Style::Close);
	win1.setPosition(centerWindow);


	Button buttonPlay;
	buttonPlay.setShapePosition(559, 320);
	buttonPlay.setShapeSize(150, 100);
	if (!buttonPlay.isChangeTexture("Buttons/play.png"))
		cout << "THIS FILE CANNOT OPEN";
	buttonPlay.setColorShape(sf::Color::White);

	Button buttonPlay2;
	buttonPlay2.setShapePosition(200, 200);
	buttonPlay2.setShapeSize(120, 80);
	if (!buttonPlay2.isChangeTexture("Buttons/play.png"))
		cout << "THIS FILE CANNOT OPEN";
	buttonPlay2.setColorShape(sf::Color::White);

	sf::Font font;
	if (!font.loadFromFile("font/arial.ttf")) {
		cout << "Font file cannot be loaded." << endl;
		return EXIT_FAILURE;
	}

	textArea text1(win1, font, 20, sf::Color::White, sf::Color::Black);
	text1.setPosition(100, 100);

	textArea text2(win1, font, 20, sf::Color::White, sf::Color::Black);
	text1.setPosition(400, 400);


	while (win1.isOpen())
	{
		sf::Event e;
		while (win1.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				win1.close();
			text1.handleEvent(e);
			text2.handleEvent(e);
		}
		win1.clear();
		buttonPlay.drawMe(win1);
		buttonPlay2.drawMe(win1);
		text1.render(win1);
		text2.render(win1);
		win1.display();
	}
	return EXIT_SUCCESS;
}
