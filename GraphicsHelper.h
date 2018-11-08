#pragma once

#ifndef GRAPHICSHELPER_H
#define GRAPHICSHELPER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>

// given a vector of rectangle shapes, return a vector of two floats --- the x value
//  being the sum of the x-sizes of the rectangles plus the x-position of the first
//  rectangle; the y being the y-position of the first
//  (this function is usefull for drawing rectanlges side by side)
sf::Vector2f topRight(sf::RectangleShape&);

// similar to topRight, this returns the coordinate of the bottom left corner
sf::Vector2f botLeft(sf::RectangleShape*);

// returns true if the point specified by the vector lies within the rectangle (border inclusive)
bool clickRect(sf::RectangleShape&, sf::Vector2f);

#endif
