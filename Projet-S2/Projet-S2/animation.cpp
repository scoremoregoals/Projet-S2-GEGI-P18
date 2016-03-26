#include "animation.h"

Animation::Animation()
{
}

Animation::Animation(int width, int height, int numFrames, int fps)
{
	_image = new QGraphicsPixmapItem();
	_currentFrame = 0;
	_frameWidth = width;
	_frameHeight = height;
	_numFrames = numFrames;

	_frameTimer = new QTimer();
	_frameTimer->setInterval(fps * 8);
	QObject::connect(_frameTimer, SIGNAL(timeout()), this, SLOT(nextFrame()));

	_spriteSheet.load(QString("spritesheet.png"));
	_frame = _spriteSheet.copy(_currentFrame * _frameWidth, 0, _frameWidth, _frameHeight);

	_frameTimer->start();
}

Animation::~Animation()
{
}

void Animation::nextFrame()
{
	_frame = _spriteSheet.copy(_currentFrame * _frameWidth, 0, _frameWidth, _frameHeight);
	_image->setPixmap(_frame);
	_currentFrame++;
	if (_currentFrame > _numFrames - 1)
		_currentFrame = 0;
}