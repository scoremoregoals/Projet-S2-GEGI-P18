#include "id.h"


ObstacleID::ObstacleID()
{}

ObstacleID::ObstacleID(int id, bool isTaken)
{
	_id = id;
	_isTaken = isTaken;
}

ObstacleID::~ObstacleID()
{}

void ObstacleID::set_id(int id)
{
	_id = id;
}

void ObstacleID::set_taken(bool taken)
{
	_isTaken = taken;
}