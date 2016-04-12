#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <qobject.h>
#include <QGraphicsPixmapItem>
#include <qtimer.h>
#include "Headers/animation.h"
#include "Headers/global.h"

class Explosion : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	Explosion();
	~Explosion();

private slots:
	void nextFrame();

private:
	Animation* _animation;
	QTimer* _frameTimer;
	int frameCount;
};

#endif //EXPLOSION_H