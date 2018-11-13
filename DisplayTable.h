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
	sf::Font font;			// for sf::Text objects
	float charsize = 20;	// text height
	std::vector<sf::Text*> texts;
	sf::Vector2f displace;	// where the top left of the table should be
	// one RectangleShape for each Text element to allow for alternating
	//  background colors if desired
	std::vector<sf::RectangleShape*> rects;
};



#endif DisplayTable_H