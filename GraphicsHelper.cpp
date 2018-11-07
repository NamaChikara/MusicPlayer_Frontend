#include "GraphicsHelper.h"
#include <SFML/Graphics.hpp>

sf::Vector2f findPosition(std::vector<sf::RectangleShape> rects)
{
	float xpos = 0;
	float ypos = 0;
	for (int i = 0; i < rects.size(); ++i)
	{
		xpos += rects[i].getSize().x;
		if (i == 0)
		{
			xpos += rects[i].getPosition().x;
			ypos += rects[i].getPosition().y;
		}
	}
	return sf::Vector2f{ xpos,ypos };
}

bool clickRect(sf::RectangleShape rect, sf::Vector2i click)
{
	return (rect.getPosition().x <= click.x
		&& click.x <= rect.getPosition().x + rect.getSize().x
		&& rect.getPosition().y <= click.y
		&& click.y <= rect.getPosition().y + rect.getSize().y);
}