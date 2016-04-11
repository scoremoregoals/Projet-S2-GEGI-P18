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

	_animation = new Animation(500, 10, 10, "HlaserSpriteSheet.png");
	_frameTimer = new QTimer();
	_frameTimer->setInterval(FRAMETIME * 8);
	connect(_frameTimer, SIGNAL(timeout()), this, SLOT(nextFrame()));
	_frameTimer->start();
}

Hlaser::~Hlaser()
{
	delete _spawnSound;
	delete _animation;
	delete _frameTimer;
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

void Hlaser::nextFrame()
{
	_animation->nextFrame();
	setPixmap(QPixmap(_animation->get_currentFrame()));
}

