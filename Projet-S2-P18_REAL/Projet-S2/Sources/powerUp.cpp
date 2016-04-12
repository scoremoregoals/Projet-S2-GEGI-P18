#include "Headers/powerUp.h"

PowerUp::PowerUp()
{
	set_type(powerUp);
	set_speed(POWERUP_BASE_SPEED);
	set_width(50);
	set_height(50);
	set_damage(0);
}

PowerUp::PowerUp(Obstacle* copy)
{
	this->set_powerUptype(copy->get_powerUpType());
	this->setPixmap(copy->pixmap());
	set_type(powerUp);
	set_speed(5);
	set_width(50);
	set_height(50);
	set_damage(0);
}

PowerUp::~PowerUp()
{	
	delete _animation;
	delete _frameTimer;
}

void PowerUp::update()
{
	setPos(x(), y() + get_speed());
}

void PowerUp::randomizeType()
{
	int random = rand() % 2;
	switch (random)
	{
	case 0: 
		_powerUpType = Slow;
		_animation = new Animation(3000, 50, 60,"spritesheets/SlowDownSpriteSheet.png");
		_frameTimer = new QTimer();
		_frameTimer->setInterval(FRAMETIME * 8);
		connect(_frameTimer, SIGNAL(timeout()), this, SLOT(nextFrame()));
		_frameTimer->start();
		break;
	case 1:
		_powerUpType = Destroy;
		_animation = new Animation(600, 50, 12, "spritesheets/bombSpriteSheet.png");
		_frameTimer = new QTimer();
		_frameTimer->setInterval(FRAMETIME * 8);
		connect(_frameTimer, SIGNAL(timeout()), this, SLOT(nextFrame()));
		_frameTimer->start();
		break;
	default:
		break;
	}
}

void PowerUp::set_powerUptype(PowerUpType type)
{
	_powerUpType = type;
}

void PowerUp::nextFrame()
{
	_animation->nextFrame();
	setPixmap(QPixmap(_animation->get_currentFrame()));
}


