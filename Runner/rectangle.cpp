#include "rectangle.h"


Rectangle::Rectangle()
{
	_coordTopLeft = NULL;
	_coordTopRight = NULL;
	_coordBottomLeft = NULL;
	_coordBottomRight = NULL;
}

Rectangle::Rectangle(int width, int height, int positionX, int positionY)
{
	_coordTopLeft = new Vector2(positionX, positionY);
	_coordTopRight = new Vector2(positionX + width, positionY);
	_coordBottomLeft = new Vector2(positionX, positionY + height);
	_coordBottomRight = new Vector2(positionX + width, positionY + height);
}

Rectangle::~Rectangle()
{}
	
bool Rectangle::checkIntersect(Rectangle* rect)
{
	return false;
}

//setters
void Rectangle::set_coordTL(Vector2* coordTL)
{
	_coordTopLeft = coordTL;
}

void Rectangle::set_coordTR(Vector2* coordTR)
{
	_coordTopRight = coordTR;
}

void Rectangle::set_coordBL(Vector2* coordBL)
{
	_coordBottomLeft = coordBL;
}

void Rectangle::set_coordBR(Vector2* coordBR)
{
	_coordBottomRight = coordBR;
}



