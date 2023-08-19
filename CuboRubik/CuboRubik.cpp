#include <iostream>
#include "Button.h"

using namespace std;

int main()
{
	sf::RenderWindow win1;
	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 653,
		(sf::VideoMode::getDesktopMode().height / 2) - 364);

	//WINDOW-1
	win1.create(sf::VideoMode(1300, 700), "Play", sf::Style::Titlebar | sf::Style::Close);
	win1.setPosition(centerWindow);

	sf::RenderWindow win2;
	win2.create(sf::VideoMode(1300, 700), "Second Win", sf::Style::Titlebar | sf::Style::Close);
	win2.setPosition(centerWindow);

	Button buttonPlay;
	buttonPlay.setShapePosition(559, 320);
	buttonPlay.setShapeSize(150, 100);
	if (!buttonPlay.isChangeTexture("Buttons/play.png"))
		cout << "THIS FILE CANNOT OPEN";
	buttonPlay.setColorShape(sf::Color::White);

	while (win1.isOpen())
	{
		sf::Event e;
		while (win1.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				win1.close();
			if (e.type == sf::Event::MouseButtonPressed && buttonPlay.isPressed(sf::Vector2f::Vector2(sf::Mouse::getPosition(win1).x,
				sf::Mouse::getPosition(win1).y), 0)) {
				win1.~RenderWindow();
				win2.clear();
				win2.display();
			}
		}
		sf::Event e1;
		while (win2.pollEvent(e))
		{
			if (e1.type == sf::Event::Closed)
			{
				win2.close();
			}
		}
		win1.clear();
		win1.~RenderWindow();
		buttonPlay.drawMe(win1);
		win1.display();
	}
	return EXIT_SUCCESS;
}
