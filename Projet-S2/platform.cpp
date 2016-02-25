#include "platform.h"
#include <iostream> 



Platform::Platform()
{
		//_obstacles = obstacles;
		_player = NULL;
		_nbrObstacles = 0;
}

Platform::~Platform()
{
}

Platform::Platform( Runner & player, list<Obstacle*> liste)
{
		//_obstacles = obstacles;
		_player = &player;
		_nbrObstacles = 0;
		_listeObstacles = liste;
		
}
/*
void Platform::Update() //a modifier, selon les fonctions Runner::Update() et Obstacle::Update()
{
	Direction directionJoueur = checkPhoneme(); //on va cherche le phoneme
	_player->move(directionJoueur);
	for (int i = 0; i < _listeObstacles->get_longueur(); i++)
	{
		Obstacle* temp = _listeObstacles->get_courant();
		temp->Update();	
		_listeObstacles->suivant();
	}
	checkCollision();
}*/

Direction Platform::checkPhoneme() // a implementer
{
	return droite;
}
/*
void Platform::checkCollision()
{
	Rectangle* playerRect = new Rectangle(_player->get_width(), _player->get_height(), _player->get_position()->get_positionX(),
		 _player->get_position()->get_positionY());   //rectangle de collision du joueur
		 
	//Check collision avec chaque obstacle
	for (int i = 0; i < _listeObstacles->get_longueur(); i++)
	{
		Obstacle* temp = _listeObstacles->get_courant();
		Rectangle* obstacleRect = new Rectangle(temp->get_width(), temp->get_height(), temp->get_position()->get_positionX(),
		 temp->get_position()->get_positionY());     //rectangle de collision de l'obstacle
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
		_listeObstacles->suivant();
		delete obstacleRect;
		delete temp;
	}
	delete playerRect;
}*/
/*
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
}*/

//setters
void Platform::set_player(Runner & player)
{
	_player = &player;
}








