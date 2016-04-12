#ifndef GLOBAL_H
#define GLOBAL_H

/**
 * Time for a frame
 */
const int FRAMETIME = 1000 / 60;
/**
 * Width size of the playable screen
 */
const int SCREEN_WIDTH = 800;
/**
 * Height size of the playable screen
 */
const int SCREEN_HEIGHT = 600;
/**
 * Normal laser speed
 */
const int LASER_BASE_SPEED = 2;
/**
 * Slower laser speed
 */
const int LASER_SLOWED_SPEED = 1;
/**
 * Normal powerup speed
 */
const int POWERUP_BASE_SPEED = 5;
/**
 * Slower powerup speed
 */
const int POWERUP_SLOWED_SPEED = 3;
/**
 * Max obstacle speed
 */
extern int MAX_OBSTACLES_ACTIFS;
/**
 * Last phoneme received
 */
extern int LAST_PHONEME;

/**
 * @brief      To know wich type of colision the player will have
 */
enum TypeObstacle
{
	hlaser,
	vlaser,
	powerUp  //etc..
};

/**
 * @brief      Direction of a object
 */
enum Direction
{
	gauche,
	droite,
	nulle
};

/**
 * @brief      Types of powerups
 */
enum PowerUpType
{
	Slow,
	Destroy
};


#endif //GLOBAL_H