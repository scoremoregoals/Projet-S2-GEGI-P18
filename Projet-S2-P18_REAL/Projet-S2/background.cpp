#include "background.h"

BackGround::BackGround(){}

BackGround::BackGround(QString backgroundPath)
{
	_positions[0] = QPoint(0, 0 - SCREEN_HEIGHT);
	_positions[1] = QPoint(0, 0);

	_background1 = new QGraphicsPixmapItem();
	_background1->setPixmap(QPixmap(backgroundPath));
	_background1->setPos(_positions[0]);

	_background2 = new QGraphicsPixmapItem();
	_background2->setPixmap(QPixmap(backgroundPath));
	_background2->setPos(_positions[1]);

	_speed = 1;
}

BackGround::~BackGround()
{
}

void BackGround::move()
{
	QGraphicsPixmapItem* backgrounds[2];
	backgrounds[0] = _background1;
	backgrounds[1] = _background2;
	for (int i = 0; i < 2; i++)
	{
		backgrounds[i]->setPos(0, backgrounds[i]->y() + _speed);
		if (backgrounds[i]->y() > SCREEN_HEIGHT)
		{
			backgrounds[i]->setPos(_positions[0]);
		}
	}
}