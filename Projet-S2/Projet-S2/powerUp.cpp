#include "powerUp.h"

PowerUp::PowerUp()
{
	set_type(powerUp);
	set_speed(10);
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

