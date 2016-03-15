#ifndef GLOBAL_H
#define GLOBAL_H

const int FRAMETIME = 1000 / 20;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
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


#endif //GLOBAL_H