#include "runner.h"
#include <iostream>

Runner::Runner()
{
	_life = 100;
	_speed = 3;
	_width = 100;
	_height = 100;
	_isRunning = false;
	_usePowerUp = false;
}

Runner::~Runner()
{}

void Runner::move(Direction direction)
{
	switch (direction)
	{
	case gauche:
		setPos(x() - _speed, y());
		break;
	case droite:
		setPos(x() + _speed, y());
		break;
	case nulle :
		break;
	default:
		break;
	}
	if (x() >= scene()->width() - _width - 4)
		setPos(scene()->width() - _width - 4, y());
	if (x() <= 0)
		setPos(0, y());
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

