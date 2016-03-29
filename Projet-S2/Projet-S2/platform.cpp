#include "platform.h"
#include <iostream> 

Platform::~Platform()
{
	delete _player;
	delete _listeObstaclesActifs;
}

Platform::Platform()
{
	//gamestate
	_gameState = NotInitialized;
	_gameOver = false;

	//level
	_level = 1;
	_levelup = false;

	//liste d'obstacle
	_listeObstaclesActifs = new Liste();

	//powerup
	_currentPowerUp = nullptr;
	_slowedDown = false;

	//scene and view
	_scene = new QGraphicsScene();
	_view = new QGraphicsView();
	_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	_view->setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	_scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	_view->setScene(_scene);

	//background
	_background = new BackGround("background.png");
	_scene->addItem(_background->get_background1());
	_scene->addItem(_background->get_background2());
	//container pour powerUp
	QGraphicsPixmapItem* powerUpRect = new QGraphicsPixmapItem();
	powerUpRect->setPixmap(QPixmap("powerUpRect.png"));
	powerUpRect->setPos(SCREEN_WIDTH - powerUpRect->boundingRect().width() - 15, 30);
	powerUpRect->setZValue(1);
	_scene->addItem(powerUpRect);
	_currentPowerUpImage = new QGraphicsPixmapItem();
	_currentPowerUpImage->setPixmap(QPixmap("noPowerUp.png"));
	_currentPowerUpImage->setPos(SCREEN_WIDTH - powerUpRect->boundingRect().width() - 10, 35);
	_currentPowerUpImage->setZValue(2);
	_scene->addItem(_currentPowerUpImage);

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
	//level
	_levelText = new Text();
	_levelText->set_value(_level);
	_levelText->set_name("Level");
	_levelText->setPos(_view->width() / 2 - 35, 0);
	_scene->addItem(_levelText);
	_levelText->draw();
	//current power up
	currentPowerUpText = new QGraphicsTextItem();
	currentPowerUpText->setPlainText("Current PowerUp :");
	currentPowerUpText->setPos(SCREEN_WIDTH - 170, 0);
	currentPowerUpText->setDefaultTextColor(Qt::white);
	currentPowerUpText->setFont(QFont("times", 14));
	_scene->addItem(currentPowerUpText);

	/*SOUNDS*/
	//background music
	_bgMusic = new QMediaPlayer();
	_bgMusic->setMedia(QUrl("backgroundmusic.mp3"));
	//collisions
	_laserCollisionSound = new QMediaPlayer();
	_laserCollisionSound->setMedia(QUrl("laserCollision.wav"));
	_powerUpCollisionSound = new QMediaPlayer();
	_powerUpCollisionSound->setMedia(QUrl("powerUpCollision.wav"));
	//gameover
	_gameOverSound = new QMediaPlayer();
	_gameOverSound->setMedia(QUrl("gameOver.wav"));
	//destroy power 
	_destroySound = new QMediaPlayer();
	_destroySound->setMedia(QUrl("destroyPowerup.wav"));
	//slow down power up
	_slowDownSound = new QMediaPlayer();
	_slowDownSound->setMedia(QUrl("slowDownpowerup.wav"));
	timerSlowDown = new QElapsedTimer();

	//timer frame
	timerFrame = new QTimer();
	QObject::connect(timerFrame, SIGNAL(timeout()), this, SLOT(Update()));
	timerElapsed = new QElapsedTimer();

	//animation test
	Animation* _animation = new Animation(50, 72, 10, FRAMETIME, "spritesheet.png");
	_animation->get_frame()->setPos(0, 50);
	_scene->addItem(_animation->get_frame());
}

void Platform::initialize()
{
	timerFrame->setInterval(FRAMETIME);
	timerFrame->start();
	timerElapsed->start();

	currentFrameTime = 0;
	totalPauseTime = 0;
	timeSinceLastPause = 0;
	pauseTime = 0;

	_player->setFocus();

	_gameState = Running;

	_bgMusic->play();

	_view->show();
}

void Platform::Update()
{
	Obstacle* temp;
	Direction direction;
	switch (_gameState)
	{
	case NotInitialized: //ne fait rien tant que le jeu n'est pas initie
		return;
		break;


	case Paused:
		if (_player->get_isRunning())
		{
			cout << "GAME RESUMED" << endl;
			totalPauseTime += timerElapsed->elapsed() - pauseTime;
			_gameState = Running;
		}
		//stop music
		_bgMusic->pause();
		return;
		break;


	case GameOver:
		//player loses
		if (!_gameOver)
		{
			cout << "GAME OVER!" << endl;
			_gameOverImage = new QGraphicsPixmapItem();
			_gameOverImage->setPixmap(QPixmap("gameover.png"));
			_gameOverImage->setPos(0, 0);
			_gameOverImage->setOpacity(0.00);
			_scene->addItem(_gameOverImage);
			_gameOver = true;
		}
		_bgMusic->setVolume(_bgMusic->volume() - 0.015);
		_gameOverImage->setOpacity(_gameOverImage->opacity() + 0.01);
		if (_bgMusic->volume() <= 0)
		{
			_gameOverSound->play();
			_bgMusic->stop();
			timerFrame->stop();
			delete this;
		}
		break;


	case Running:
		if (!_player->get_isRunning())
		{
			cout << "GAME PAUSED" << endl;
			pauseTime = timerElapsed->elapsed();
			_gameState = Paused;
		}
		//check si power up utilise
		if (_player->get_usePowerup())
		{
			usePowerUp();
		}
		//check si slow down termine
		currentFrameTime = timerSlowDown->elapsed();
		if (_slowedDown)
		{
			slowDown();
			if (timerSlowDown->elapsed() - totalPauseTime > 5000 && _slowedDown)
			{
				_slowedDown = false;
				speedUp();
			}
		}
		//play music
		_bgMusic->play();

		//frame time
		currentFrameTime = timerElapsed->elapsed() - totalPauseTime;

		//background
		_background->move();

		//texts
		_gameTime->set_value((float)currentFrameTime / 1000);
		_gameTime->draw();
		_levelText->set_value(_level);
		_levelText->draw();

		if (currentFrameTime % 1000 < 15)
		{
			ajouterAuJeu(vlaser);
		}

		if (currentFrameTime % 4000 < 25)
		{
			ajouterAuJeu(powerUp);
		}

		if (currentFrameTime % 1100 < 15)
		{
			ajouterAuJeu(hlaser);
		}

		if (currentFrameTime % 9900 < 20)
			_levelup = true;

		if (currentFrameTime % 10000 < 20 && _levelup)
		{
			if (currentFrameTime > 100)
			{
				_level++;
				MAX_OBSTACLES_ACTIFS++;
				cout << "------------LEVEL UP! LEVEL : " << _level << " max obstacles = " << MAX_OBSTACLES_ACTIFS << endl;
				_levelup = false;
			}
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

void Platform::usePowerUp()
{
	if (_currentPowerUp != nullptr)
	{
		switch (_currentPowerUp->get_powerUpType())
		{
		case Slow:
			cout << "SLOW DOWN POWER UP" << endl;
			_slowDownSound->play();
			_slowedDown = true;
			timerSlowDown->restart();
			timerSlowDown->start();
			break;
		case Destroy:
			clearListe();
			cout << "DESTROY POWER UP" << endl;
			_destroySound->play();
			break;

		default:
			break;
		}
		delete _currentPowerUp;
		_currentPowerUp = nullptr;
		_currentPowerUpImage->setPixmap(QPixmap("noPowerUp.png"));
	}
	else
	{
		cout << "pas de current power up a utilise" << endl;
	}
	_player->set_usePowerup(false);
}

void Platform::slowDown()
{
	_listeObstaclesActifs->premier();
	Obstacle* temp = _listeObstaclesActifs->get_head();
	for (int i = 0; i < _listeObstaclesActifs->get_longueur(); i++)
	{
		temp = _listeObstaclesActifs->get_courant();
		if (temp->get_type() == powerUp)
			temp->set_speed(POWERUP_SLOWED_SPEED);
		else
			temp->set_speed(LASER_SLOWED_SPEED);
		_listeObstaclesActifs->suivant();
	}
}

void Platform::speedUp()
{
	_listeObstaclesActifs->premier();
	Obstacle* temp = _listeObstaclesActifs->get_head();
	for (int i = 0; i < _listeObstaclesActifs->get_longueur(); i++)
	{
		temp = _listeObstaclesActifs->get_courant();
		if (temp->get_type() == powerUp)
			temp->set_speed(POWERUP_BASE_SPEED);
		else
			temp->set_speed(LASER_BASE_SPEED);
		_listeObstaclesActifs->suivant();
	}
}
void Platform::clearListe()
{
	_listeObstaclesActifs->premier();
	Obstacle* temp = _listeObstaclesActifs->get_head();
	_scene->removeItem(temp);
	_listeObstaclesActifs->effacer();
	if (_listeObstaclesActifs->get_longueur() > 0)
		clearListe();
	else
		return;
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
				if (_powerUpCollisionSound->state() == QMediaPlayer::PlayingState)
					_powerUpCollisionSound->setPosition(0);
				_powerUpCollisionSound->play();

				//creer deep copie du power up pour affichage dans le coin droit
				if (_currentPowerUp == nullptr)
					_currentPowerUp = new PowerUp(temp);
				else
					cout << "deja un current powerup non utilise" << endl;

				switch (_currentPowerUp->get_powerUpType())
				{
				case Slow:
					_currentPowerUpImage->setPixmap(QPixmap("powerupSlow.png"));
					break;
				case Destroy:
					_currentPowerUpImage->setPixmap(QPixmap("powerupDestroy.png"));
					break;
				default:
					break;
				}
				effacerObstacle(temp);
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

		//si player meure
		if (_player->get_life() <= 0)
			_gameState = GameOver;

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
		break;
	case vlaser:
		temp = new Vlaser();
		_listeObstaclesActifs->ajouter(temp);
		temp->setPixmap(QPixmap("vlaser.png"));
		temp->setPos(temp->spawnVertical(), 0 - temp->get_height());
		_scene->addItem(temp);
		temp->playSpawnSound();
		break;
	case powerUp:
		temp = new PowerUp();
		temp->randomizeType();
		_listeObstaclesActifs->ajouter(temp);
		temp->setPos(temp->spawnVertical(), 0 - temp->get_height());
		_scene->addItem(temp);
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
		_listeObstaclesActifs->suivant();          // on incremente dans la liste
		temp = _listeObstaclesActifs->get_courant();
	}
	cout << "removed, new length liste : " << _listeObstaclesActifs->get_longueur() << endl;
}







