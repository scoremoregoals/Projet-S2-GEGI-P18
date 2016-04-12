#ifndef HLASER_H
#define HLASER_H

#include <qobject.h>
#include <qtimer.h>
#include <QMediaPlayer>
#include "Headers/obstacle.h"
#include "Headers/global.h"
#include "Headers/animation.h"

class Hlaser : public QObject, public Obstacle
{
	Q_OBJECT
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

	/**
	* @brief      Spawn the horizontal laser and chooses side
	*/
	void spawnHorizontal();

private slots:
	void nextFrame();

private:
	QMediaPlayer* _spawnSound;
	int _side;
	Animation* _animation;
	QTimer* _frameTimer;
};

#endif