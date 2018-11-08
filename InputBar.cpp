#include "InputBar.h"

InputBar::InputBar(std::string font_file)
{
	font.loadFromFile(font_file);

	place_rects();
	setup_texts();
	text_locations();
}

void InputBar::draw(sf::RenderTarget& target, sf::RenderStates) const
{
	target.draw(artist_rect);
	target.draw(album_rect);
	target.draw(year_rect);
	target.draw(set_rect);
	target.draw(get_rect);

	target.draw(artist_text);
	target.draw(album_text);
	target.draw(year_text);
	target.draw(set_text);
	target.draw(get_text);
}

void InputBar::place_rects()
{
	artist_rect.setSize(sf::Vector2f{ 200,rect_height });
	artist_rect.setFillColor(sf::Color::Blue);

	album_rect.setSize(sf::Vector2f{ 200,rect_height });
	album_rect.setPosition(topRight(artist_rect));
	album_rect.setFillColor(sf::Color::Red);

	year_rect.setSize(sf::Vector2f{ 100,rect_height });
	year_rect.setPosition(topRight(album_rect));
	year_rect.setFillColor(sf::Color::Blue);

	set_rect.setSize(sf::Vector2f{ 50,rect_height });
	set_rect.setPosition(topRight(year_rect));
	set_rect.setFillColor(sf::Color::Red);

	get_rect.setSize(sf::Vector2f{ 50,rect_height });
	get_rect.setPosition(topRight(set_rect));
	get_rect.setFillColor(sf::Color::Blue);
}

void InputBar::setup_texts()
{
	artist_text.setFont(font);
	artist_text.setCharacterSize(charsize);
	artist_text.setString(artist_init);
	artist_text.setFillColor(sf::Color(255, 255, 255));

	album_text.setFont(font);
	album_text.setString(album_init);
	album_text.setCharacterSize(charsize);
	artist_text.setFillColor(sf::Color(255, 255, 255));

	year_text.setFont(font);
	year_text.setString(year_init);
	year_text.setCharacterSize(charsize);
	artist_text.setFillColor(sf::Color(255, 255, 255));

	set_text.setFont(font);
	set_text.setString(set_init);
	set_text.setCharacterSize(charsize);
	artist_text.setFillColor(sf::Color(255, 255, 255));

	get_text.setFont(font);
	get_text.setString(get_init);
	get_text.setCharacterSize(charsize);
	artist_text.setFillColor(sf::Color(255, 255, 255));
}

void InputBar::text_locations()
{
	float voffset = (rect_height - (float)charsize) / 2;
	artist_text.setPosition(artist_rect.getPosition() + sf::Vector2f(hoffset, voffset));
	album_text.setPosition(album_rect.getPosition() + sf::Vector2f(hoffset, voffset));
	year_text.setPosition(year_rect.getPosition() + sf::Vector2f(hoffset, voffset));
	set_text.setPosition(set_rect.getPosition() + sf::Vector2f(hoffset, voffset));
	get_text.setPosition(get_rect.getPosition() + sf::Vector2f(hoffset, voffset));
}

sf::Vector2f InputBar::bottom_left()
{
	return botLeft(&artist_rect);
}