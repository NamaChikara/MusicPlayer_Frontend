#pragma once

#ifndef DisplayTable_H
#define DisplayTable_H

#include <SFML/Graphics.hpp>
#include "GraphicsHelper.h"
#include <iostream>
#include <string>
#include <vector>

class DisplayTable
{
public:
	// need to load font file when creating a DisplayTable; the Vector2f
	//  offsets the placement of the table
	DisplayTable(std::string, sf::Vector2f = sf::Vector2f{ 0,0 });

	// new strings to display; one Text/RectangleShape for each string
	void update(std::vector<std::string>&);	

	// set where the top left of the table should be
	void set_displace(sf::Vector2f);

	// override sf::Drawable's pure virtual function
	virtual void draw(sf::RenderTarget&, sf::RenderStates = sf::RenderStates()) const;
private:
	sf::Font font;			// must load a font to draw Text objects
	int charsize = 20;		// how large text should be
	float rect_height = 50;	// how tall the RectangleShapes are
	float rect_width = 300; // how wide the RectangleShapes are
	float hoffset = 10;		// horizontal offset of text within rectangle
	float voffset = (rect_height - charsize) / 2;
	sf::Vector2f displace;	// where the top left of the table should be
	// one RectangleShape for each Text element to allow for alternating
	//  background colors if desired
	std::vector<sf::Text*> texts;
	std::vector<sf::RectangleShape*> rects;
};



#endif DisplayTable_H