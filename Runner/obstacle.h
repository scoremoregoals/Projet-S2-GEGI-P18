#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "vector2.h"

enum ID
{};

class Obstacle
{
public:
	Obstacle();
	Obstacle(Vector2 position, double speed, int width, int height,
		ID id, int damage); //ajout de sprite et validSpawn[]
	~Obstacle();
	
	//setters
	void set_position(Vector2 position);
	void set_speed(double speed);
	void set_width(int width);
	void set_height(int height);
	void set_ID(ID id);
	void set_damage(int damage);
	//set_validSpawn
	//void set_sprite();
	
	//getters
	Vector2 get_position() {return _position;}
	double get_speed() {return _speed;}
	int get_width() {return _width;}
	int get_height() {return _height;}
	ID get_id() {return _id;}
	int get_damage() {return _damage;}
	//get_validSpawn()
	
private:
	Vector2 _position;
	//ajout validSpawn
	ID _id;
	double _speed;
	int _width;
	int _height;
	//Sprite _sprite;
	int _damage;
};

#endif //OBSTACLE_H
