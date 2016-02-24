#ifndef PLATFORM_H
#define PLATFORM_H

#include "obstacle.h"
#include "runner.h"
#include "vector2.h"
#include "liste.h"
#include "rectangle.h"

const int MAX_POSITIONS = 5; //A CHANGER SELON NBR CASES
const int MAX_OBSTACLES = 4; //CONTIENT LE NBR D'OBJETS DIFFERENTS DU JEU

class Platform
{
public:
	Platform();
	Platform( Runner & player, double obstacleBaseSpeed, Vector2* positions[MAX_POSITIONS], Liste& liste);     
	virtual ~Platform();
	
	void creerObstacle(Obstacle& obstacle);
	void ajouterAuJeu(Obstacle& obstacle);
	Direction checkPhoneme();
	void checkCollision();
	void moveObstacles();
	void movePlayer();
	
	void Update();    //est appelé a chaque frame, sert a updater les positions du joueur/obstacles et phonemes et collisions ,etc
	
	//setters
	void set_player(Runner & player);
	void set_obstacleBaseSpeed(double obstacleBaseSpeed);
	void set_positions(Vector2 positions[MAX_POSITIONS]);
	//liste
	
	//getters
	Runner* get_player() {return _player;}
	Vector2 get_position(int index) {return *_positions[index];}
	double get_obstacleBaseSpeed() {return _obstacleBaseSpeed;}
	Liste* get_listeObstacles(){return _listeObstacles;}
	Obstacle* get_obstacleByIndex(int index) {return _obstacles[index];}
	int get_nbrObstacles() {return _nbrObstacles;}

private:
	Liste*  _listeObstacles;			//liste d'obstacle actifs sur la plateforme
	Obstacle* _obstacles[MAX_OBSTACLES]; //tableau d'obstacles pouvant etre ajouter au jeu a n'importe quel moment
	int _nbrObstacles;
	Runner* _player;
	Vector2* _positions[MAX_POSITIONS];      //ajout du tableau de position
	double _obstacleBaseSpeed;
};

#endif //PLATFORM_H
