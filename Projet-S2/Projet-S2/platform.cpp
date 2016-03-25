#include "platform.h"
#include <iostream> 

Platform::~Platform()
{}

Platform::Platform()// ObstacleID* id[MAX_OBSTACLES_ACTIFS])
{
	//gamestate
	_gameState = NotInitialized;

	//liste d'obstacle
	_listeObstaclesActifs = new Liste();

	//scene and view
	_scene = new QGraphicsScene();
	_view = new QGraphicsView();
	_view->setBackgroundBrush(QBrush(QImage("background.png")));
	_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	_view->setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	_scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	_view->setScene(_scene);

	//player
	_player = new Runner();
	_player->setPixmap(QPixmap("player.png"));
	_player->setFlag(QGraphicsItem::ItemIsFocusable);
	_scene->addItem(_player);
	_player->setPos(_view->width() / 2 - _player->get_width() / 2,
		_view->height() - _player->get_height() - 5);
	_player->set_isRunning(true);

	/*Texts*/
	//health
	_playerHealth = new Text();
	_playerHealth->set_value(_player->get_life());
	_playerHealth->set_name("Health");
	_playerHealth->setPos(_playerHealth->x(), _playerHealth->y() + 25);
	_scene->addItem(_playerHealth);
	_playerHealth->draw();
	//gametime
	_gameTime = new Text();
	_gameTime->set_value(currentFrameTime / 1000);
	_gameTime->set_name("GameTime");
	_scene->addItem(_gameTime);
	_gameTime->draw();

	/*SOUNDS*/
	//background music
	_bgMusic = new QMediaPlayer();
	_bgMusic->setMedia(QUrl("backgroundmusic.mp3"));
	//collisions
	_laserCollisionSound = new QMediaPlayer();
	_laserCollisionSound->setMedia(QUrl("laserCollision.wav"));
	_powerUpCollisionSound = new QMediaPlayer();
	_powerUpCollisionSound->setMedia(QUrl("powerUpCollision.wav"));
	//timer frame
	timerFrame = new QTimer();
	QObject::connect(timerFrame, SIGNAL(timeout()), this, SLOT(Update()));
	timerElapsed = new QElapsedTimer();
}

void Platform::initialize()
{
	timerFrame->setInterval(FRAMETIME);
	timerFrame->start();
	timerElapsed->start();

	currentFrameTime = 0;
	lastFrameTime = 0;
	timeSinceLastFrame = 0;

	_player->setFocus();

	_gameState = Running;

	_bgMusic->play();
}

void Platform::Update()
{
	Obstacle* temp;
	Direction direction;
	switch (_gameState)
	{
	case NotInitialized:
		return;
		break;
	case Paused:
		if (_player->get_isRunning())
		{
			cout << "game unpaused" << endl;
			_gameState = Running;
		}
		//stop music
		_bgMusic->pause();
		return;
		break;
	case GameOver:
		//player loses
		break;
	case Running:
		if (!_player->get_isRunning())
		{
			cout << "game paused" << endl;
			_gameState = Paused;
		}
		//play music
		_bgMusic->play();

		//frame times
		currentFrameTime = timerElapsed->elapsed();
		timeSinceLastFrame = currentFrameTime - lastFrameTime;
		lastFrameTime = currentFrameTime;

		//text
		_gameTime->set_value(currentFrameTime/1000);
		_gameTime->draw();

		//cout << "current frame : " <<  currentFrameTime << endl;

		//le spawn des obstacles a pas tant rapport c'etait juste pour tester
		if (currentFrameTime % 3000 < 150)
		{
			ajouterAuJeu(vlaser);
		}

		if (currentFrameTime % 6300 < 150)
		{
			ajouterAuJeu(powerUp);
		}

		if (currentFrameTime % 4500 < 150)
		{
			ajouterAuJeu(hlaser);
		}

		//MOVE PLAYER
		direction = checkPhoneme(LAST_PHONEME);
		_player->move(direction);

		if (_listeObstaclesActifs->get_longueur() < 1)   //n'update pas et ne check pas collisions si liste vide
			return;

		//MOVE OBSTACLES
		_listeObstaclesActifs->premier();
		temp = _listeObstaclesActifs->get_courant();
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
		break;
	default:
		break;
	}
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
				if (_powerUpCollisionSound->state() == QMediaPlayer::PlayingState)
					_powerUpCollisionSound->setPosition(0);
				_powerUpCollisionSound->play();
				effacerObstacle(temp);
				//...
				break;
			case hlaser:
				cout << "player collision with hlaser" << endl;
				_player->set_life(_player->get_life() - temp->get_damage());
				_playerHealth->set_value(_player->get_life());
				_playerHealth->draw();
				//play laser sound
				if (_laserCollisionSound->state() == QMediaPlayer::PlayingState)
					_laserCollisionSound->setPosition(0);
				_laserCollisionSound->play();
				effacerObstacle(temp);
				break;
			case vlaser:
				cout << "player collision with vlaser" << endl;
				_player->set_life(_player->get_life() - temp->get_damage());
				_playerHealth->set_value(_player->get_life());
				_playerHealth->draw();
				//play laser sound
				if (_laserCollisionSound->state() == QMediaPlayer::PlayingState)
					_laserCollisionSound->setPosition(0);
				_laserCollisionSound->play();
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


void Platform::ajouterAuJeu(TypeObstacle type)
{
	if (_listeObstaclesActifs->get_longueur() == MAX_OBSTACLES_ACTIFS)
	{
		return;    //liste pleine
	}

	Obstacle* temp;
	switch (type)
	{
	case hlaser:
		temp = new Hlaser();    //on cre l'obstacle
		_listeObstaclesActifs->ajouter(temp);        //on l'ajoute a la liste
		temp->setPixmap(QPixmap("hlaser.png"));
		temp->setPos(0 - temp->get_height(), temp->spawnHorizontal());
		_scene->addItem(temp);
		temp->playSpawnSound();
		cout << "spawn hlaser" << endl;
		break;
	case vlaser:
		temp = new Vlaser();
		_listeObstaclesActifs->ajouter(temp);
		temp->setPixmap(QPixmap("vlaser.png"));
		temp->setPos(temp->spawnVertical(), 0 - temp->get_height());
		_scene->addItem(temp);
		temp->playSpawnSound();
		cout << "spawn vlaser" << endl;
		break;
	case powerUp:
		temp = new PowerUp();
		_listeObstaclesActifs->ajouter(temp);
		temp->setPixmap(QPixmap("powerup.png"));
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







