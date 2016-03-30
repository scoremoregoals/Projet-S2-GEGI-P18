#include "obstacle.h"
#include <iostream>
#include <cstdlib> 


Obstacle::Obstacle()
{
}

Obstacle::~Obstacle()
{}

void Obstacle::spawnHorizontal()  
{
}

void Obstacle::spawnVertical()  
{  
	int random = rand() % (SCREEN_WIDTH - 10);
	setPos(random, 0 - _height);
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






