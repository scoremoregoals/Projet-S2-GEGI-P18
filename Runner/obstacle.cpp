#include "obstacle.h"
#include <iostream>

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

Obstacle::Obstacle(double speed, int width, int height, int id, int damage, Vector2 validSpawn[MAX_VALIDSPAWN])
{
	_speed = speed;
	_width = width;
	_height = height;
	_id = id;
	_damage = damage;
	for (int i = 0; i < MAX_VALIDSPAWN; i++)
	{
		_validSpawn[i] = &validSpawn[i];
	}
}

Obstacle::~Obstacle()
{}

void Obstacle::spawn()            // choisi une position random a partir de validSpawn
{
	
}
