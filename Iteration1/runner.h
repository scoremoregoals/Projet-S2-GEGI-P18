#ifndef RUNNER_H
#define RUNNER_H

#include "vector2.h"



class Runner
{
public:
	Runner();
	Runner(Vector2* position, int life, int speed, int width, int height); //ajout sprite
	virtual ~Runner();
	
	void Update(); //appele a chaque frame, sert a updater la position, la vie, etc selon les actions du frame -> a implementer
	void afficherDetails();
	Direction move(Direction direction);
	void stop();
	
	//setters
	void set_life(int life);
	void set_speed(int speed);
	void set_position(Vector2* position);
	void set_width(int width);
	void set_height(int height);
	//Sprite;
	
	//getters
	int get_life() {return _life;}
	int get_speed() {return _speed;}
	Vector2* get_position() {return _position;}
	int get_width() {return _width;}
	int get_height() {return _height;}
	
private:
	Vector2* _position;
	int _width;
	int _height;
	int _life;
	int _speed;
	//Ajout sprite
};


#endif //RUNNER_H
