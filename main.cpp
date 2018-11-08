#include <iostream>
#include <string>
#include "ArtistTree.h"
#include "AlbumList.h"
#include "MusicData.h"
#include <SFML/Graphics.hpp>
#include "GraphicsHelper.h"

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

	// create text object for displaying user input
	sf::Text input_text;
	input_text.setFont(font);
	input_text.setCharacterSize(30);
	input_text.setFillColor(sf::Color::Red);
	std::string artist_str;

	// create a place to display user input
	sf::RectangleShape artist_rect(sf::Vector2f(200, 50));
	// create a button to toggle whether or not input is accepted
	sf::RectangleShape input_rect(sf::Vector2f(50, 50));
	input_rect.setPosition(topRight(artist_rect));
	input_rect.setFillColor(sf::Color::Blue);
	// create a button to pass the input to the MusicData class
	sf::RectangleShape enter_rect(sf::Vector2f(50, 50));
	offset = findPosition(topRight(input_rect));
	enter_rect.setPosition(offset);
	enter_rect.setFillColor(sf::Color::Red);

	// create a place to display album names
	sf::RectangleShape album_display(sf::Vector2f(300, 50));
	album_display.setPosition(sf::Vector2f(0, 50));
	album_display.setFillColor(sf::Color::White);
	sf::Text album_output;
	album_output.setFont(font);
	album_output.setCharacterSize(30);
	album_output.setFillColor(sf::Color::Black);
	album_output.setPosition(sf::Vector2f(0, 50));
	std::string album_str;

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

	return 0;
}