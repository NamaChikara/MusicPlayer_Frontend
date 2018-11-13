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
	// create example MusicData structure
	MusicData mymusic1;
	mymusic1.add_artist("Duran Jones");
	mymusic1.add_album("Duran Jones", 2018, "Duran Jones and the Indications");
	mymusic1.add_artist("DjM Trio");
	mymusic1.add_album("DjM Trio", 2018, "Cave Art Pt. 2");
	mymusic1.add_album("DjM Trio", 2014, "Cave Art");
	mymusic1.add_album("DjM Trio", 2010, "The Intrigue");

	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

	// Load font file for sf::Text objects
	std::string font_file = "SourceSansPro.otf";	// font for Text Objects
	sf::Font font;
	if (!font.loadFromFile(font_file))
	{
		std::cerr << "Could not load " << font_file << " font file." << std::endl;
	}

	DisplayTable mytable{ font_file };
	InputBar myinput{ font_file, mytable  };

	std::vector<std::string> titles = { "Wish You Were Here",
		"Dark Side Of The Moon", "Animals", "The Wall" };
	mytable.update(titles);

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
				if (event.key.code == sf::Mouse::Left)
				{
					myinput.clicked(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
				}
				else if (event.key.code == sf::Mouse::Right)
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