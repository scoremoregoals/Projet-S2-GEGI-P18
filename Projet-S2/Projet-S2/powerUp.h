#ifndef POWERUP_H
#define POWERUP_H

#include <QMediaPlayer>
#include "obstacle.h"
#include "global.h"

class PowerUp : public Obstacle
{
public:
	PowerUp();
	PowerUp(Obstacle* copy);
	~PowerUp();

	void randomizeType();

	//virtuals
	void update();
	void playSpawnSound() {};

	PowerUpType get_powerUpType() { return _powerUpType; }
	void set_powerUptype(PowerUpType type);
private:
	PowerUpType _powerUpType;
};

#endif