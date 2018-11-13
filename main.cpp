#include <iostream>
#include <string>
#include "ArtistTree.h"
#include "AlbumList.h"
#include "MusicData.h"
#include <SFML/Graphics.hpp>
#include "GraphicsHelper.h"
#include "InputBar.h"
#include "DisplayTable.h"

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
	// load DisplayTable then use it to initialize InputBar
	DisplayTable mytable{ font_file };
	InputBar myinput{ font_file, mytable  };

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
			// pass click location to InputBar to take action
				if (event.key.code == sf::Mouse::Left)
				// left click means information might have been entered
				{
					myinput.clicked(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
				}
				else if (event.key.code == sf::Mouse::Right)
				// right click means input field might have been cleared
				{
					myinput.cleared(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
				}
				break;
			case sf::Event::TextEntered:
				// handle ASCII characters only
				if (event.text.unicode < 128)
				{
					myinput.input(static_cast<char>(event.text.unicode));
				}
				break;
			}
		}

		window.clear();

		myinput.draw(window);

		window.display();
	}
	return 0;
}