#include "runner.h"


Runner::Runner()
{
	_life = 0;
	_speed = 0;
	_width = 0;
	_height = 0;
	_isRunning = false;
}

Runner::~Runner()
{}

Runner::Runner(int life, int speed, int width, int height) //ajout sprite
{
	_life = life;
	_speed = speed;
	_width = width;
	_height = height;
	_isRunning = false;
}

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
	if (x() >= scene()->width() - rect().width() - 4)
		setPos(scene()->width() - rect().width() - 4, y());
	if (x() <= 0)
		setPos(0, y());
}

void Runner::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Left)
	{
		setPos(x() - 10, y());
		LAST_PHONEME = 1;
	}
	else if (event->key() == Qt::Key_Right)
	{
		setPos(x() + 10, y());
		LAST_PHONEME = 2;
	}
	else if (event->key() == Qt::Key_Escape)
	{
		if (_isRunning == true)
			_isRunning = false;
		else
			_isRunning = true;
	}
}

//setters
void Runner::set_life(int life)
{
	_life = life;
}

void Runner::set_speed(int speed)
{
	_speed = speed;
}

void Runner::set_width(int width)
{
	_width = width;
}

void Runner::set_height(int height)
{
	_height = height;	
}

void Runner::set_isRunning(bool run)
{
	_isRunning = run;
}

