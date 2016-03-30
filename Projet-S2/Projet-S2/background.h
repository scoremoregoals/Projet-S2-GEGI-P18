#include <qbrush.h>
#include <QGraphicsPixmapItem>
#include "global.h"

class BackGround
{
public:
	/**
	 * @brief      Unused constructor
	 */
	BackGround();
	/**
	 * @brief      Load a backgroud image
	 *
	 * @param[in]  backgroundPath  Directory and image name for the background
	 */
	BackGround(QString backgroundPath);
	/**
	 * @brief      Deconstructor
	 */
	~BackGround();

	/**
	 * @brief      Move background to make a more realistic and fun visual
	 */
	void move();

	/**
	 * @brief      Get the current background (unused get)
	 *
	 * @return     The image of the background1
	 */
	QGraphicsPixmapItem* get_background1() { return _background1; }

	/**
	 * @brief      Get the current background (unused)
	 *
	 * @return     The image of the background2
	 */
	QGraphicsPixmapItem* get_background2() { return _background2; }

private:
	QGraphicsPixmapItem* _background1;
	QGraphicsPixmapItem* _background2;
	QPoint _positions[2];
	int _speed;
};
