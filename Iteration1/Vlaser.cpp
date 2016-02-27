#include "Vlaser.h"
#include <iostream>

Vlaser::Vlaser()
{
	set_type(vlaser);
	set_speed(0);
	set_width(0);
	set_height(0);
	set_damage(0);
	set_lien(NULL);
}

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

void Vlaser::Update()
{
	get_position()->set_positionY(get_position()->get_positionY() + get_speed());
}

void Vlaser::draw()
{}

void Vlaser::afficherDetails() //a modif pour ajouter dautres trucs a afficher
{
	std::cout << "new position type vlaser id : " << get_id() << " : x = " << get_position()->get_positionX() << " y = "
		<< get_position()->get_positionY() << std::endl;
}
