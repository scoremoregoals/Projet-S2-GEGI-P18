#ifndef HLASER_H
#define HLASER_H

#include "obstacle.h"

class Hlaser : public Obstacle
{
public:
	Hlaser();
	Hlaser(int speed, int width, int height, int damage, Vector2* horizontalValidSpawn[MAX_VALIDSPAWN_HORIZ]);
	~Hlaser();

	//virtuals
	void Update();
	void draw();
	void afficherDetails();
	void move();
	void spawnHorizontal();
	virtual void spawnVertical();

	void set_horizontalValidSpawn(Vector2* validSpawn[MAX_VALIDSPAWN_HORIZ]);

private:
	Vector2* _horizontalValidSpawn[MAX_VALIDSPAWN_HORIZ];
};

#endif