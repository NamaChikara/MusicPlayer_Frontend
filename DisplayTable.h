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
	// need to load font file when creating a DisplayTable
	DisplayTable(std::string);

	// new strings to display; one Text/RectangleShape for each string
	void update(std::vector<std::string>);	

	// override sf::Drawable's pure virtual function
	virtual void draw(sf::RenderTarget&, sf::RenderStates = sf::RenderStates()) const;

private:
	sf::Font font;
	float charsize = 20;
	std::vector<sf::Text*> texts;
	// one RectangleShape for each Text element to allow for alternating
	//  background colors if desired
	std::vector<sf::RectangleShape*> rects;
};



#endif DisplayTable_H