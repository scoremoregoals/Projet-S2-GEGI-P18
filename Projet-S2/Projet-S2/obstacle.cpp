#include "obstacle.h"
#include <iostream>
#include <cstdlib> 


Obstacle::Obstacle()
{}

Obstacle::~Obstacle()
{}

int Obstacle::spawnHorizontal()    // random position en Y, puis X en dehors de la map pour pas qu'on voit l'obstaacle quand il spawn
{   //a modifier pour enlever positions trop pres du bord
	int random = rand() % (SCREEN_HEIGHT - 100);
	return random;
}

int Obstacle::spawnVertical()   // random position en X, puis Y en dehors de la map pour pas qu'on voit l'obstaacle quand il spawn
{  
	int random = rand() % (SCREEN_WIDTH - 10);
	return random;
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






