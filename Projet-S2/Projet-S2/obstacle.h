#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "vector2.h"
#include "global.h"

class Obstacle : public QGraphicsRectItem
{
public:
	Obstacle();
	virtual ~Obstacle();												 														 	

	//virtuals
	virtual void update() = 0; // est appelee a chaque frame, update la position, etc -> a implementer

	int spawnHorizontal();
	int spawnVertical();
	
	//setters
	void set_speed(int speed);
	void set_width(int width);
	void set_height(int height);
	void set_id(int id);
	void set_damage(int damage);
	void set_lien(Obstacle* lien);
	void set_type(TypeObstacle type);
	
	//getters
	int get_speed() {return _speed;}
	int get_width() {return _width;}
	int get_height() {return _height;}
	int get_id() {return _id;}
	int get_damage() {return _damage;}
	Obstacle* get_lien(){return _lien;}
	TypeObstacle get_type() {return _type;}
	
private:
	int _id;
	int _speed;
	int _width;
	int _height;
	int _damage;
	Obstacle* _lien;
	TypeObstacle _type;
};

#endif //OBSTACLE_H
