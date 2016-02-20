#include "vector2.h"
#include <iostream>

class Rectangle
{
public:
	Rectangle();
	Rectangle(int width, int height, int positionX, int positionY);
	virtual ~Rectangle();
	
	bool checkIntersect(Rectangle* rect);
	
	//setters
	void set_coordTL(Vector2* coordTL);
	void set_coordTR(Vector2* coordTR);
	void set_coordBL(Vector2* coordBL);
	void set_coordBR(Vector2* coordBR);
	
	//getters
	Vector2* get_coordTL() {return _coordTopLeft;}
	Vector2* get_coordTR() {return _coordTopRight;}
	Vector2* get_coordBL() {return _coordBottomLeft;}
	Vector2* get_coordBR() {return _coordBottomRight;}
	
private:
	Vector2* _coordTopLeft;
	Vector2* _coordTopRight;
	Vector2* _coordBottomLeft;
	Vector2* _coordBottomRight;
};
