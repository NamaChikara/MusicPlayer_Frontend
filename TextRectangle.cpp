#include "TextRectangle.h"

TextRectangle::TextRectangle(sf::Vector2f rectsize, int fontsize,
	std::string font_loc)
	: rect{ rectsize }
{
	text.setCharacterSize(fontsize);
	if (font_loc != "")
	{
		font.loadFromFile(font_loc);
		text.setFont(font);
	}
}

void TextRectangle::draw(sf::RenderTarget& target, sf::RenderStates) const
{
	target.draw(rect);
	target.draw(text);
}