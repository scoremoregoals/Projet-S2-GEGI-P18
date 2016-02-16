#ifndef PLATFORM_H
#define PLATFORM_H

#include "obstacle.h"
#include "runner.h"
#include "vector2.h"

const int MAX_POSITIONS = 20; //A CHANGER SELON NBR CASES

class Platform
{
public:
	Platform();
	//Platform(Liste obstacles, Runner player, double obstacleBaseSpeed);      //ajout du tableau de positions
	~Platform();
	void checkPhoneme();
	void checkCollision();
	void moveObstacles();
	void moveCar();
	
	//setters
	//getters

private:
	//Liste _obstacles;	
	Runner _player;
	//Vector2 _positions[MAX_POSITIONS];      //ajout du tableau de position
	double _obstacleBaseSpeed;
};

#endif //PLATFORM_H
