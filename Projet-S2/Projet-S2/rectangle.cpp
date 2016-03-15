#include "rectangle.h"

Rectangle::Rectangle()
{
	_topY = 0;
	_leftX = 0;
	_rightX = 0;
	_bottomY = 0;
}

Rectangle::Rectangle(int width, int height, int positionX, int positionY)
{
	_topY = positionY;
	_leftX = positionX;
	_rightX = positionX + width;
	_bottomY = positionY + height;
}

Rectangle::~Rectangle()
{}
	
bool Rectangle::checkIntersect(Rectangle* rect)   //pas sur, peut etre modifié si pas correcte, a tester
{
	if ( this->get_leftX()  > rect->get_rightX() || this->get_rightX()  < rect->get_leftX() ||
   		 this->get_topY()  > rect->get_bottomY() || this->get_bottomY() < rect->get_topY() ) 
   	{
   		return false;
   	}
   	return true;
}

//setters
void Rectangle::set_topY(int topY)
{
	_topY = topY;
}

void Rectangle::set_leftX(int leftX)
{
	_leftX = leftX;
}

void Rectangle::set_rightX(int rightX)
{
	_rightX = rightX;
}

void Rectangle::set_bottomY(int bottomY)
{
	_bottomY = bottomY;
}



