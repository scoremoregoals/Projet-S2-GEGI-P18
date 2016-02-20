#include "runner.h"
#include <iostream>

Runner::Runner()
{
	_position = NULL;
	_life = 0;
	_speed = 0;
	_width = 0;
	_height = 0;
}

Runner::~Runner()
{}

Runner::Runner(Vector2* position, int life, int speed, int width, int height) //ajout sprite
{
	_position = position; // AJOUTER POSITION INITIALE?
	_life = life;
	_speed = speed;
	_width = width;
	_height = height;
}

void Runner::move(Direction direction)
{
	switch (direction)
	{
		case haut:
			std::cout << "player move up" << std::endl;
			_position->set_positionY(_position->get_positionY() - _speed);
			break;
		case bas:
			std::cout << "player move down" << std::endl;
			_position->set_positionY(_position->get_positionY() + _speed);
			break;
		case gauche:
			std::cout << "player move left" << std::endl;
			_position->set_positionX(_position->get_positionX() - _speed);
			break;
		case droite:
			std::cout << "player move right" << std::endl;
			_position->set_positionX(_position->get_positionX() + _speed);
			break;
		default :
			break;
	}
	std::cout << "new position : x = " << _position->get_positionX() << " y = " << _position->get_positionY() << std::endl;
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

void Runner::set_position(Vector2* position)
{
	_position = position;
}

void Runner::set_width(int width)
{
	_width = width;
}

void Runner::set_height(int height)
{
	_height = height;	
}

