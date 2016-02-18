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
			std::cout << "player move high" << std::endl;
			break;
		case bas:
			std::cout << "player move low" << std::endl;
			break;
		case gauche:
			std::cout << "player move left" << std::endl;
			break;
		case droite:
			std::cout << "player move right" << std::endl;
			break;
	}
}

void Runner:: stop()
{
// Le runner arrete d'avancer et sa vie est nulle, il vient de se faire attraper. 
// Sont corps reste la ou il est.
	_speed = 0;
	_life = 0;
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

// les getters sont deja code dans le fichier runner.h
