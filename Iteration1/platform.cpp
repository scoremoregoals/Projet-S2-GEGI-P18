#include "platform.h"
#include <iostream> 


Platform::Platform()
{
		_player = NULL;
}

Platform::~Platform()
{
}

Platform::Platform(Runner & player, Liste& liste, ObstacleID* id[MAX_OBSTACLES_ACTIFS])
{
	for (int i = 0; i < MAX_OBSTACLES_ACTIFS; i++)
	{
		_tableauID[i] = id[i];
	}
	_listeObstaclesActifs = &liste;
	_player = &player;
	_lastPhoneme = nulle;
}

void Platform::Update(int input) //a modifier, selon les fonctions Runner::Update() et Obstacle::Update()
{
	Direction directionJoueur = checkPhoneme(input); //on va cherche le phoneme
	if (directionJoueur == nulle)   // si aucun phoneme n'est detecte, on garde la meme direction qu'au frame d'avant
	{
		_lastPhoneme = _player->move(_lastPhoneme);
	}
	else
		_lastPhoneme = _player->move(directionJoueur);
	_player->afficherDetails();

	if (_listeObstaclesActifs->get_longueur() < 1)   //n'update pas et ne check pas collisions si liste vide
		return;

	_listeObstaclesActifs->premier();
	Obstacle* temp = _listeObstaclesActifs->get_courant();
	for (int i = 0; i < _listeObstaclesActifs->get_longueur(); i++)
	{
		temp->Update();
		temp->afficherDetails();
		_listeObstaclesActifs->suivant();
		temp = _listeObstaclesActifs->get_courant();
	}
	checkCollision();
}

Direction Platform::checkPhoneme(int input)
{
	switch (input)   //direction dans laquelle le joueur va aller selon le input
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
		return nulle;
		break;
	}
}

void Platform::checkCollision()
{
	Rectangle* playerRect = new Rectangle(_player->get_width(), _player->get_height(), _player->get_position()->get_positionX(),
		_player->get_position()->get_positionY());   //rectangle de collision du joueur

	_listeObstaclesActifs->premier();
	Obstacle* temp =_listeObstaclesActifs->get_courant();
	for (int i = 0; i < _listeObstaclesActifs->get_longueur(); i++)
	{
		Rectangle* obstacleRect = new Rectangle(temp->get_width(), temp->get_height(), temp->get_position()->get_positionX(),
			temp->get_position()->get_positionY());   //rectangle de collision pour obstacle
		if (playerRect->checkIntersect(obstacleRect))
		{
			//IL Y A COLLISION, FAIRE ACTIONS...
			//REGARDER NATURE DU L'OBSTACLE (QUI FAIT DU DEGAT, QUI DONNE UN BOOST, ETC) ET MODIFIER LES ATTRIBUTS DU JOUEUR EN CONSEQUENCE
			switch (temp->get_type())
			{
			case powerUp:
				cout << "player collision with powerUp" << endl;
				//...
				effacerObstacle(temp);
				//...
				break;
			case hlaser:
				cout << "player collision with hlaser" << endl;
				get_player()->set_life(get_player()->get_life() - temp->get_damage());
				//...
				effacerObstacle(temp);
				break;
			case vlaser:
				cout << "player collision with vlaser" << endl;
				get_player()->set_life(get_player()->get_life() - temp->get_damage());
				//...
				effacerObstacle(temp);
				break;
			default:
				break;
			}
		}
		delete obstacleRect;
		_listeObstaclesActifs->suivant();              //increment temp au prochain element de la liste
		temp = _listeObstaclesActifs->get_courant();
	}
	delete playerRect;
	return;
}

void Platform::ajouterAuJeu(TypeObstacle type) //1->hlaserm 2->vlaser, 3->powerUp1, 4->powerUp2
{
	ObstacleID* newID = new ObstacleID();
	bool foundValidID = false;
	for (int i = 0; i < MAX_OBSTACLES_ACTIFS; i++)   //on verifie si il reste un ID disponible
	{
		if (_tableauID[i]->isTaken() == false)
		{
			_tableauID[i]->set_taken(true);
			newID = _tableauID[i];                 //place un ID disponible dans une variable
			foundValidID = true;                
			break;
		}
	}

	if (!foundValidID)                   //si pas de ID disponible, on ne peu ajouter d'obstacle nouveau
	{
		return;
	}

	Obstacle* temp;
	switch (type)
	{
		//Modifier les dimensions selon les sprites-> width = 2e parametre, height = 3e parametre
	case hlaser:
		temp = new Hlaser(5, 20, 10, 10);    //on cre l'obstacle
		temp->set_id(newID->get_id());              //on donne a l'obstacle le ID disponible obtenu plus haut
		_listeObstaclesActifs->ajouter(temp);        //on l'ajoute a la liste
		temp->spawnHorizontal();   //l'obstacle spawn dans le jeu
		break;
	case vlaser:
		temp = new Vlaser(5, 10, 10, 10);
		temp->set_id(newID->get_id());
		_listeObstaclesActifs->ajouter(temp);
		temp->spawnVertical();
		break;
	case powerUp:
		temp = new PowerUp(5, 20, 18, 0);
		temp->set_id(newID->get_id()); 
		_listeObstaclesActifs->ajouter(temp);
		temp->spawnVertical();
		break;
	default:
		break;
	}

}

void Platform::effacerObstacle(Obstacle* obstacle)
{
	if (_listeObstaclesActifs->get_longueur() < 1)  //n'efface rien si liste vide
		return;
	int obstacleEffacerID = obstacle->get_id();

	_listeObstaclesActifs->premier();
	Obstacle* temp = _listeObstaclesActifs->get_courant();
	for (int i = 0; i < _listeObstaclesActifs->get_longueur(); i++)
	{
		if (temp == obstacle)          //si temp = l'obstacle a effacer, on efface temp
		{
			_tableauID[obstacleEffacerID]->set_taken(false); // on rend l'ID de l'obstacle effacer disponible
			_listeObstaclesActifs->effacer();
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
		_listeObstaclesActifs->suivant();          // on icremente dans la liste
		temp = _listeObstaclesActifs->get_courant();
	}
}

//setters
void Platform::set_player(Runner & player)
{
	_player = &player;
}








