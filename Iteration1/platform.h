#ifndef PLATFORM_H
#define PLATFORM_H

#include "obstacle.h"
#include "runner.h"
#include "vector2.h"
#include "rectangle.h"
#include <list>
#include "liste.h"
#include "id.h"
#include "Hlaser.h"
#include "Vlaser.h"
#include "powerUp.h"

using namespace std;

const int MAX_OBSTACLES_ACTIFS = 6;

class Platform
{
public:
	Platform();
	Platform(Runner & player, Liste& liste, ObstacleID* id[MAX_OBSTACLES_ACTIFS]);
	virtual ~Platform();

	void ajouterAuJeu(TypeObstacle type);
	void effacerObstacle(Obstacle* obstacle);
	Direction checkPhoneme(int input);
	void checkCollision();
	void moveObstacles();
	void movePlayer();

	void Update(int input);    //est appelé a chaque frame, sert a updater les positions du joueur/obstacles et phonemes et collisions ,etc

	//setters
	void set_player(Runner & player);
	void set_level(int level);
	//liste

	//getters
	Runner* get_player() { return _player; }
	Liste* get_listeObstaclesActifs() { return _listeObstaclesActifs; }

private:
	Runner* _player;    //ajout du tableau de position
	int _nbrObstaclesActifs;
	ObstacleID* _tableauID[MAX_OBSTACLES_ACTIFS];
	Liste* _listeObstaclesActifs;
	Direction _lastPhoneme;
};

#endif //PLATFORM_H
