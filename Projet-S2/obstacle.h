#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "vector2.h"

const int SCREEN_WIDTH = 100;   //dimensions de la fenetre de jeu pour les spawns
const int SCREEN_HEIGHT = 100;

enum TypeObstacle   //sert pour savoir avec quoi le joueur collisionne, s'assigne lors de la construction de l'obstacle
{
	hlaser,
	vlaser,
	powerUp  //etc..
};

class Obstacle
{
public:
	Obstacle();
	virtual ~Obstacle();												 														 	

	//virtuals
	virtual void draw() = 0;
	virtual void afficherDetails() = 0;
	virtual void Update() = 0; // est appelee a chaque frame, update la position, etc -> a implementer

	void spawnHorizontal();
	void spawnVertical();
	
	//setters
	void set_position(Vector2* position);
	void set_speed(int speed);
	void set_width(int width);
	void set_height(int height);
	void set_id(int id);
	void set_damage(int damage);
	void set_lien(Obstacle* lien);
	void set_type(TypeObstacle type);
	//void set_sprite();
	
	//getters
	Vector2* get_position() {return _position;}
	int get_speed() {return _speed;}
	int get_width() {return _width;}
	int get_height() {return _height;}
	int get_id() {return _id;}
	int get_damage() {return _damage;}
	Obstacle* get_lien(){return _lien;}
	TypeObstacle get_type() {return _type;}
	
private:
	Vector2* _position; 
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
