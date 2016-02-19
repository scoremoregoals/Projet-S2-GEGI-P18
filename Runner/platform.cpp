#include "platform.h"
#include <iostream> 

Platform::Platform()
{
		//_obstacles = obstacles;
		_player = NULL;
		_obstacleBaseSpeed = 0;
		for (int i = 0; i < MAX_POSITIONS; i++)
		{
			_positions[i] = NULL;	
		}
		_nbrObstacles = 0;
}

Platform::~Platform()
{
	for (int i = 0; i < MAX_POSITIONS; i++)
	{
		delete _positions[i];
		_positions[i] = NULL;
	}
}

Platform::Platform( Runner & player, double obstacleBaseSpeed, Vector2* positions[MAX_POSITIONS], Liste& liste)
{
		//_obstacles = obstacles;
		_player = &player;
		_obstacleBaseSpeed = obstacleBaseSpeed;
		for (int i = 0; i < MAX_POSITIONS; i++)
		{
			_positions[i] = positions[i];	
		}
		_nbrObstacles = 0;
		_listeObstacles = &liste;
		
}

void Platform::creerObstacle(Obstacle& obstacle)
{
	if (_nbrObstacles >= MAX_OBSTACLES)    //ne peut ajouter plus que le max, modifier max (.h) pour ajouter plus
		return;
	_obstacles[_nbrObstacles] = &obstacle;
	_nbrObstacles++;
}

void Platform::ajouterAuJeu(Obstacle& obstacle)
{
	_listeObstacles->ajouter(obstacle);	
	obstacle.spawn();
}

//setters
void Platform::set_player(Runner & player)
{
	_player = &player;
}

void Platform::set_obstacleBaseSpeed(double obstacleBaseSpeed)
{
	_obstacleBaseSpeed = obstacleBaseSpeed;
}

void Platform::set_positions(Vector2 positions[MAX_POSITIONS])
{
	for (int i = 0; i < MAX_POSITIONS; i++)
	{
		_positions[i] = &positions[i];
	}
}







