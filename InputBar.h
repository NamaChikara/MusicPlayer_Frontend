#pragma once

#ifndef InputBar_H
#define InputBar_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "GraphicsHelper.h"

class InputBar : public sf::Drawable
{
public:
	// NOTE: setting the constructor to ask for an sf::Font object instead
	//  of asking for a string of the font file location causes the program 
	//  to crash.
	InputBar(std::string);

	// override sf::Drawable's pure virtual function
	virtual void draw(sf::RenderTarget&, sf::RenderStates = sf::RenderStates()) const;

private:
	sf::Font font;	// must load a font to draw Text objects
	int charsize = 20;	// how large text should be
	float rect_height = 50;	// how tall the RectangleShapes are
	float hoffset = 5; // horizontal offset of text within rectangle

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

	void place_rects();		// set the widths of the rectangles
	void setup_texts();		// set Text objects' initial size/string parameters
	void text_locations();   // set texts within the rectangles
};


#endif InputBar_H