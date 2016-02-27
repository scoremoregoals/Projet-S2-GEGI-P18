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

Vlaser::Vlaser(int speed, int width, int height, int damage, Vector2* verticalValidSpawn[MAX_VALIDSPAWN_VERT])
{
	set_type(vlaser);
	set_speed(speed);
	set_width(width);
	set_height(height);
	set_damage(damage);

	for (int i = 0; i < MAX_VALIDSPAWN_VERT; i++)
	{
		_verticalValidSpawn[i] = verticalValidSpawn[i];
	}
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

void Vlaser::spawnVertical()            // choisi une position random a partir de validSpawn et l'assigne a la position de l'obstacle
{
	int random = rand() % MAX_VALIDSPAWN_VERT;
	set_position(_verticalValidSpawn[random]);
}

void Vlaser::spawnHorizontal()
{}

void Vlaser::set_verticalValidSpawn(Vector2* verticalValidSpawn[MAX_VALIDSPAWN_VERT])
{
	for (int i = 0; i < MAX_VALIDSPAWN_VERT; i++)
	{
		_verticalValidSpawn[i] = verticalValidSpawn[i];
	}
}