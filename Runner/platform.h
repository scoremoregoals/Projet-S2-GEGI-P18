#ifndef PLATFORM_H
#define PLATFORM_H

#include "obstacle.h"
#include "runner.h"
#include "vector2.h"
#include "liste.h"

const int MAX_POSITIONS = 20; //A CHANGER SELON NBR CASES

class Platform
{
public:
	Platform();
	Platform( Runner & player, double obstacleBaseSpeed, Vector2 positions[MAX_POSITIONS], Liste& listeObstacle);     
	~Platform();
	
	void checkPhoneme();
	void checkCollision();
	void moveObstacles();
	void moveCar();
	
	//setters
	void set_player(Runner & player);
	void set_obstacleBaseSpeed(double obstacleBaseSpeed);
	void set_positions(Vector2 positions[MAX_POSITIONS]);
	//liste
	
	//getters
	Runner* get_player() {return _player;}
	Vector2 get_position(int index) {return *_positions[index];}
	double get_obstacleBaseSpeed() {return _obstacleBaseSpeed;}
	Liste* get_listeObstacle(){return _listeObstacles;}

private:
	Liste*  _listeObstacles;	
	Runner* _player;
	Vector2* _positions[MAX_POSITIONS];      //ajout du tableau de position
	double _obstacleBaseSpeed;
};

#endif //PLATFORM_H
