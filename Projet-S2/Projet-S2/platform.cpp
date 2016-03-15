#include "platform.h"
#include <iostream> 


Platform::Platform()
{	
}

Platform::~Platform()
{}

Platform::Platform(Runner * player, Liste& liste)// ObstacleID* id[MAX_OBSTACLES_ACTIFS])
{
	_listeObstaclesActifs = &liste;
	_player = player;
	_level = 1;
	_isPaused = false;

	//scene
	_scene = new QGraphicsScene();
	_view = new QGraphicsView();
	_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	_view->setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	_scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	_view->setScene(_scene);

	//player
	_player->setRect(0, 0, _player->get_width(), _player->get_height());
	_player->setFlag(QGraphicsItem::ItemIsFocusable);
	_player->setFocus();
	_scene->addItem(_player);
	_player->setPos(_view->width() / 2 - _player->rect().width() / 2,
		_view->height() - _player->rect().height() - 5);
	_player->set_isRunning(true);

	//Text
	_playerHealth = new Text();
	_playerHealth->set_value(_player->get_life());
	_playerHealth->set_name("Health");
	_playerHealth->setPos(_playerHealth->x(), _playerHealth->y() + 25);
	_scene->addItem(_playerHealth);
	_playerHealth->draw();
	
	_gameTime = new Text();
	_gameTime->set_value(currentFrameTime / 1000);
	_gameTime->set_name("GameTime");
	_scene->addItem(_gameTime);
	_gameTime->draw();


	//timer frame
	timerFrame = new QTimer();
	QObject::connect(timerFrame, SIGNAL(timeout()), this, SLOT(Update()));
	timerFrame->setInterval(FRAMETIME);
	timerFrame->start();

	currentFrameTime = 0;
	lastFrameTime = 0;
	timeSinceLastFrame = 0;

	timer = new QElapsedTimer();
	timer->start();

	_view->show();
}

void Platform::Update()
{
	if (!_player->get_isRunning()) //on update pas en pause
	{
		if (!_isPaused)
		{
			cout << "game paused" << endl;
			_isPaused = true;
		}
		return;
	}
	_isPaused = false;
	currentFrameTime = timer->elapsed();
	timeSinceLastFrame = currentFrameTime - lastFrameTime;
	lastFrameTime = currentFrameTime;
	_gameTime->set_value(currentFrameTime / 1000);
	_gameTime->draw();
	//cout << "current frame : " <<  currentFrameTime << endl;

	if (currentFrameTime % 2000 < 150)
	{
		ajouterAuJeu(vlaser);
	}

	if (currentFrameTime % 6000 < 150)
	{
		ajouterAuJeu(powerUp);
	}

	if (currentFrameTime % 4000 < 150)
	{
		ajouterAuJeu(hlaser);
	}

	if (currentFrameTime % 10000 < 100)
	{
		_level++;
		MAX_OBSTACLES_ACTIFS++;
		cout << "------>> level up : " << _level << " ---->> max obstacles -> " << MAX_OBSTACLES_ACTIFS << endl;
	}

	//MOVE PLAYER
	Direction direction = checkPhoneme(LAST_PHONEME);
	_player->move(direction);

	if (_listeObstaclesActifs->get_longueur() < 1)   //n'update pas et ne check pas collisions si liste vide
		return;

	//MOVE OBSTACLES
	_listeObstaclesActifs->premier();
	Obstacle* temp = _listeObstaclesActifs->get_courant();
	for (int i = 0; i < _listeObstaclesActifs->get_longueur(); i++)
	{
		temp->update();
		if (temp->x() > SCREEN_WIDTH || temp->y() > SCREEN_HEIGHT) //en dehors du jeu
		{
			effacerObstacle(temp);
		}
		_listeObstaclesActifs->suivant();
		temp = _listeObstaclesActifs->get_courant();
	}

	//CHECK COLLISION ENTRE PLAYER ET OBSTACLES
	checkCollision();
}


Direction Platform::checkPhoneme(int input)
{
	switch (input)   //direction dans laquelle le joueur va aller selon le input
	{
	case 1:
		return gauche;
		break;
	case 2:
		return droite;
		break;
	default:
		return nulle;
		break;
	}
}

void Platform::checkCollision()
{
	Rectangle* playerRect = new Rectangle(_player->get_width(), _player->get_height(),
		_player->x(), _player->y());   //rectangle de collision du joueur

	_listeObstaclesActifs->premier();
	Obstacle* temp =_listeObstaclesActifs->get_courant();
	for (int i = 0; i < _listeObstaclesActifs->get_longueur(); i++)
	{
		Rectangle* obstacleRect = new Rectangle(temp->get_width(), temp->get_height(), 
			temp->x(), temp->y());   //rectangle de collision pour obstacle
		if (playerRect->checkIntersect(obstacleRect))
		{
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
				_player->set_life(_player->get_life() - temp->get_damage());
				_playerHealth->set_value(_player->get_life());
				_playerHealth->draw();
				effacerObstacle(temp);
				break;
			case vlaser:
				cout << "player collision with vlaser" << endl;
				_player->set_life(_player->get_life() - temp->get_damage());
				_playerHealth->set_value(_player->get_life());
				_playerHealth->draw();
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
	if (_listeObstaclesActifs->get_longueur() == MAX_OBSTACLES_ACTIFS)
	{
		return;    //liste pleine
	}

	Obstacle* temp;
	switch (type)
	{
	case hlaser:
		temp = new Hlaser(10, 50, 10, 10);    //on cre l'obstacle
		_listeObstaclesActifs->ajouter(temp);        //on l'ajoute a la liste
		temp->setRect(0, 0, temp->get_width(), temp->get_height());
		temp->setPos(0 - temp->get_height(), temp->spawnHorizontal());
		_scene->addItem(temp);
		cout << "spawn hlaser" << endl;
		break;
	case vlaser:
		temp = new Vlaser(10, 10, 50, 10);
		_listeObstaclesActifs->ajouter(temp);
		temp->setRect(0, 0, temp->get_width(), temp->get_height());
		temp->setPos(temp->spawnVertical(), 0 - temp->get_height());
		_scene->addItem(temp);
		cout << "spawn vlaser" << endl;
		break;
	case powerUp:
		temp = new PowerUp(10, 50, 50, 0);
		_listeObstaclesActifs->ajouter(temp);
		temp->setRect(0, 0, temp->get_width(), temp->get_height());
		temp->setPos(temp->spawnVertical(), 0 - temp->get_height());
		_scene->addItem(temp);
		cout << "spawn powerUp" << endl;
		break;
	default:
		break;
	}
	cout << "added, new length liste : " << _listeObstaclesActifs->get_longueur() << endl;
}

void Platform::effacerObstacle(Obstacle* obstacle)
{
	if (_listeObstaclesActifs->get_longueur() < 1)  //n'efface rien si liste vide
		return;

	_listeObstaclesActifs->premier();
	Obstacle* temp = _listeObstaclesActifs->get_courant();
	for (int i = 0; i < _listeObstaclesActifs->get_longueur(); i++)
	{
		if (temp == obstacle)          //si temp = l'obstacle a effacer, on efface temp
		{
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
			_scene->removeItem(temp);                       //enleve de la scene
			_listeObstaclesActifs->effacer();                //enleve de la liste
		}
		_listeObstaclesActifs->suivant();          // on icremente dans la liste
		temp = _listeObstaclesActifs->get_courant();
	}
	cout << "removed, new length liste : " << _listeObstaclesActifs->get_longueur() << endl;
}







