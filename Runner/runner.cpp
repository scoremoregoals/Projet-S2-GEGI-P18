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

void Runner::move(Direction direction)
{
	switch (direction)
	{
		case haut:
			std::cout << "player move haut" << std::endl;
			break;
		case bas:
			std::cout << "player move bas" << std::endl;
			break;
		case gauche:
			std::cout << "player move gauche" << std::endl;
			break;
		case droite:
			std::cout << "player move droit" << std::endl;
			break;
	}
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
