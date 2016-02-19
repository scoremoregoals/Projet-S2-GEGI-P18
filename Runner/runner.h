#ifndef RUNNER_H
#define RUNNER_H

#include "vector2.h"

enum Direction
{
	haut,
	bas,
	gauche,
	droite
};

class Runner
{
public:
	Runner();
	Runner(Vector2* position, int life, int speed); //ajout sprite
	~Runner();
	void move(Direction direction);
	void stop();
	
	//setters
	void set_life(int life);
	void set_speed(int speed);
	void set_position(Vector2* position);
	//Sprite;
	
	//getters
	int get_life() {return _life;}
	int get_speed() {return _speed;}
	Vector2* get_position() {return _position;}
	
private:
	Vector2* _position;
	int _life;
	double _speed;
	//Ajout sprite
};


#endif //RUNNER_H
