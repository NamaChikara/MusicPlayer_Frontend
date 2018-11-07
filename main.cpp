#include <iostream>
#include <string>
#include "ArtistTree.h"
#include "AlbumList.h"
#include "MusicData.h"
#include <SFML/Graphics.hpp>
#include "GraphicsHelper.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

	// Load font file for sf::Text objects
	std::string font_file = "SourceSansPro.otf";	// font for Text Objects
	sf::Font font;

	if (!font.loadFromFile(font_file))
	{
		std::cerr << "Could not load " << font_file << " font file." << std::endl;
	}

	// create text object for displaying user input
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::Red);
	std::string artist_str;

	// create rectangle object for determining when to display user input
	sf::RectangleShape artist_rect(sf::Vector2f(200, 50));
	sf::RectangleShape input_rect(sf::Vector2f(50, 50));
	sf::Vector2f offset = findPosition({ artist_rect });
	input_rect.setPosition(offset);
	input_rect.setFillColor(sf::Color::Blue);
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
					&& sf::Mouse::getPosition(window).x >= input_rect.getPosition().x
					&& sf::Mouse::getPosition(window).x <= input_rect.getPosition().x + input_rect.getSize().x)
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
						artist_str += static_cast<char>(event.text.unicode);
						text.setString(artist_str);
					}
				}
			}
		}

		window.clear();

		window.draw(artist_rect);
		window.draw(input_rect);
		window.draw(text);

		window.display();
	}

	return 0;
}