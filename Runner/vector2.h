#ifndef VECTOR2_H
#define VECTOR2_H


/*
Je savais pas s'il y'avait deja une classe qui existait pour ca fek j'en ai faite une
*/

class Vector2
{
public:
	Vector2(); 
	Vector2(int positionX, int positionY);
	~Vector2();
	
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
