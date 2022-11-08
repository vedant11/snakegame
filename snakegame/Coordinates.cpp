#include "Coordinates.hpp"
#include "Utilities.hpp"
#include <iostream>

Coordinates::Coordinates(int x = 0, int y = 0)
{
	setCoordinates(x, y);
}
void Coordinates::setCoordinates(int x, int y)
{
	this->x = x;
	this->y = y;
	return;
}
int Coordinates::getX()
{
	return this->x;
}
int Coordinates::getY()
{
	return this->y;
}
void Coordinates::draw(char c)
{
	placeXY(this->x, this->y);
	std::cout << c;
}
void Coordinates::moveDown()
{
	this->setCoordinates(this->x, y - 1);
	this->draw('o');
}
void Coordinates::moveLeft()
{
	this->setCoordinates(x - 1, y);
	this->draw('o');
}
void Coordinates::moveUp()
{
	this->setCoordinates(x, y + 1);
	this->draw('o');
}
void Coordinates::moveRight()
{
	this->setCoordinates(x + 1, y);
	this->draw('o');
}
void Coordinates::copyPosition(Coordinates *coord)
{
	coord->x = this->x;
	coord->y = this->y;
}