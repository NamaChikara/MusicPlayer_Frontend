#pragma once

#ifndef InputBar_H
#define InputBar_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "GraphicsHelper.h"
#include "MusicData.h"
#include "DisplayTable.h"

class InputBar : public sf::Drawable
{
public:
	// NOTE: setting the constructor to ask for an sf::Font object instead
	//  of asking for a string of the font file location causes the program 
	//  to crash.
	InputBar(std::string, DisplayTable, MusicData = MusicData());

	// override sf::Drawable's pure virtual function
	virtual void draw(sf::RenderTarget&, sf::RenderStates = sf::RenderStates()) const;

	// find the bottom left corner of the InputBar
	sf::Vector2f bottom_left();	

	// activate text input within the RectangleShape a left click occured in
	void clicked(sf::Vector2f);

	// delete the text within a RectangleShape a right click occured in
	void cleared(sf::Vector2f);

	// add text to sf::Text object if its "xxx_ent" value is set to true
	void input(char);
private:
	DisplayTable mytable;	// where calls to the "get" button display the results
	MusicData mymusic;		// where user input is stored
	sf::Font font;			// must load a font to draw Text objects
	int charsize = 20;		// how large text should be
	float rect_height = 50;	// how tall the RectangleShapes are
	float hoffset = 10;		// horizontal offset of text within rectangle
	// how wide the RectangleShapes are
	float artist_size = 300;
	float album_size = 300;
	float year_size = 100;
	float set_size = 50;
	float get_size = 50;
	// initial string values for text objects
	std::string artist_init = "artist";
	std::string album_init = "album";
	std::string year_init = "year";
	std::string set_init = "set";
	std::string get_init = "get";

	// Text objects will be placed inside the RectangleShapes
	sf::Text artist_text;
	sf::Text album_text;
	sf::Text year_text;
	sf::Text set_text;
	sf::Text get_text;

	sf::RectangleShape artist_rect;
	sf::RectangleShape album_rect;
	sf::RectangleShape year_rect;
	sf::RectangleShape set_rect;
	sf::RectangleShape get_rect;

	// if true, then characters passed in get concatenated into the
	//  respective text objects
	bool artist_ent;
	bool album_ent;
	bool year_ent;

	void place_rects();		// set the widths of the rectangles
	void setup_texts();		// set Text objects' initial size/string parameters
	void text_locations();   // set texts within the rectangles

	// linking set and get buttons to MusicData
	void process_set();		// if the set_rect is clicked, check values of text
							//  objects and take appropriate action on MusicData object
	void process_get();		// if the get_rect is clicked and artist_text is nonempty,
							//  load the albums of that artist to mytable. otherwise load
							//  all artists to mytable.
};

#endif 