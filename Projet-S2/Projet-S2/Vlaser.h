#ifndef VLASER_H
#define VLASER_H

#include <QMediaPlayer>
#include "obstacle.h"
#include "global.h"

class Vlaser : public Obstacle
{
public:
	Vlaser();
	~Vlaser();

	//virtuals
	void update();
	void playSpawnSound();

private:
	QMediaPlayer* _spawnSound;
};

#endif