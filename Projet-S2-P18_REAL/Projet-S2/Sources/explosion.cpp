#include "Headers/explosion.h"

Explosion::Explosion()
{
	frameCount = 0;
	_animation = new Animation(215, 15, 12, "spritesheets/explosion.png");
	setPixmap(_animation->get_currentFrame());
	_frameTimer = new QTimer();
	_frameTimer->setInterval(FRAMETIME);
	connect(_frameTimer, SIGNAL(timeout()), this, SLOT(nextFrame()));
	_frameTimer->start();
}

Explosion::~Explosion()
{
	delete _animation;
	delete _frameTimer;
}

void Explosion::nextFrame()
{
	_animation->nextFrame();
	setPixmap(QPixmap(_animation->get_currentFrame()));
	frameCount++;
	if (frameCount >= 11)
		delete this;
}