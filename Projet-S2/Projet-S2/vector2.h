#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
public:
	/**
	 * @brief      Constructor
	 */
	Vector2();
	/**
	 * @brief      New position of an object
	 *
	 * @param[in]  positionX  Position X of the object
	 * @param[in]  positionY  Position Y of the object
	 */
	Vector2(int positionX, int positionY);
	/**
	 * @brief      Deconstructor
	 */
	virtual ~Vector2();
	
	//setters
	void set_positionX(int positionX);
	void set_positionY(int positionY);
	//getters
	int get_positionX() {return _positionX;}
	int get_positionY() {return _positionY;}

private:
	int _positionX;
	int _positionY;
};



#endif //VECTOR2_H
