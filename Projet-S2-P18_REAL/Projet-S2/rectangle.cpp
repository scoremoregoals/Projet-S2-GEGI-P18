#include "rectangle.h"

Rectangle::Rectangle()
{
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


