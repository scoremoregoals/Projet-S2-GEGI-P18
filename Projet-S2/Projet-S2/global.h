#ifndef GLOBAL_H
#define GLOBAL_H

const int FRAMETIME = 1000 / 60;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int LASER_BASE_SPEED = 2;
const int LASER_SLOWED_SPEED = 1;
const int POWERUP_BASE_SPEED = 5;
const int POWERUP_SLOWED_SPEED = 3;
extern int MAX_OBSTACLES_ACTIFS;
extern int LAST_PHONEME;

enum TypeObstacle   //sert pour savoir avec quoi le joueur collisionne, s'assigne lors de la construction de l'obstacle
{
	hlaser,
	vlaser,
	powerUp  //etc..
};

enum Direction
{
	gauche,
	droite,
	nulle
};

enum PowerUpType
{
	Slow,
	Destroy
};


#endif //GLOBAL_H