#include "obstacle.h"
#include <iostream>
#include <cstdlib> 
#include <ctime> 


Obstacle::Obstacle()
{}

Obstacle::~Obstacle()
{}

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

void Obstacle::set_id(int id)
{
	_id = id;
}

void Obstacle::set_damage(int damage)
{
	_damage = damage;
}


void Obstacle::set_lien(Obstacle* lien)
{
	_lien = lien;
}

void Obstacle::set_type(TypeObstacle type)
{
	_type = type;
}






