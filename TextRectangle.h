#pragma once

#ifndef TextRectangle_H
#define TextRectangle_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class TextRectangle : public sf::Drawable 
{
public:
	TextRectangle(sf::Vector2f = sf::Vector2f(0, 0), int fontsize = 12, 
		std::string font_loc = "");
private:
	sf::Font font;	// must load a font to draw Text objects
	
	sf::Text text;
	sf::RectangleShape rect;


};