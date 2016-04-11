#include "runner.h"
#include <iostream>

Runner::Runner()
{
	_life = 100;
	_speed = 3;
	_width = 80;
	_height = 80;
	_isRunning = false;
	_usePowerUp = false;

	_animationLeft = new Animation(1000, 100, 10, "bb8-gauche.png");
	_animationRight = new Animation(1000, 100, 10, "bb8-droite.png");
	_currentAnimation = new Animation(1000, 100, 10, "bb8-droite.png");
	_frameTimer = new QTimer();
	_frameTimer->setInterval(FRAMETIME * 8);
	connect(_frameTimer, SIGNAL(timeout()), this, SLOT(nextFrame()));
	_frameTimer->start();
}

Runner::~Runner()
{}

void Runner::move(Direction direction)
{
	switch (direction)
	{
	case gauche:
		setPos(x() - _speed, y());
		_currentAnimation = _animationLeft;
		break;
	case droite:
		setPos(x() + _speed, y());
		_currentAnimation = _animationRight;
		break;
	case nulle :
		break;
	default:
		break;
	}
	if (x() >= scene()->width() - 200)
		setPos(scene()->width() - 200, y());
	if (x() <= 100)
		setPos(100, y());
}

void Runner::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Left)
	{
		LAST_PHONEME = 1;
	}
	else if (event->key() == Qt::Key_Right)
	{
		LAST_PHONEME = 2;
	}
	else if (event->key() == Qt::Key_Up)
	{
		usePowerUp();
	}
	else if (event->key() == Qt::Key_Escape)
	{
		if (_isRunning == true)
			_isRunning = false;
		else
			_isRunning = true;
	}
}

void Runner::usePowerUp()
{
	std::cout << "use power up" << std::endl;
	_usePowerUp = true;
}

void Runner::nextFrame()
{
	_currentAnimation->nextFrame();
	setPixmap(QPixmap(_currentAnimation->get_currentFrame()));
}

//setters
void Runner::set_usePowerup(bool use)
{
	_usePowerUp = use;
}

void Runner::set_life(int life)
{
	_life = life;
}

void Runner::set_isRunning(bool run)
{
	_isRunning = run;
}

