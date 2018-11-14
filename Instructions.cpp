#include "Instructions.h"

Instructions::Instructions(std::string font_file, sf::Vector2f window_size)
	: window_size{ window_size }, display_on{ true }
{
	font.loadFromFile(font_file);

	setup_texts();
	setup_button();
}

void Instructions::setup_texts()
{
	// initialize sf::Text objects
	for (std::string str : insts)
	{
		inst_texts.push_back(sf::Text(str, font, charsize));
	}
	// place the sf::Text objecs, moving from the bottom up
	sf::Vector2f offset{ hoffset, window_size.y - charsize - voffset };
	for (size_t i = 0; i < inst_texts.size(); ++i)
	{
		inst_texts[inst_texts.size() - 1 - i].setFillColor(sf::Color::White);
		inst_texts[inst_texts.size() - 1 - i].setPosition(offset);
		offset = offset - sf::Vector2f(0, charsize + voffset);
	}
}

void Instructions::setup_button()
{
	// place display_text in the bottom right corner
	display_text = sf::Text(display, font, charsize);
	display_text.setFillColor(sf::Color::White);
	sf::Vector2f text_size{ display_text.getGlobalBounds().width, display_text.getGlobalBounds().height };
	sf::Vector2f offset{ hoffset, voffset };
	display_text.setPosition(window_size - text_size - offset);

	display_rect = sf::RectangleShape(text_size + sf::Vector2f{ 2 * hoffset, voffset });
	sf::Vector2f rect_size{ display_rect.getGlobalBounds().width, display_rect.getGlobalBounds().height };
	display_rect.setPosition(window_size - rect_size);
	display_rect.setFillColor(sf::Color::Blue);
	display_rect.setOutlineThickness(-2);
	display_rect.setOutlineColor(sf::Color::White);
}

void Instructions::clicked(sf::Vector2f click)
{
	// if click is on display_rect, toggle truth of display_on
	if (clickRect(display_rect, click))
	{
		display_on = !display_on;
	}
}

void Instructions::draw(sf::RenderTarget& target, sf::RenderStates) const
{
	target.draw(display_rect);
	target.draw(display_text);
	if (display_on)
	{
		for (sf::Text text : inst_texts)
		{
			target.draw(text);
		}
	}
}