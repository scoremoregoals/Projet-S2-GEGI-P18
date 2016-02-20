

class Rectangle
{
public:
	Rectangle();
	Rectangle(int width, int height, int positionX, int positionY);
	virtual ~Rectangle();
	
	bool checkIntersect(Rectangle* rect);
	
	//setters
	void set_topY(int topY);
	void set_leftX(int leftX);
	void set_rightX(int rightX);
	void set_bottomY(int bottomY);
	
	//getters
	int get_topY() {return _topY;}
	int get_leftX() {return _leftX;}
	int get_rightX() {return _rightX;}
	int get_bottomY() {return _bottomY;}
	
private:
	int _topY;       //cotes du rectangle
	int _leftX;
	int _rightX;
	int _bottomY;
};
