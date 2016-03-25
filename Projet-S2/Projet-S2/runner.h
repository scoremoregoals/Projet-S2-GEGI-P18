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
	Runner();
	Runner(int life, int speed, int width, int height);
	virtual ~Runner();

	void keyPressEvent(QKeyEvent *event);
	void move(Direction direction);
	
	//setters
	void set_life(int life);
	void set_speed(int speed);
	void set_width(int width);
	void set_height(int height);
	void set_isRunning(bool run);
	
	//getters
	int get_life() {return _life;}
	int get_speed() {return _speed;}
	int get_width() {return _width;}
	int get_height() {return _height;}
	bool get_isRunning() { return _isRunning; }
	
private:
	int _width;
	int _height;
	int _life;
	int _speed;
	bool _isRunning;
};


#endif //RUNNER_H
