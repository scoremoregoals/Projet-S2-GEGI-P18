#include "runner.h"
#include <iostream>

Runner::Runner()
{
	_position = NULL;
	_life = 0;
	_speed = 0;
}

Runner::~Runner()
{}

Runner::Runner(Vector2 & position, int life, int speed) //ajout sprite
{
	_position = &position;
	_life = life;
	_speed = speed;
}

//setters
void Runner::set_life(int life)
{
	_life = life;
}

void Runner::set_speed(int speed)
{
	_speed = speed;
}

void Runner::set_position(Vector2 position)
{
	_position = &position;
}
