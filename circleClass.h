#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
class textInfo
{

public:
	sf::Font font;
	int size;
	const int r;
	const int g;
	const int b;
	bool check = true;

	textInfo(const std::string& fontpath, int size, const int r, const int g, const int b)
		: size(size)
		, r(r)
		, g(g)
		, b(b)
		, font(fontpath)
	{
	}
};

class Circle
{
public:

	sf::CircleShape sf_circle;
	float xPos;
	float yPos;
	float dx;
	float dy;
	float radius;
	std::string name;
	const int r;
	const int g;
	const int b;


	//Constructor with given args
	Circle(std::string name, float xPos, float yPos, float dx, float dy, const int r, const int g, const int b, float radius)
		: name(name)
		, xPos(xPos)
		, yPos(yPos)
		, dx(dx)
		, dy(dy)
		, r(r)
		, g(g)
		, b(b)
		, radius(radius)
		, sf_circle(radius)
	{
	}
	void intiateCircle()
	{
		sf_circle.setFillColor(sf::Color(r, g, b));
		sf_circle.setPosition({ xPos, yPos });

	}

		
};

class Rectangle
{

public:
	sf::RectangleShape sf_rect;
	std::string name;
	float dx;
	float dy;
	float width;
	float height;
	float xPos;
	float yPos;
	const int r;
	const int g;
	const int b;

	// Default constructor for text purposes
	Rectangle()
		: xPos(0), yPos(0), dx(0), dy(0), name(""), r(0), g(0), b(0), width(0), height(0)
	{
	}

	Rectangle(std::string name, float xPos, float yPos, float dx, float dy, const int r, const int g, const int b, float Width, float Height)

		: name(name)
		, xPos(xPos)
		, yPos(yPos)
		, dx(dx)
		, dy(dy)
		, r(r)
		, g(g)
		, b(b)
		, width(Width)
		, height(Height)
		, sf_rect({ Width, Height })
	{
	}
	void intiateRect()
	{
		sf_rect.setFillColor(sf::Color(r, g, b));
		sf_rect.setPosition({ xPos, yPos });

	}
};


