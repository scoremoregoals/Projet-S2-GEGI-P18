#ifndef ANIMATION_H
#define ANIMATION_H

#include <QGraphicsPixmapItem>
#include <qimage.h>

class Animation
{
public:
	/**
	 * @brief Unused constructor
	 * @details Nothing happen here
	 */
	Animation();

	/**
	 * @brief      Load the spritesheet with the correct form
	 *
	 * @param[in]  width      Size in width of the sprites
	 * @param[in]  height     Size in height of the sprites
	 * @param[in]  numFrames  Number of frame of the sprites
	 * @param[in]  fps        Number of frame per seconds
	 * @param[in]  sheetPath  Directory of the containing sprites
	 */
	Animation(int width, int height, int numFrames, QString sheetPath);

	/**
	 * @brief      Deconstructor
	 */
	~Animation();

	/**
	 * @brief      Connect to get_frame, for loading the next frame
	 *
	 * @return     The image of the sprite
	 */
	QGraphicsPixmapItem* get_frame() { return _image; }
	QPixmap get_currentFrame() { return _frame; }

	/**
	 * @brief      Load the next frame
	 */
	void nextFrame();

private:
	QPixmap _spriteSheet;
	QPixmap _frame;
	QGraphicsPixmapItem* _image;
	QString _sheetPath;
	int _numFrames;
	int _currentFrame;
	int _frameWidth;
	int _frameHeight;
};

#endif //ANIMATION_H