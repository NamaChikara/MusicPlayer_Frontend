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