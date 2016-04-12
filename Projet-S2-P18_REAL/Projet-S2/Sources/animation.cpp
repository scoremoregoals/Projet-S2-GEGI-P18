#include "Headers/animation.h"

Animation::Animation()
{
}

Animation::Animation(int width, int height, int numFrames, QString sheetPath)
{
	_image = new QGraphicsPixmapItem();
	_currentFrame = 0;
	_frameWidth = width / numFrames;
	_frameHeight = height;
	_numFrames = numFrames;
	_sheetPath = sheetPath;

	//charge la spritesheet
	_spriteSheet.load(_sheetPath);
	//la frame actuelle est chargee a partir de la spritesheet
	_frame = _spriteSheet.copy(_currentFrame * _frameWidth, 0, _frameWidth, _frameHeight);
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