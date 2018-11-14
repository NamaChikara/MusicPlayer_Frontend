#include "InputBar.h"

InputBar::InputBar(std::string font_file, DisplayTable tt, MusicData mm)
	: mytable{ tt }, mymusic {mm}, artist_ent{ false }, album_ent{ false }, year_ent{ false }
{
	font.loadFromFile(font_file);

	place_rects();
	setup_texts();
	text_locations();
	mytable.set_displace(bottom_left());
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

	mytable.draw(target);
}

void InputBar::place_rects()
{
	artist_rect.setSize(sf::Vector2f{ artist_size,rect_height });
	artist_rect.setFillColor(sf::Color::Blue);
	artist_rect.setOutlineThickness(-2);
	artist_rect.setOutlineColor(sf::Color());

	album_rect.setSize(sf::Vector2f{ album_size,rect_height });
	album_rect.setPosition(topRight(artist_rect));
	album_rect.setFillColor(sf::Color::Red);
	album_rect.setOutlineThickness(-2);
	album_rect.setOutlineColor(sf::Color());

	year_rect.setSize(sf::Vector2f{ year_size,rect_height });
	year_rect.setPosition(topRight(album_rect));
	year_rect.setFillColor(sf::Color::Blue);
	year_rect.setOutlineThickness(-2);
	year_rect.setOutlineColor(sf::Color());

	set_rect.setSize(sf::Vector2f{ set_size,rect_height });
	set_rect.setPosition(topRight(year_rect));
	set_rect.setFillColor(sf::Color::Red);
	set_rect.setOutlineThickness(-2);
	set_rect.setOutlineColor(sf::Color());

	get_rect.setSize(sf::Vector2f{ get_size,rect_height });
	get_rect.setPosition(topRight(set_rect));
	get_rect.setFillColor(sf::Color::Blue);
	get_rect.setOutlineThickness(-2);
	get_rect.setOutlineColor(sf::Color());
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
	// center the set and get texts within their RectangleShapes
	float set_hoffset = (set_rect.getSize().x - set_text.getGlobalBounds().width) / 2;
	set_text.setPosition(set_rect.getPosition() + sf::Vector2f(set_hoffset, voffset));
	float get_hoffset = (get_rect.getSize().x - get_text.getGlobalBounds().width) / 2;
	get_text.setPosition(get_rect.getPosition() + sf::Vector2f(get_hoffset, voffset));
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
	// if the click is on a rect, clear the appropriate text object and focus input
	if (clickRect(artist_rect, click))
	{
		artist_text.setString("");
		artist_ent = true;
	}
	else if (clickRect(album_rect, click))
	{
		album_text.setString("");
		album_ent = true;
	}
	else if (clickRect(year_rect, click))
	{
		year_text.setString("");
		year_ent = true;
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
	// if tab was pressed, move between input fields
	else if (c == '\t')
	{
		if (artist_ent)
		{
			artist_ent = false;
			album_ent = true;
		}
		else if (album_ent)
		{
			album_ent = false;
			year_ent = true;
		}
		else if (year_ent)
		{
			year_ent = false;
			artist_ent = true;
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
		std::vector<std::string> ss = mymusic.get_album_strings(artist);
		// add message concerning the state of the albums 
		if (ss.size() == 0)
		{
			std::string none = "There are no albums by " + artist + " currently stored.";
			ss.push_back(none);
		}
		else
		{
			std::string some = "Albums by " + artist + ":";
			ss.insert(ss.begin(), some);
		}
		mytable.update(ss);
	}
	// otherwise, print a list of stored artists
	else
	{
		std::vector<std::string> ss = mymusic.get_artist_strings();
		// add message concerning the state of the ArtistTree
		if (ss.size() == 0)
		{
			ss.push_back("There are no artists currently stored.");
		}
		else
		{
			ss.insert(ss.begin(), "Artists currently stored:");
		}
		mytable.update(ss);
	}
}