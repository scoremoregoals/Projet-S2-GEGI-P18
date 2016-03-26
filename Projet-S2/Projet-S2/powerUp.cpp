#include "powerUp.h"
#include <iostream>

PowerUp::PowerUp()
{
	set_type(powerUp);
	set_speed(5);
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
		setPixmap(QPixmap("powerupSlow.png"));
		break;
	case 1:
		_powerUpType = Destroy;
		setPixmap(QPixmap("powerupDestroy.png"));
		break;
	default:
		break;
	}
}

void PowerUp::set_powerUptype(PowerUpType type)
{
	_powerUpType = type;
}


