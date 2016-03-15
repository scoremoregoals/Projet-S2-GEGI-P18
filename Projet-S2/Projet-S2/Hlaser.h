#ifndef HLASER_H
#define HLASER_H

#include "obstacle.h"
#include "global.h"

class Hlaser : public Obstacle
{
public:
	Hlaser();
	Hlaser(int speed, int width, int height, int damage);
	~Hlaser();

	//virtuals
	void update();
};

#endif