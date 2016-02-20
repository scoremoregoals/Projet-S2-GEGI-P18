#include "platform.h"
#include <iostream> 

Platform::Platform()
{
		//_obstacles = obstacles;
		_player = NULL;
		_obstacleBaseSpeed = 0;
		for (int i = 0; i < MAX_POSITIONS; i++)
		{
			_positions[i] = NULL;	
		}
		_nbrObstacles = 0;
}

Platform::~Platform()
{
	for (int i = 0; i < MAX_POSITIONS; i++)
	{
		delete _positions[i];
		_positions[i] = NULL;
	}
}

Platform::Platform( Runner & player, double obstacleBaseSpeed, Vector2* positions[MAX_POSITIONS], Liste& liste)
{
		//_obstacles = obstacles;
		_player = &player;
		_obstacleBaseSpeed = obstacleBaseSpeed;
		for (int i = 0; i < MAX_POSITIONS; i++)
		{
			_positions[i] = positions[i];	
		}
		_nbrObstacles = 0;
		_listeObstacles = &liste;
		
}

void Platform::checkCollision()
{
	Rectangle* playerRect = new Rectangle(_player->get_width(), _player->get_height(), _player->get_position()->get_positionX(),
		 _player->get_position()->get_positionY());
		 
	//Check collision avec chaque obstacle
	for (int i = 0; i < _listeObstacles->get_longueur(); i++)
	{
		Obstacle* temp = _listeObstacles->get_courant();
		Rectangle* obstacleRect = new Rectangle(temp->get_width(), temp->get_height(), temp->get_position()->get_positionX(),
		 temp->get_position()->get_positionY());
		if (playerRect->checkIntersect(obstacleRect))
		{
			//IL Y A COLLISION, FAIRE ACTIONS...
			//REGARDER NATURE DU L'OBSTACLE (QUI FAIT DU DEGAT, QUI DONNE UN BOOST, ETC) ET MODIFIER LES ATTRIBUTS DU JOUEUR EN CONSEQUENCE
			switch (temp->get_type())
			{
				case power :
					//...
					break;
				case laser :
					//...
					break;
				default:
					break;
			}
		}
		delete obstacleRect;
		delete temp;
	}
	delete playerRect;
}

void Platform::creerObstacle(Obstacle& obstacle)
{
	if (_nbrObstacles >= MAX_OBSTACLES)    //ne peut ajouter plus que le max, modifier max (.h) pour ajouter plus
		return;
	_obstacles[_nbrObstacles] = &obstacle;
	_nbrObstacles++;
}

void Platform::ajouterAuJeu(Obstacle& obstacle)
{
	_listeObstacles->ajouter(obstacle);	
	obstacle.spawn();
}

//setters
void Platform::set_player(Runner & player)
{
	_player = &player;
}

void Platform::set_obstacleBaseSpeed(double obstacleBaseSpeed)
{
	_obstacleBaseSpeed = obstacleBaseSpeed;
}

void Platform::set_positions(Vector2 positions[MAX_POSITIONS])
{
	for (int i = 0; i < MAX_POSITIONS; i++)
	{
		_positions[i] = &positions[i];
	}
}







