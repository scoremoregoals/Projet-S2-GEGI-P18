#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "global.h"

class Obstacle : public QGraphicsPixmapItem
{
public:
	/**
	 * @brief      Constructor
	 */
	Obstacle();
	/**
	 * @brief      Deconstructor
	 */
	virtual ~Obstacle();												 														 	

	//virtuals
	virtual void update() = 0; // est appelee a chaque frame, update la position, etc -> a implementer
	virtual void playSpawnSound() = 0 ;
	virtual void randomizeType() {}   //pour power ups

	/**
	 * @brief      Spawn an obstacle in horizontal
	 */
	virtual void spawnHorizontal();
	/**
	 * @brief      Spawn an obstacle in vertical
	 */
	void spawnVertical();
	
	//setters
	void set_speed(int speed);
	void set_width(int width);
	void set_height(int height);
	void set_damage(int damage);
	void set_lien(Obstacle* lien);
	void set_type(TypeObstacle type);
	
	//getters
	int get_speed() {return _speed;}
	int get_width() {return _width;}
	int get_height() {return _height;}
	int get_damage() {return _damage;}
	Obstacle* get_lien(){return _lien;}
	TypeObstacle get_type() {return _type;}
	virtual PowerUpType get_powerUpType() { return _powerType; }   //pour power ups
	
private:
	int _speed;
	int _width;
	int _height;
	int _damage;
	Obstacle* _lien;
	TypeObstacle _type;
	PowerUpType _powerType;
};

#endif //OBSTACLE_H
