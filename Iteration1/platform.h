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

const int MAX_OBSTACLES = 4; //CONTIENT LE NBR D'OBJETS DIFFERENTS DU JEU
const int MAX_OBSTACLES_ACTIFS = 6;

class Platform
{
public:
	Platform();
	Platform(Runner & player, list<Obstacle*> liste);
	Platform(Runner & player, Liste& liste, ObstacleID* id[MAX_OBSTACLES_ACTIFS],
		Vector2* verticalValidSpawn[MAX_VALIDSPAWN_VERT], Vector2* horizontalValidSpawn[MAX_VALIDSPAWN_HORIZ]);
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
	//liste

	//getters
	Runner* get_player() { return _player; }
	Liste* get_listeObstaclesActifs() { return _listeObstaclesActifs; }

private:
	list<Obstacle*>  _listeObstacles;			//liste d'obstacle actifs sur la plateforme
	Runner* _player;    //ajout du tableau de position
	int _nbrObstaclesActifs;
	ObstacleID* _tableauID[MAX_OBSTACLES_ACTIFS];
	Liste* _listeObstaclesActifs;
	Vector2* _verticalValidSpawn[MAX_VALIDSPAWN_VERT];
	Vector2* _horizontalValidSpawn[MAX_VALIDSPAWN_HORIZ];

};

#endif //PLATFORM_H
