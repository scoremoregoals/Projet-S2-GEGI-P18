#ifndef VLASER_H
#define VLASER_H

#include <qobject.h>
#include <QMediaPlayer>
#include <qtimer.h>
#include "obstacle.h"
#include "global.h"
#include "animation.h"

class Vlaser : public QObject, public Obstacle
{
	Q_OBJECT
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

private slots:
	void nextFrame();

private:
	QMediaPlayer* _spawnSound;
	Animation* _animation;
	QTimer* _frameTimer;
};

#endif