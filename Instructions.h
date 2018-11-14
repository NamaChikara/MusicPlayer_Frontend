// This class is displayed at the bottom of the program window to inform
//  the user of the features.

#pragma once

#ifndef Instructions_H
#define Instructions_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "GraphicsHelper.h"

class Instructions : public sf::Drawable
{
public:
	Instructions(std::string font_file, sf::Vector2f window_size);

	// override sf::Drawable's pure virtual function
	virtual void draw(sf::RenderTarget&, sf::RenderStates = sf::RenderStates()) const;

	// check if display_rect was clicked; toggle value of display_on if so
	void clicked(sf::Vector2f);	
private:
	sf::Vector2f window_size;	// use to place Texts at bottom of window
	sf::Font font;
	float charsize = 20;	// how large text should be
	float voffset = 10;		// vertical distance between text objects
	float hoffset = 10;		// horizontal distance from side of window
	bool display_on;		// if true, draw instructions; if false, do not draw

	sf::RectangleShape display_rect;	// click to toggle instructions
	sf::Text display_text;
	std::string display = "Instructions On/Off";

	std::vector<sf::Text> inst_texts;
	std::vector<std::string> insts{
		"Instructions for use:",
		"-> right click to clear contents, left click to focus input, tab to move between fields",
		"-> click 'set':",
		"   a) album field is empty: the artist is added to list of artists",
		"   b) album field nonempty: adds album to the artist's list of albums",
		"-> click 'get':",
		"   a) artist field is empty: prints a list of stored artists",
		"   b) artist field nonempty: prints a list of stored albums for that artist"
	};

	void setup_texts();	// calculate where to place sf::Text objects
	void setup_button();// calculate where to place display_rect/text
};

#endif Instructions_H