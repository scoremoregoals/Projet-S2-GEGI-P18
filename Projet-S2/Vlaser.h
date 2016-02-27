#ifndef VLASER_H
#define VLASER_H

#include "obstacle.h"

class Vlaser : public Obstacle
{
public:
	Vlaser();
	Vlaser(int speed, int width, int height, int damage);
	~Vlaser();

	//virtuals
	void Update();
	void draw();
	void afficherDetails();
};

#endif