#include "powerUp.h"

PowerUp::PowerUp()
{}

PowerUp::PowerUp(int speed, int width, int height, int damage)
{
	set_type(powerUp);
	set_speed(speed);
	set_width(width);
	set_height(height);
	set_damage(damage);
}

PowerUp::~PowerUp()
{}

void PowerUp::update()
{
	setPos(x(), y() + get_speed());
	if (y() > SCREEN_WIDTH)
	{
		scene()->removeItem(this);
		delete this;
	}
}
