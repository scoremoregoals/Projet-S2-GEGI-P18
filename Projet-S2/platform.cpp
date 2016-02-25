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

void Platform::Update(int input) //a modifier, selon les fonctions Runner::Update() et Obstacle::Update()
{
	Direction directionJoueur = checkPhoneme(input); //on va cherche le phoneme
	_player->move(directionJoueur);
	list<Obstacle*>::iterator temp;
	for (temp = _listeObstacles.begin(); temp != _listeObstacles.end(); temp++)
	{
		(*temp)->Update();
	}
	checkCollision();
}

Direction Platform::checkPhoneme(int input) // a implementer
{
	switch (input)
	{
	case 1:
		return haut;
		break;
	case 2:
		return bas;
		break;
	case 3:
		return gauche;
		break;
	case 4:
		return droite;
		break;
	default:
		break;
	}
}

void Platform::checkCollision()
{
	Rectangle* playerRect = new Rectangle(_player->get_width(), _player->get_height(), _player->get_position()->get_positionX(),
		_player->get_position()->get_positionY());   //rectangle de collision du joueur

	list<Obstacle*>::iterator temp;
	for (temp = _listeObstacles.begin(); temp != _listeObstacles.end(); temp++)
	{
		Rectangle* obstacleRect = new Rectangle((*temp)->get_width(), (*temp)->get_height(), (*temp)->get_position()->get_positionX(),
			(*temp)->get_position()->get_positionY());
		if (playerRect->checkIntersect(obstacleRect))
		{
			//IL Y A COLLISION, FAIRE ACTIONS...
			//REGARDER NATURE DU L'OBSTACLE (QUI FAIT DU DEGAT, QUI DONNE UN BOOST, ETC) ET MODIFIER LES ATTRIBUTS DU JOUEUR EN CONSEQUENCE
			switch ((*temp)->get_type())
			{
			case powerUp:
				cout << "player collision with powerUp" << endl;
				effacerObstacle((*temp));
				//...
				break;
			case hlaser:
				cout << "player collision with hlaser" << endl;
				effacerObstacle((*temp));
				//...
				break;
			case vlaser:
				cout << "player collision with vlaser" << endl;
				effacerObstacle((*temp));
				//...
				break;
			default:
				break;
			}
		}
		delete obstacleRect;
	}
	delete playerRect;
	return;
}


void Platform::creerObstacle(Obstacle* obstacle)
{
	if (_nbrObstacles >= MAX_OBSTACLES)    //ne peut ajouter plus que le max, modifier max (.h) pour ajouter plus
		return;
	_obstacles[_nbrObstacles] = obstacle;
	_nbrObstacles++;
}

void Platform::ajouterAuJeu(Obstacle* obstacle)
{
	_listeObstacles.push_front(obstacle);
	_listeObstacles.front()->spawn();
}

void Platform::effacerObstacle(Obstacle* obstacle)
{
	_listeObstacles.remove(obstacle);
	switch (obstacle->get_type())
	{
	case powerUp:
		cout << "powerUp delete" << endl;
		break;
	case hlaser:
		cout << "hlaser delete" << endl;
		break;
	case vlaser:
		cout << "vlaser delete" << endl;
		break;
	default:
		break;
	}
}

//setters
void Platform::set_player(Runner & player)
{
	_player = &player;
}








