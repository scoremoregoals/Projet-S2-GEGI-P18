#include "Vlaser.h"

Vlaser::Vlaser()
{}

Vlaser::Vlaser(int speed, int width, int height, int damage)
{
	set_type(vlaser);
	set_speed(speed);
	set_width(width);
	set_height(height);
	set_damage(damage);
}

Vlaser::~Vlaser()
{}

void Vlaser::update()
{
	setPos(x(), y() + get_speed());
	if (y() > SCREEN_WIDTH)
	{
		scene()->removeItem(this);
		delete this;
	}
}

