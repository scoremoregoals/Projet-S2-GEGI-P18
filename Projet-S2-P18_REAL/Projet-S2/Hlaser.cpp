#include "Hlaser.h"

Hlaser::Hlaser()
{
	set_type(hlaser);
	set_speed(LASER_BASE_SPEED);
	set_width(50);
	set_height(10);
	set_damage(10);

	//sounds
	_spawnSound = new QMediaPlayer();
	_spawnSound->setMedia(QUrl("laserSpawn.wav"));
}

Hlaser::~Hlaser()
{
	delete _spawnSound;
}

void Hlaser::update()
{
	setPos(x() + get_speed(), y() + get_speed());
}

void Hlaser::playSpawnSound()
{
	_spawnSound->play();
}

