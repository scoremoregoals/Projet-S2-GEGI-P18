#include "Headers/Vlaser.h"

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
	_spawnSound->setMedia(QUrl("sounds/laserSpawn.wav"));

	_animation = new Animation(70, 50, 7, "spritesheets/VlaserSpriteSheet.png");
	_frameTimer = new QTimer();
	_frameTimer->setInterval(FRAMETIME * 8);
	connect(_frameTimer, SIGNAL(timeout()), this, SLOT(nextFrame()));
	_frameTimer->start();
}

Vlaser::~Vlaser()
{
	delete _spawnSound;
	delete _animation;
	delete _frameTimer;
}

void Vlaser::update()
{
	setPos(x(), y() + get_speed());
}

void Vlaser::playSpawnSound()
{
	_spawnSound->play();
}

void Vlaser::nextFrame()
{
	_animation->nextFrame();
	setPixmap(QPixmap(_animation->get_currentFrame()));
}


