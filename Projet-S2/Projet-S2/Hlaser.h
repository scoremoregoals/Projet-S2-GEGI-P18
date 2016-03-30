#ifndef HLASER_H
#define HLASER_H

#include <QMediaPlayer>
#include "obstacle.h"
#include "global.h"

class Hlaser : public Obstacle
{
public:
	Hlaser();
	~Hlaser();

	//virtuals
	void update();
	void playSpawnSound();

private:
	QMediaPlayer* _spawnSound;
};

#endif