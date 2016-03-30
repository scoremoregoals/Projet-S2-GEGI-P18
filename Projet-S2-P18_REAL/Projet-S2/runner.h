#ifndef RUNNER_H
#define RUNNER_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "global.h"

class Runner : public QGraphicsPixmapItem
{
public:
	/**
	 * @brief      Constructor, set the default runner settings
	 */
	Runner();
	/**
	 * @brief      Set runner with other settings
	 *
	 * @param[in]  life    Life of the runner
	 * @param[in]  speed   Set the speed of the runner
	 * @param[in]  width   Set the fatness of the runner
	 * @param[in]  height  Set the height of the runner
	 */
	Runner(int life, int speed, int width, int height);
	/**
	 * @brief      Deconstructor
	 */
	virtual ~Runner();

	/**
	 * @brief      Event of a global KeyPress
	 *
	 * @param      event  Event (the key received)
	 */
	void keyPressEvent(QKeyEvent *event);
	/**
	 * @brief      Move the runner on the platform
	 *
	 * @param[in]  direction  Move the runner and received the direction of an input (FPGA OR KEYS)
	 */
	void move(Direction direction);
	/**
	 * @brief      True or false if we want to use power ups
	 */
	void usePowerUp();
	
	//setters
	void set_life(int life);
	void set_isRunning(bool run);
	void set_usePowerup(bool use);
	
	//getters
	int get_life() {return _life;}
	int get_width() {return _width;}
	int get_height() {return _height;}
	bool get_isRunning() { return _isRunning; }
	bool get_usePowerup() { return _usePowerUp; }
	
private:
	int _width;
	int _height;
	int _life;
	int _speed;
	bool _isRunning;
	bool _usePowerUp;
};


#endif //RUNNER_H
