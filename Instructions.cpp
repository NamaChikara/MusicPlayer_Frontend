#include "Instructions.h"

Instructions::Instructions(std::string font_file, sf::Vector2f window_size)
	: window_size{ window_size }
{
	font.loadFromFile(font_file);

	setup_texts();
}

void Instructions::setup_texts()
{
	for (std::string str : insts)
	{
		inst_texts.push_back(sf::Text(str, font, charsize));
	}

	sf::Vector2f offset{ hoffset, window_size.y - charsize - voffset };
	for (size_t i = 0; i < inst_texts.size(); ++i)
	{
		inst_texts[inst_texts.size() - 1 - i].setFillColor(sf::Color::White);
		inst_texts[inst_texts.size() - 1 - i].setPosition(offset);
		offset = offset - sf::Vector2f(0, charsize + voffset);
	}
}

void Instructions::draw(sf::RenderTarget& target, sf::RenderStates) const
{
	//target.draw(inst_rect);
	for (sf::Text text : inst_texts)
	{
		target.draw(text);
	}
}
