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
}

Obstacle::Obstacle(double speed, int width, int height, int id, int damage, Vector2* validSpawn[MAX_VALIDSPAWN])
{
	_speed = speed;
	_width = width;
	_height = height;
	_id = id;
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

void Obstacle::spawn()            // choisi une position random a partir de validSpawn et l'assigne a la position de l'obstacle
{
	srand((unsigned)time(0)); 
    int random = rand() % MAX_VALIDSPAWN;
    set_position(_validSpawn[random]);
}


//setters
void Obstacle::set_position(Vector2* position)
{
	_position = position;
}

void Obstacle::set_speed(double speed)
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









