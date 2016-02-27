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

Hlaser::Hlaser(int speed, int width, int height, int damage, Vector2* horizontalValidSpawn[MAX_VALIDSPAWN_HORIZ])
{
	set_type(hlaser);
	set_speed(speed);
	set_width(width);
	set_height(height);
	set_damage(damage);

	for (int i = 0; i < MAX_VALIDSPAWN_VERT; i++)
	{
		_horizontalValidSpawn[i] = horizontalValidSpawn[i];
	}
}

Hlaser::~Hlaser()
{}

void Hlaser::Update()
{
	get_position()->set_positionX(get_position()->get_positionX() + get_speed());
}

void Hlaser::draw()
{}

void Hlaser::afficherDetails() //a modif pour ajouter dautres trucs a afficher
{
	std::cout << "new position type hlaser id : " << get_id() << " : x = " << get_position()->get_positionX() << " y = "
		<< get_position()->get_positionY() << std::endl;
}

void Hlaser::spawnHorizontal()            // choisi une position random a partir de validSpawn et l'assigne a la position de l'obstacle
{
	int random = rand() % MAX_VALIDSPAWN_HORIZ;
	set_position(_horizontalValidSpawn[random]);
}

void Hlaser::spawnVertical()          
{}

void Hlaser::set_horizontalValidSpawn(Vector2* horizontalValidSpawn[MAX_VALIDSPAWN_HORIZ])
{
	for (int i = 0; i < MAX_VALIDSPAWN_HORIZ; i++)
	{
		_horizontalValidSpawn[i] = horizontalValidSpawn[i];
	}
}