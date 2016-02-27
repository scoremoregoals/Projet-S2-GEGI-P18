#include "Hlaser.h"
#include <iostream>

Hlaser::Hlaser()
{
	set_type(hlaser);
	set_speed(0);
	set_width(0);
	set_height(0);
	set_damage(0);
	set_lien(NULL);
}

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

void Hlaser::Update()
{
	get_position()->set_positionX(get_position()->get_positionX() + get_speed());
}

void Hlaser::draw()
{}

void Hlaser::afficherDetails()
{
	std::cout << "new position type hlaser id : " << get_id() << " : x = " << get_position()->get_positionX() << " y = "
		<< get_position()->get_positionY() << std::endl;
}
