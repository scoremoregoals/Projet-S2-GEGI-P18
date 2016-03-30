#ifndef VLASER_H
#define VLASER_H

#include <QMediaPlayer>
#include "obstacle.h"
#include "global.h"

class Vlaser : public Obstacle
{
public:
	/**
	 * @brief      Create a Vertical laser with default settings
	 */
	Vlaser();

	/**
	 * @brief      Deconstructor
	 */
	~Vlaser();

	//virtuals
	void update();
	void playSpawnSound();

private:
	QMediaPlayer* _spawnSound;
};

#endif