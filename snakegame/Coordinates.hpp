#pragma once
class Coordinates
{
private:
	int x, y;

public:
	Coordinates(int, int);
	void setCoordinates(int, int);
	int getX();
	int getY();
	void draw(char);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void copyPosition(Coordinates *);
};