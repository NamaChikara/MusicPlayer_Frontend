#include <iostream>
#include <string>
#include "ArtistTree.h"
#include "AlbumList.h"
#include "MusicData.h"
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	// Load font file for sf::Text objects
	std::string font_file = "SourceSansPro.otf";	// font for Text Objects
	sf::Font font;

	if (!font.loadFromFile(font_file))
	{
		std::cerr << "Could not load " << font_file << " font file." << std::endl;
		std::cin.get();
		std::cin.get();
	}

	// create text object for displaying user input
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::Red);
	std::string str;
	text.setString("ABC");

	// create rectangle object for determining when to display user input
	sf::RectangleShape rect(sf::Vector2f(100, 100));
	bool isSelected = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
				if (event.key.code == sf::Mouse::Left
					&& sf::Mouse::getPosition(window).x >= rect.getPosition().x
					&& sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x)
				{
					isSelected = !isSelected;
				}
				break;
			case sf::Event::TextEntered:
				if (isSelected)
				{
					// handle ASCII characters only
					if (event.text.unicode < 128)
					{
						str += static_cast<char>(event.text.unicode);
						text.setString(str);
					}
				}
			}
		}

		window.clear();

		window.draw(rect);
		window.draw(text);

		window.display();
	}

	return 0;
}