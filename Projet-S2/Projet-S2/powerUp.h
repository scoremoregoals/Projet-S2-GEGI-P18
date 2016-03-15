#ifndef POWERUP_H
#define POWERUP_H

#include "obstacle.h"
#include "global.h"

class PowerUp : public Obstacle
{
public:
	PowerUp();
	PowerUp::PowerUp(int speed, int width, int height, int damage);
	~PowerUp();

	//virtuals
	void update();
};

#endif