#include "powerUp.h"
#include <iostream>

PowerUp::PowerUp()
{
	set_type(powerUp);
	set_speed(POWERUP_BASE_SPEED);
	set_width(50);
	set_height(50);
	set_damage(0);
}

PowerUp::PowerUp(Obstacle* copy)
{
	this->set_powerUptype(copy->get_powerUpType());
	this->setPixmap(copy->pixmap());
	set_type(powerUp);
	set_speed(5);
	set_width(50);
	set_height(50);
	set_damage(0);
}

PowerUp::~PowerUp()
{	
}

void PowerUp::update()
{
	setPos(x(), y() + get_speed());
}

void PowerUp::randomizeType()
{
	int random = rand() % 2;
	switch (random)
	{
	case 0: 
		_powerUpType = Slow;
		_animation = new Animation(3000, 50, 60,"SlowDownSpriteSheet.png");
		_frameTimer = new QTimer();
		_frameTimer->setInterval(FRAMETIME * 8);
		connect(_frameTimer, SIGNAL(timeout()), this, SLOT(nextFrame()));
		_frameTimer->start();
		break;
	case 1:
		_powerUpType = Destroy;
		setPixmap(QPixmap("powerupDestroy.png"));
		/*_animation = new Animation(100, 50, 10, FRAMETIME, "VlaserSpriteSheet.png");
		_frameTimer = new QTimer();
		_frameTimer->setInterval(FRAMETIME * 8);
		connect(_frameTimer, SIGNAL(timeout()), this, SLOT(nextFrame()));
		_frameTimer->start();*/
		break;
	default:
		break;
	}
}

void PowerUp::set_powerUptype(PowerUpType type)
{
	_powerUpType = type;
}

void PowerUp::nextFrame()
{
	_animation->nextFrame();
	setPixmap(QPixmap(_animation->get_currentFrame()));
}


