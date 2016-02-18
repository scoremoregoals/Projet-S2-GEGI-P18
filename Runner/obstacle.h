#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "vector2.h"

const int MAX_VALIDSPAWN = 3; //A CHANGER SELON NBR colonnes

class Obstacle
{
public:
	Obstacle();
	Obstacle(Obstacle* lien);
    Obstacle(double speed, int width, int height, int id, int damage, Vector2* validSpawn[MAX_VALIDSPAWN]); 
	~Obstacle();																										 	
	
	void spawn();           // choisi une position random a partir de validSpawn
	
	//setters
	void set_position(Vector2* position);
	void set_speed(double speed);
	void set_width(int width);
	void set_height(int height);
	void set_ID(int id);
	void set_damage(int damage);
	void set_validSpawn(Vector2* validSpawn[MAX_VALIDSPAWN]);
	void set_lien(Obstacle* lien);
	//void set_sprite();
	
	//getters
	Vector2* get_position() {return _position;}
	double get_speed() {return _speed;}
	int get_width() {return _width;}
	int get_height() {return _height;}
	int get_ID() {return _id;}
	int get_damage() {return _damage;}
	Obstacle* get_lien(){return _lien;}
	
private:
	Vector2* _position;
	Vector2* _validSpawn[MAX_VALIDSPAWN]; 
	int _id;
	double _speed;
	int _width;
	int _height;
	//Sprite _sprite;
	int _damage;
	Obstacle* _lien;
};

#endif //OBSTACLE_H
