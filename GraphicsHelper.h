#pragma once

#ifndef GRAPHICSHELPER_H
#define GRAPHICSHELPER_H

#include <SFML/Graphics.hpp>
#include <vector>

// given a vector of rectangle shapes, return a vector of two floats --- the x value
//  being the sum of the x-sizes of the rectangles plus the x-position of the first
//  rectangle; the y being the y-position of the first
//  (this function is usefull for drawing rectanlges side by side)
sf::Vector2f findPosition(std::vector<sf::RectangleShape>);

#endif
