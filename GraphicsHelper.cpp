#include "GraphicsHelper.h"
#include <SFML/Graphics.hpp>

sf::Vector2f topRight(sf::RectangleShape rect)
{
	float xpos = rect.getPosition().x + rect.getSize().x;
	float ypos = rect.getPosition().y;
	return sf::Vector2f{ xpos,ypos };
}

sf::Vector2f botLeft(sf::RectangleShape *rect)
{
	float xpos = rect->getPosition().x;
	float ypos = rect->getPosition().y + rect->getSize().y;
	return sf::Vector2f{ xpos,ypos };
}

bool clickRect(sf::RectangleShape rect, sf::Vector2i click)
{
	return (rect.getPosition().x <= click.x
		&& click.x <= rect.getPosition().x + rect.getSize().x
		&& rect.getPosition().y <= click.y
		&& click.y <= rect.getPosition().y + rect.getSize().y);
}