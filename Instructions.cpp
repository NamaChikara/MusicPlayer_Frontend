#include "Instructions.h"

Instructions::Instructions(std::string font_file, sf::Vector2f window_size)
	: window_size{ window_size }
{
	font.loadFromFile(font_file);

	setup_texts();
}

void Instructions::setup_texts()
{
	inst0_text = sf::Text(inst0, font, charsize);
	inst1_text = sf::Text(inst1, font, charsize);
	inst2_text = sf::Text(inst2, font, charsize);
	inst3_text = sf::Text(inst3, font, charsize);

	inst0_text.setFillColor(sf::Color::White);
	inst1_text.setFillColor(sf::Color::White);
	inst2_text.setFillColor(sf::Color::White);
	inst3_text.setFillColor(sf::Color::White);

	inst3_text.setPosition(sf::Vector2f(hoffset, window_size.y - charsize - voffset));
	inst2_text.setPosition(sf::Vector2f(hoffset, inst3_text.getPosition().y - charsize - voffset));
	inst1_text.setPosition(sf::Vector2f(hoffset, inst2_text.getPosition().y - charsize - voffset));
	inst0_text.setPosition(sf::Vector2f(hoffset, inst1_text.getPosition().y - charsize - voffset));
}

void Instructions::draw(sf::RenderTarget& target, sf::RenderStates) const
{
	//target.draw(inst_rect);
	target.draw(inst0_text);
	target.draw(inst1_text);
	target.draw(inst2_text);
	target.draw(inst3_text);
}
