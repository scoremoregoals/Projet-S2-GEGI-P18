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
	_spawnSound->setVolume(20);
	_spawnSound->setMedia(QUrl("laserSpawn.wav"));
}

Hlaser::~Hlaser()
{
	delete _spawnSound;
}

void Hlaser::update()
{
	switch (_side)
	{
	case 0 :   //moves right
		setPos(x() + get_speed(), y() + get_speed());
		break;
	case 1 :   //moves left
		setPos(x() - get_speed(), y() + get_speed());
		break;
	default:
		break;
	}
}

void Hlaser::spawnHorizontal()
{
	_side = rand() % 2;
	int height = rand() % (SCREEN_HEIGHT - 100);
	switch (_side)
	{
	case 0: //LEFT
		break;
	case 1: //RIGHT
		setPos(SCREEN_WIDTH, height);
		break;
	default:
		setPos(0 - get_width(), height);
		break;
	}
}

void Hlaser::playSpawnSound()
{
	_spawnSound->play();
}

