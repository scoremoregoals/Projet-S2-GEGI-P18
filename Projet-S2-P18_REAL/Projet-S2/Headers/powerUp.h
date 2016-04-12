#ifndef POWERUP_H
#define POWERUP_H

#include <qobject.h>
#include <qtimer.h>
#include <QMediaPlayer>
#include "Headers/obstacle.h"
#include "Headers/global.h"
#include "Headers/animation.h"

class PowerUp : public QObject, public Obstacle
{
	Q_OBJECT
public:
	/**
	 * @brief      Create a powerup object and set speed, width, height and damage
	 */
	PowerUp();
	/**
	 * @brief      Copy the current power up obstacle
	 *
	 * @param      copy  Obstacle 
	 */
	PowerUp(Obstacle* copy);
	/**
	 * @brief      Deconstructor
	 */
	~PowerUp();

	/**
	 * @brief      Choose a randow type of power ups
	 */
	void randomizeType();

	//virtuals
	void update();
	void playSpawnSound() {};

	/**
	 * @brief      Get the current type of power up
	 *
	 * @return     Retrun the type of power up
	 */
	PowerUpType get_powerUpType() { return _powerUpType; }
	/**
	 * @brief      Set a type of power up
	 *
	 * @param[in]  type  Type of the power up
	 */
	void set_powerUptype(PowerUpType type);

private slots:
	void nextFrame();

private:
	PowerUpType _powerUpType;
	Animation* _animation;
	QTimer* _frameTimer;
};

#endif