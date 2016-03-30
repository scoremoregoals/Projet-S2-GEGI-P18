#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
	/**
	 * @brief      Initialize all of the attributs of the class
	 */
	Rectangle();
	/**
	 * @brief      Initialize a rectangle
	 *
	 * @param[in]  width      Width size in pixel
	 * @param[in]  height     Height size in pixel
	 * @param[in]  positionX  Position on the frame in X
	 * @param[in]  positionY  Position on the frame in Y
	 */
	Rectangle(int width, int height, int positionX, int positionY);
	/**
	 * @brief      Deconstructor
	 */
	virtual ~Rectangle();
	
	/**
	 * @brief      Look if the rectangle intersect with the limit of the frame
	 *
	 * @param      rect  Rectangle to verify
	 *
	 * @return     True or false if collide or not
	 */
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

#endif //RECTANGLE_H
