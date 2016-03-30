#ifndef HLASER_H
#define HLASER_H

#include <QMediaPlayer>
#include "obstacle.h"
#include "global.h"

class Hlaser : public Obstacle
{
public:
	/**
	 * @brief      Create a Hlaser object with those parameters, laser speed slow,
	 * width of the laser == 50
	 * height of the laser == 10
	 * Damage that laser makes == 10
	 */
	Hlaser();

	/**
	 * @brief      Deconstructor
	 */
	~Hlaser();

	//virtuals
	
	/**
	 * @brief      Update the current speed and position
	 */
	void update();

	/**
	 * @brief      Play a spawn sound when spawning the object on the screen
	 */
	void playSpawnSound();

private:
	QMediaPlayer* _spawnSound;
};

#endif