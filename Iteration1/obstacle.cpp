#include "obstacle.h"
#include <iostream>
#include <cstdlib> 
#include <ctime> 


Obstacle::Obstacle()
{
	_speed = 0;
	_width = 0;
	_height = 0;
	_id = 0;
	_damage = 0;
	for (int i = 0; i < MAX_VALIDSPAWN; i++)
	{
		_validSpawn[i] = NULL;
	}
	_lien = NULL;
}

Obstacle::Obstacle(int speed, int width, int height, int id, int damage, TypeObstacle type, Vector2* validSpawn[MAX_VALIDSPAWN]) //CONSTRUCTEUR POUR TABLEAU OBSTACLES DANS PLATEFOR
{
	_speed = speed;
	_width = width;
	_height = height;
	_id = id;
	_type = type;
	_damage = damage;
	for (int i = 0; i < MAX_VALIDSPAWN; i++)
	{
		_validSpawn[i] = validSpawn[i];
	}
}
Obstacle::~Obstacle()
{
	for (int i = 0; i < MAX_VALIDSPAWN; i++)
	{
		delete _validSpawn[i];
		_validSpawn[i] = NULL;
	}
}

void Obstacle::afficherDetails() //a modif pour ajouter dautres trucs a afficher
{
	std::cout << "new position obstacle id : " << _id << " : x = " << _position->get_positionX() << " y = "
		<< _position->get_positionY() << std::endl;
}
void Obstacle::Update()
{
	switch (_type)
	{
		case hlaser :
			_position->set_positionX(_position->get_positionX() + _speed);
			break;
		case vlaser:
			_position->set_positionY(_position->get_positionY() + _speed);
			break;
		case powerUp :
			_position->set_positionY(_position->get_positionY() + _speed);
			break;
		default:
			break;
	}
	afficherDetails();
}

void Obstacle::draw()
{}

void Obstacle::spawn()            // choisi une position random a partir de validSpawn et l'assigne a la position de l'obstacle
{
	srand(time(NULL));
    int random = rand() % MAX_VALIDSPAWN;
    set_position(_validSpawn[random]);
}


//setters
void Obstacle::set_position(Vector2* position)
{
	_position = position;
}

void Obstacle::set_speed(int speed)
{
	_speed = speed;
}

void Obstacle::set_width(int width)
{
	_width = width;
}

void Obstacle::set_height(int height)
{
	_height = height;
}

void Obstacle::set_ID(int id)
{
	_id = id;
}

void Obstacle::set_damage(int damage)
{
	_damage = damage;
}

void Obstacle::set_validSpawn(Vector2* validSpawn[MAX_VALIDSPAWN])
{
	for (int i = 0; i < MAX_VALIDSPAWN; i++)
	{
		_validSpawn[i] = validSpawn[i];
	}
}

void Obstacle::set_lien(Obstacle* lien)
{
	_lien = lien;
}

void Obstacle::set_type(TypeObstacle type)
{
	_type = type;
}






