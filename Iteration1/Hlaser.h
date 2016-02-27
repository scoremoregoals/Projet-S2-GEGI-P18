#ifndef HLASER_H
#define HLASER_H

#include "obstacle.h"

class Hlaser : public Obstacle
{
public:
	Hlaser();
	Hlaser(int speed, int width, int height, int damage);
	~Hlaser();

	//virtuals
	void Update();
	void draw();
	void afficherDetails();
};

#endif