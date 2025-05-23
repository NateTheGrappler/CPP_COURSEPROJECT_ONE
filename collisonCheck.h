#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cstdlib>  // For integers
#include <cmath>    // For floating-point numbers
#include <fstream>



void checkWallCollisionCircle(sf::CircleShape& circle, Circle& circleVals, int windowHeight, int windowWidth)
{
	//Checks the wall collision for the left wall
	if (circle.getPosition().x < 0.0f)
	{
		circleVals.dx = abs(circleVals.dx);
	}
	//Checks the wall collision for the right wall
	if (circle.getPosition().x + (circleVals.radius * 2) > windowWidth)
	{
		circleVals.dx = -(circleVals.dx);
	}
	//Checks the wall collision for the ceiling wall
	if (circle.getPosition().y < 0.0f)
	{
		circleVals.dy = abs(circleVals.dy);
	}
	//Checks the wall collision for the floor wall
	if (circle.getPosition().y + (circleVals.radius * 2) > windowHeight)
	{
		circleVals.dy = -(circleVals.dy);
	}
}

void checkWallCollisionRect(sf::RectangleShape& rectangle, Rectangle& rectVals, int windowHeight, int windowWidth)
{
	//Checks the wall collision for the left wall
	if (rectangle.getPosition().x < 0.0f)
	{
		rectVals.dx = abs(rectVals.dx);
	}
	//Checks the wall collision for the right wall 
	if (rectangle.getPosition().x + (rectVals.width) > windowWidth)
	{
		rectVals.dx = -(rectVals.dx);
	}
	//Checks the wall collision for the ceiling wall
	if (rectangle.getPosition().y < 0.0f)
	{
		rectVals.dy = abs(rectVals.dy);
	}
	//Checks the wall collision for the floor wall 
	if (rectangle.getPosition().y + (rectVals.height) > windowHeight)
	{
		rectVals.dy = -(rectVals.dy);
	}
}
std::vector<std::string> getFileInfo() 
{
	std::vector<std::string> instructions;

	std::fstream inputFile("inputFile.txt");
	if (!inputFile.is_open())
	{
		std::cerr << "Could not open text file, fuck did you do" << std::endl;
	}
	std::string word;
	while (inputFile >> word) {
		instructions.push_back(word);
	}
	inputFile.close();

	return instructions;
}

