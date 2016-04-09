#include "Vlaser.h"

Vlaser::Vlaser()
{
	set_type(vlaser);
	set_speed(LASER_BASE_SPEED);
	set_width(10);
	set_height(50);
	set_damage(10);

	//sounds
	_spawnSound = new QMediaPlayer();
	_spawnSound->setVolume(20);
	_spawnSound->setMedia(QUrl("laserSpawn.wav"));
}

Vlaser::~Vlaser()
{
	delete _spawnSound;
}

void Vlaser::update()
{
	setPos(x(), y() + get_speed());
}

void Vlaser::playSpawnSound()
{
	_spawnSound->play();
}
