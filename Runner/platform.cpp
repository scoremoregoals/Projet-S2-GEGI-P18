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
}

Platform::~Platform()
{}

Platform::Platform( Runner & player, double obstacleBaseSpeed, Vector2 positions[MAX_POSITIONS]) //liste obstacle
{
		//_obstacles = obstacles;
		_player = &player;
		_obstacleBaseSpeed = obstacleBaseSpeed;
		for (int i = 0; i < MAX_POSITIONS; i++)
		{
			_positions[i] = &positions[i];	
		}
		
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







