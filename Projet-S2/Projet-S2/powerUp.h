#ifndef POWERUP_H
#define POWERUP_H

#include <QMediaPlayer>
#include "obstacle.h"
#include "global.h"

class PowerUp : public Obstacle
{
public:
	PowerUp();
	~PowerUp();

	//virtuals
	void update();
	void playSpawnSound() {};
};

#endif