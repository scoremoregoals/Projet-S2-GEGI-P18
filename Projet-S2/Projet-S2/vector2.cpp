#include "vector2.h"

Vector2::Vector2()
{}

Vector2::Vector2(int positionX, int positionY)
{
	_positionX = positionX;
	_positionY = positionY;
}

Vector2::~Vector2()
{}

void Vector2::set_positionX(int positionX)
{
	_positionX = positionX;
}

void Vector2::set_positionY(int positionY)
{
	_positionY = positionY;
}

