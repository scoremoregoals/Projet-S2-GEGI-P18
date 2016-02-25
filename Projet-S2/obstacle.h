#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "vector2.h"

const int MAX_VALIDSPAWN = 3; //A CHANGER SELON NBR colonnes

enum TypeObstacle   //sert pour savoir avec quoi le joueur collisionne, s'assigne lors de la construction de l'obstacle
{
	laser,
	power  //etc..
};

class Obstacle
{
public:
	Obstacle();
    Obstacle(int speed, int width, int height, int id, int damage, Vector2* validSpawn[MAX_VALIDSPAWN]); //va etre retirer lorsque les obstacles specifiques
	virtual ~Obstacle();												 			//vont etre implementer												 	
	
	void spawn();           // choisi une position random a partir de validSpawn
	virtual void draw() = 0;
	void move();
	
	virtual void Update() = 0; // est appelee a chaque frame, update la position, etc -> a implementer
	
	//setters
	void set_position(Vector2* position);
	void set_speed(int speed);
	void set_width(int width);
	void set_height(int height);
	void set_ID(int id);
	void set_damage(int damage);
	void set_validSpawn(Vector2* validSpawn[MAX_VALIDSPAWN]);
	void set_lien(Obstacle* lien);
	void set_type(TypeObstacle type);
	//void set_sprite();
	
	//getters
	Vector2* get_position() {return _position;}
	int get_speed() {return _speed;}
	int get_width() {return _width;}
	int get_height() {return _height;}
	int get_ID() {return _id;}
	int get_damage() {return _damage;}
	Obstacle* get_lien(){return _lien;}
	TypeObstacle get_type() {return _type;}
	
private:
	Vector2* _position;
	Vector2* _validSpawn[MAX_VALIDSPAWN]; 
	int _id;
	int _speed;
	int _width;
	int _height;
	//Sprite _sprite;
	int _damage;
	Obstacle* _lien;
	TypeObstacle _type;
};

#endif //OBSTACLE_H
