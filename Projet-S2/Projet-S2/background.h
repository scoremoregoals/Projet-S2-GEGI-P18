#include <qbrush.h>
#include <QGraphicsPixmapItem>
#include "global.h"

class BackGround
{
public:
	BackGround();
	BackGround(QString backgroundPath);
	~BackGround();

	void move();
	QGraphicsPixmapItem* get_background1() { return _background1; }
	QGraphicsPixmapItem* get_background2() { return _background2; }

private:
	QGraphicsPixmapItem* _background1;
	QGraphicsPixmapItem* _background2;
	QPoint _positions[2];
	int _speed;
};
