#ifndef VLASER_H
#define VLASER_H

#include "obstacle.h"

class Vlaser : public Obstacle
{
public:
	Vlaser();
	Vlaser(int speed, int width, int height, int damage, Vector2* verticalValidSpawn[MAX_VALIDSPAWN_VERT]);
	~Vlaser();

	//virtuals
	void Update();
	void draw();
	void afficherDetails();
	void move();

	void spawnVertical();           // choisi une position random a partir de validSpawn
	virtual void spawnHorizontal();
	void set_verticalValidSpawn(Vector2* validSpawn[MAX_VALIDSPAWN_VERT]);

private:
	Vector2* _verticalValidSpawn[MAX_VALIDSPAWN_VERT];
};

#endif