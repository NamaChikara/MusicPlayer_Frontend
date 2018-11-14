// This class is displayed at the bottom of the program window to inform
//  the user of the features.

#pragma once

#ifndef Instructions_H
#define Instructions_H

#include <SFML/Graphics.hpp>
#include <string>

class Instructions : public sf::Drawable
{
public:
	Instructions(std::string font_file, sf::Vector2f window_size);

	// override sf::Drawable's pure virtual function
	virtual void draw(sf::RenderTarget&, sf::RenderStates = sf::RenderStates()) const;

private:
	sf::Vector2f window_size;	// use to place Texts at bottom of window
	float charsize = 20;	// how large text should be
	float voffset = 10;		// vertical distance between text objects
	float hoffset = 10;		// horizontal distance from side of window

	sf::RectangleShape inst_rect;	// where the text will be written
	sf::Font font;

	sf::Text inst0_text;
	sf::Text inst1_text;
	sf::Text inst2_text;
	sf::Text inst3_text;

	std::string inst0 = "Instructions for use:";
	std::string inst1 = "-> right click on a text field to clear contents, left click to "
		"focus text input, tab to move between fields";
	std::string inst2 = "-> click 'set': if album field is blank, the artist is added to list "
		"of artists, if album is present, album is added to that artist's list of albums";
	std::string inst3 = "-> click 'get': if an artist name is present, attempts to retrieve a list "
		"of that artist's abums; if no artist name, prints a list of stored artists";

	void setup_texts();	// calculate where to place sf::Text objects
};

#endif Instructions_H