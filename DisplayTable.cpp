#include "DisplayTable.h"

DisplayTable::DisplayTable(std::string font_file, sf::Vector2f displace)
	: displace{ displace }
{
	font.loadFromFile(font_file);
}

void DisplayTable::update(std::vector<std::string> &labels)
{
	texts.clear();
	rects.clear();
	for (int i = 0; i < labels.size(); ++i)
	{
		rects.push_back(new sf::RectangleShape(sf::Vector2f(rect_width, rect_height)));
		rects[i]->setFillColor(sf::Color::Black);
		if (i == 0)
		{
			rects[i]->setPosition(displace);
		}
		if (i > 0)
		{
			rects[i]->setPosition(botLeft(rects[i - 1]));
		}
		texts.push_back(new sf::Text(labels[i], font, charsize));
		texts[i]->setFillColor(sf::Color::White);
		texts[i]->setPosition(rects[i]->getPosition() + sf::Vector2f(hoffset, voffset));
	}
}

void DisplayTable::set_displace(sf::Vector2f disp)
{
	displace = disp;
}

void DisplayTable::draw(sf::RenderTarget& target, sf::RenderStates) const
{
	for (sf::RectangleShape *rect : rects)
	{
		target.draw(*rect);
	}
	for (sf::Text *text : texts)
	{
		target.draw(*text);
	}
}