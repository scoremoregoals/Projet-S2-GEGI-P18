#ifndef VLASER_H
#define VLASER_H

#include "obstacle.h"
#include "global.h"

class Vlaser : public Obstacle
{
public:
	Vlaser();
	Vlaser(int speed, int width, int height, int damage);
	~Vlaser();

	//virtuals
	void update();
};

#endif