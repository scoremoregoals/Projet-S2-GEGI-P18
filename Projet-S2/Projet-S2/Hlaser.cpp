#include "Hlaser.h"
#include <iostream>

Hlaser::Hlaser()
{}

Hlaser::Hlaser(int speed, int width, int height, int damage)
{
	set_type(hlaser);
	set_speed(speed);
	set_width(width);
	set_height(height);
	set_damage(damage);
}

Hlaser::~Hlaser()
{}

void Hlaser::update()
{
	setPos(x() + get_speed(), y() + get_speed());
}

