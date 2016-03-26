#ifndef ANIMATION_H
#define ANIMATION_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>
#include <qimage.h>

class Animation : public QObject
{
	Q_OBJECT
public:
	Animation();
	Animation(int width, int height, int numFrames, int fps);
	~Animation();

	QGraphicsPixmapItem* get_frame() { return _image; }

public slots:
	void nextFrame();

private:
	QPixmap _spriteSheet;
	QPixmap _frame;
	QTimer* _frameTimer;
	QGraphicsPixmapItem* _image;
	int _numFrames;
	int _currentFrame;
	int _frameWidth;
	int _frameHeight;
};

#endif //ANIMATION_H