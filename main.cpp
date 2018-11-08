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

	InputBar myinput{ font_file };
	DisplayTable mytable{ font_file };
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
			}
		}

		window.clear();

		//myinput.draw(window);
		mytable.draw(window);

		window.display();
	}
/*
	bool inputOn = true;	// text gets entered at the start
	bool displayAlbums = false;	// no albums to display yet

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
					// check if either button was clicked on; update boolean values accordingly
					if (clickRect(input_rect, sf::Mouse::getPosition(window)))
					{
						inputOn = !inputOn;
					}
					else if (clickRect(enter_rect, sf::Mouse::getPosition(window)))
					{
						displayAlbums = !displayAlbums;
						if (displayAlbums)
						{
							album_str = "House";
							inputOn = false;
						}
						else
						{
							album_str = "";
							inputOn = true;
						}
						album_output.setString(album_str);
					}
				}
				break;
			case sf::Event::TextEntered:
				if (inputOn)
				{
					// handle ASCII characters only
					if (event.text.unicode < 128)
					{
						artist_str += static_cast<char>(event.text.unicode);
						input_text.setString(artist_str);
					}
				}
			}
		}

		window.clear();

		window.draw(album_display);
		window.draw(artist_rect);
		window.draw(input_rect);
		window.draw(enter_rect);
		window.draw(input_text);
		window.draw(album_output);

		window.display();
	}
	*/
	return 0;
}