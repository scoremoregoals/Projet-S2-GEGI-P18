#ifndef PLATFORM_H
#define PLATFORM_H

#include "obstacle.h"
#include "runner.h"
#include "vector2.h"
#include "rectangle.h"
#include <list>

using namespace std;

const int MAX_OBSTACLES = 4; //CONTIENT LE NBR D'OBJETS DIFFERENTS DU JEU

class Platform
{
public:
	Platform();
	Platform( Runner & player, list<Obstacle*> liste);     
	virtual ~Platform();
	
	void creerObstacle(Obstacle* obstacle);
	void ajouterAuJeu(int position);
	void effacerObstacle(Obstacle* obstacle);
	Direction checkPhoneme(int input);
	void checkCollision();
	void moveObstacles();
	void movePlayer();
	
	void Update(int input);    //est appelé a chaque frame, sert a updater les positions du joueur/obstacles et phonemes et collisions ,etc
	
	//setters
	void set_player(Runner & player);
	//liste
	
	//getters
	Runner* get_player() {return _player;}
	list<Obstacle*> get_listeObstacles(){return _listeObstacles;}
	Obstacle* get_obstacleByIndex(int index) {return _obstacles[index];}
	int get_nbrObstacles() {return _nbrObstacles;}

private:
	list<Obstacle*>  _listeObstacles;			//liste d'obstacle actifs sur la plateforme
	Obstacle* _obstacles[MAX_OBSTACLES]; //tableau d'obstacles pouvant etre ajouter au jeu a n'importe quel moment
	int _nbrObstacles; //nombre d'obstacles "moules" dans le tableau d'obstacles
	Runner* _player;    //ajout du tableau de position
};

#endif //PLATFORM_H
