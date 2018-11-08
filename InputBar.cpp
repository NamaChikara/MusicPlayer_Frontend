#include "InputBar.h"

InputBar::InputBar(std::string font_file, MusicData mm)
	: mymusic{ mm }, artist_ent {false}, album_ent{ false }, year_ent{ false }
{
	font.loadFromFile(font_file);

	place_rects();
	setup_texts();
	text_locations();
}

void InputBar::draw(sf::RenderTarget& target, sf::RenderStates) const
{
	target.draw(artist_rect);
	target.draw(album_rect);
	target.draw(year_rect);
	target.draw(set_rect);
	target.draw(get_rect);

	target.draw(artist_text);
	target.draw(album_text);
	target.draw(year_text);
	target.draw(set_text);
	target.draw(get_text);
}

void InputBar::place_rects()
{
	artist_rect.setSize(sf::Vector2f{ 200,rect_height });
	artist_rect.setFillColor(sf::Color::Blue);

	album_rect.setSize(sf::Vector2f{ 200,rect_height });
	album_rect.setPosition(topRight(artist_rect));
	album_rect.setFillColor(sf::Color::Red);

	year_rect.setSize(sf::Vector2f{ 100,rect_height });
	year_rect.setPosition(topRight(album_rect));
	year_rect.setFillColor(sf::Color::Blue);

	set_rect.setSize(sf::Vector2f{ 50,rect_height });
	set_rect.setPosition(topRight(year_rect));
	set_rect.setFillColor(sf::Color::Red);

	get_rect.setSize(sf::Vector2f{ 50,rect_height });
	get_rect.setPosition(topRight(set_rect));
	get_rect.setFillColor(sf::Color::Blue);
}

void InputBar::setup_texts()
{
	artist_text.setFont(font);
	artist_text.setCharacterSize(charsize);
	artist_text.setString(artist_init);
	artist_text.setFillColor(sf::Color(255, 255, 255));

	album_text.setFont(font);
	album_text.setString(album_init);
	album_text.setCharacterSize(charsize);
	artist_text.setFillColor(sf::Color(255, 255, 255));

	year_text.setFont(font);
	year_text.setString(year_init);
	year_text.setCharacterSize(charsize);
	artist_text.setFillColor(sf::Color(255, 255, 255));

	set_text.setFont(font);
	set_text.setString(set_init);
	set_text.setCharacterSize(charsize);
	artist_text.setFillColor(sf::Color(255, 255, 255));

	get_text.setFont(font);
	get_text.setString(get_init);
	get_text.setCharacterSize(charsize);
	artist_text.setFillColor(sf::Color(255, 255, 255));
}

void InputBar::text_locations()
{
	float voffset = (rect_height - (float)charsize) / 2;
	artist_text.setPosition(artist_rect.getPosition() + sf::Vector2f(hoffset, voffset));
	album_text.setPosition(album_rect.getPosition() + sf::Vector2f(hoffset, voffset));
	year_text.setPosition(year_rect.getPosition() + sf::Vector2f(hoffset, voffset));
	set_text.setPosition(set_rect.getPosition() + sf::Vector2f(hoffset, voffset));
	get_text.setPosition(get_rect.getPosition() + sf::Vector2f(hoffset, voffset));
}

sf::Vector2f InputBar::bottom_left()
{
	return botLeft(&artist_rect);
}

void InputBar::clicked(sf::Vector2f click)
{
	// if click is not on any rect, set all to false
	artist_ent = clickRect(artist_rect, click);
	album_ent = clickRect(album_rect, click);
	year_ent = clickRect(year_rect, click);
	
	// if click is on set_rect, pass strings to MusicData
	if (clickRect(set_rect, click))
	{
		process_set();
	}

	// if click is on get_rect, print MusicData
	if (clickRect(get_rect, click))
	{
		process_get();
	}
}

void InputBar::cleared(sf::Vector2f click)
{
	// if the click is on a rect, clear the appropriate text object
	if (clickRect(artist_rect, click))
	{
		artist_text.setString("");
	}
	else if (clickRect(album_rect, click))
	{
		album_text.setString("");
	}
	else if (clickRect(year_rect, click))
	{
		year_text.setString("");
	}
}

void InputBar::input(char c)
{
	// check if the backspace key was pressed
	if (c == '\b')
	{
		// determine which field is active
		if (artist_ent)
		{
			std::string str = artist_text.getString();
			// make sure string is nonempty before attempting to delete
			if (str.size() != 0)
			{
				str.erase(str.size() - 1, 1);
				artist_text.setString(str);
			}
		}
		else if (album_ent)
		{
			std::string str = album_text.getString();
			if (str.size() != 0)
			{
				str.erase(str.size() - 1, 1);
				album_text.setString(str);
			}
		}
		else if (year_ent)
		{
			std::string str = year_text.getString();
			if (str.size() != 0)
			{
				str.erase(str.size() - 1, 1);
				year_text.setString(str);
			}
		}
	}
	else
	{
		// add character to the active field
		if (artist_ent)
		{
			artist_text.setString(artist_text.getString() + c);
		}
		else if (album_ent)
		{
			album_text.setString(album_text.getString() + c);
		}
		else if (year_ent)
		{
			// make sure input is a digit and year length is valid
			if (isdigit(c) && year_text.getString().getSize() < 4)
			{
				year_text.setString(year_text.getString() + c);
			}
		}
	}
}

void InputBar::process_set()
{
	// if no album text entered, assume we are adding an artist
	if (album_text.getString() == "")
	{
		// make sure artist field is nonempty before adding
		if (artist_text.getString() != "")
		{
			mymusic.add_artist(artist_text.getString());
		}
	}
	else
	{
		// artist field must be nonempty to add an album
		if (artist_text.getString() != "")
		{
			int year = 0; // default year value
			// update year value if year_text is nonempty
			if (year_text.getString().getSize() > 0)
			{
				std::string year_str = year_text.getString();
				// stoi takes a string of digits as input and returns an it
				year = std::stoi(year_str);
			}
			mymusic.add_album(artist_text.getString(),
				year, album_text.getString());
		}
	}
}

void InputBar::process_get()
{
	std::string artist = artist_text.getString();
	// if artist is nonempty, print their albums if they exist
	if (artist != "")
	{
		mymusic.print_albums(artist);
	}
	// otherwise, print a list of stored artists
	else
	{
		mymusic.print_artists();
	}
}