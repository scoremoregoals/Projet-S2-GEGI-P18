#include "powerUp.h"

PowerUp::PowerUp()
{
	set_type(powerUp);
	set_speed(0);
	set_width(0);
	set_height(0);
	set_damage(0);
	set_lien(NULL);
}

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

void PowerUp::Update()
{
	get_position()->set_positionY(get_position()->get_positionY() + get_speed());
}

void PowerUp::draw()
{}

void PowerUp::afficherDetails() //a modif pour ajouter dautres trucs a afficher
{
	std::cout << "new position type powerUp id : " << get_id() << " : x = " << get_position()->get_positionX() << " y = "
		<< get_position()->get_positionY() << std::endl;
}