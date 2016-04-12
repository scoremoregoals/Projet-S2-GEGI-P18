#include "Headers/platform.h"
#include <iostream>
#include <fstream>

Platform::~Platform()
{
	//DELETE DYNAMIC OBJECTS
	delete _player;
	delete _listOfObstacles;
}

Platform::Platform()
{
	//PLATFORM ATTRIBUTES
	initializeSettings();
	//SCENE, VIEW
	createScene();
	//GAME OBJECTS
	createObjects();
	//GAME TEXTS
	createTexts();
	//SOUNDS
	loadSounds();
}

void Platform::createObjects()
{
	//LIST OF OBSTACLES
	_listOfObstacles = new Liste();
	//BACKGROUND
	_background = new BackGround("images/background.png");
	_scene->addItem(_background->get_background1());
	_scene->addItem(_background->get_background2());
	//CURRENT POWERUP
	_currentPowerUpImage = new QGraphicsPixmapItem();
	_currentPowerUpImage->setPixmap(_noPowerUpTexture);
	_currentPowerUpImage->setPos(SCREEN_WIDTH - 66, 38);
	_currentPowerUpImage->setZValue(11);
	_scene->addItem(_currentPowerUpImage);
	//PLAYER
	_player = new Runner();
	_player->setFlag(QGraphicsItem::ItemIsFocusable);
	_scene->addItem(_player);
	_player->setPos(_view->width() / 2 - _player->get_width() / 2,
		_view->height() - _player->get_height() - 30);
	//HUDS
	//score
	_scoreHUD = new QGraphicsPixmapItem();
	_scoreHUD->setPixmap(QPixmap("images/scoreHUD.jpg"));
	_scoreHUD->setPos(3, 3);
	_scoreHUD->setZValue(10);
	_scene->addItem(_scoreHUD);
	//current Power
	_currentPowerHUD = new QGraphicsPixmapItem();
	_currentPowerHUD->setPixmap(QPixmap("images/currentPowerHUD.jpg"));
	_currentPowerHUD->setPos(_view->width() - 176, 3);
	_scene->addItem(_currentPowerHUD);
	_currentPowerHUD->setZValue(10);
	//FRAME TIMER
	timerFrame = new QTimer();
	QObject::connect(timerFrame, SIGNAL(timeout()), this, SLOT(Update()));
	timerElapsed = new QElapsedTimer();
}

void Platform::initializeSettings()
{
	//GAMESTATE
	_gameState = NotInitialized;
	_gameOver = false;
	currentFrameTime = 0;
	//LEVEL
	_level = 1;
	_levelup = false;
	//CURRENT POWERUP
	_currentPowerUp = nullptr;
	_slowedDown = false;
	//FPGA	
	_fpgaDisconnected = false;

	LAST_PHONEME = 0;
	MAX_OBSTACLES_ACTIFS = 2;
}

void Platform::createScene()
{
	_scene = new QGraphicsScene();
	_view = new QGraphicsView();
	_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	_view->setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	_scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	_view->setScene(_scene);
}

void Platform::loadSounds()
{
	//background music
	_bgMusic = new QMediaPlayer();
	_bgMusic->setVolume(20);
	_bgMusic->setMedia(QUrl("sounds/backgroundmusic.mp3"));
	//collisions
	_laserCollisionSound = new QMediaPlayer();
	_laserCollisionSound->setMedia(QUrl("sounds/laserCollision.wav"));
	_laserCollisionSound->setVolume(50);
	_powerUpCollisionSound = new QMediaPlayer();
	_powerUpCollisionSound->setMedia(QUrl("sounds/powerUpCollision.wav"));
	_powerUpCollisionSound->setVolume(50);
	//gameover
	_gameOverSound = new QMediaPlayer();
	_gameOverSound->setMedia(QUrl("sounds/gameOver.wav"));
	//destroy power up 
	_destroySound = new QMediaPlayer();
	_destroySound->setMedia(QUrl("sounds/destroyPowerup.wav"));
	_destroySound->setVolume(75);
	//slow down power up
	_slowDownSound = new QMediaPlayer();
	_slowDownSound->setVolume(90);
	_slowDownSound->setMedia(QUrl("sounds/slowDownpowerup.wav"));
	timerSlowDown = new QElapsedTimer();
}

void Platform::createTexts()
{
	//FONT
	QFontDatabase::removeAllApplicationFonts();
	int id = QFontDatabase::addApplicationFont("font/Starjedi.ttf");
	QString family = QFontDatabase::applicationFontFamilies(id).first();
	starWarsFont = QFont(family);
	//PLAYER HEALTH
	_playerHealth = new Text();
	_playerHealth->setDefaultTextColor(Qt::black);
	_playerHealth->setFont(starWarsFont);
	_playerHealth->set_value(_player->get_life());
	_playerHealth->set_name("Health");
	_playerHealth->setPos(_playerHealth->x() + 10, _playerHealth->y() + 30);
	_scene->addItem(_playerHealth);
	_playerHealth->setZValue(11);
	_playerHealth->draw();
	//GAMETIMER
	_gameTime = new Text();
	_gameTime->setDefaultTextColor(Qt::black);
	_gameTime->setFont(starWarsFont);
	_gameTime->setPos(_gameTime->x() + 7, _gameTime->y() + 5);
	_gameTime->set_value(currentFrameTime / 1000);
	_gameTime->set_name("GameTime");
	_scene->addItem(_gameTime);
	_gameTime->setZValue(11);
	_gameTime->draw();
	//LEVEL
	_levelText = new Text();
	_levelText->setFont(starWarsFont);
	_levelText->set_value(_level);
	_levelText->set_name("Level");
	_levelText->setPos(_view->width() / 2 - 35, 0);
	_scene->addItem(_levelText);
	_levelText->draw();
	//CURRENT POWER UP
	currentPowerUpText = new QGraphicsTextItem();
	currentPowerUpText->setFont(QFont(family, 10));
	currentPowerUpText->setDefaultTextColor(Qt::black);
	currentPowerUpText->setPlainText("Current Powerup :");
	currentPowerUpText->setPos(SCREEN_WIDTH - 170, 0);
	currentPowerUpText->setZValue(11);
	_scene->addItem(currentPowerUpText);
}

void Platform::initializeGame()
{
	//CONTROL FOCUS ON PLAYER
	_player->setFocus();
	//SET GAMESTATE TO RUNNING
	_gameState = Running;
	//PLAY BACKGROUND MUSIC
	_bgMusic->play();
	//SHOW GAME
	_view->show();
	//INITIATE FPGA COMMUNICATION
	if (_inputMode == 0)
		initiateCommunicationFPGA();
	else
		_fpga = nullptr;
	//INITIATE TIMERS
	timerFrame->setInterval(FRAMETIME);
	timerFrame->start();
	timerElapsed->start();
}

void Platform::Update()
{
	switch (_gameState)
	{
	case NotInitialized: //DOESN'T DO ANYTHING
		return;
		break;

	case GameOver:
		//CHECKS IF GAME HASN'T BEEN INITIALIZED YET
		initializeGameOver();
		//GAMEOVER UPDATE
		if (gameoverCount!=1)
			emit gameover();
		gameoverCount = 1;
		updateGameOver();
		break;
	case Running:
		//CHECKS INPUT FOR PLAYER MOVEMENT
		checkInput();
		//CHECK FOR END OF SLOW POWERUP
		checkSlowPowerUpEnd();
		//PLAY BACKGROUND MUSIC
		_bgMusic->play();
		//CALCULATE TIME OF CURRENT FRAME
		currentFrameTime = timerElapsed->elapsed();
		//MOVES BACKGROUND
		_background->move();
		//DRAW ALL OF THE GAME TEXTS
		drawTexts();
		//ADD OBSTACLES
		addObstacles();
		//CHECKS IF GAME LEVEL UP
		checkLevelUp();
		//MOVE OBSTACLES
		moveObstacle();
		//CHECK COLLISIONS BETWEEN OBSTACLES AND PLAYER
		checkCollision();
		break;
	default:
		break;
	}
}

void Platform::initializeGameOver()
{
	if (!_gameOver)
	{
		_gameOverImage = new QGraphicsPixmapItem();
		_gameOverImage->setPixmap(QPixmap("images/gameover.png"));
		_gameOverImage->setPos(0, 0);
		_gameOverImage->setOpacity(0.00);
		_gameOverImage->setZValue(10);
		_scene->addItem(_gameOverImage);
		_gameOver = true;
	}
}

void Platform::updateGameOver()
{
	_bgMusic->setVolume(_bgMusic->volume() - 0.015);
	_gameOverImage->setOpacity(_gameOverImage->opacity() + 0.01);
	if (_bgMusic->volume() <= 0)
	{
		_gameOverSound->play();
		_bgMusic->stop();
	}
}

void Platform::checkLevelUp()
{
	if (currentFrameTime % 9900 < 20)
		_levelup = true;
	if (currentFrameTime % 10000 < 20 && _levelup)
	{
		if (currentFrameTime > 100)
		{
			_level++;
			if (currentFrameTime % 10000 < 20)
				MAX_OBSTACLES_ACTIFS++;
			_levelup = false;
		}
	}
}

void Platform::checkSlowPowerUpEnd()
{
	currentFrameTime = timerSlowDown->elapsed();
	if (_slowedDown)
	{
		slowDown();
		if (timerSlowDown->elapsed() > 5000 && _slowedDown)
		{
			_slowedDown = false;
			speedUp();
		}
	}
}

void Platform::addObstacles()
{
	if (currentFrameTime % 1000 < 15)
	{
		addToGame(vlaser);
	}

	if (currentFrameTime % 4000 < 25 && _listOfObstacles->get_longueur() > 3)
	{
		addToGame(powerUp);
	}

	if (currentFrameTime % 1100 < 15)
	{
		addToGame(hlaser);
	}
}

void Platform::moveObstacle()
{
	Obstacle* temp;
	_listOfObstacles->premier();
	temp = _listOfObstacles->get_courant();
	for (int i = 0; i < _listOfObstacles->get_longueur(); i++)
	{
		temp->update();
		if (temp->x() > SCREEN_WIDTH || temp->y() > SCREEN_HEIGHT) //OUTSIDE GAME
		{
			removeObstacle(temp);
		}
		_listOfObstacles->suivant();
		temp = _listOfObstacles->get_courant();
	}
}

void Platform::drawTexts()
{
	_gameTime->set_value((float)currentFrameTime / 1000);
	_gameTime->draw();
	_levelText->set_value(_level);
	_levelText->draw();
}

void Platform::checkInput()
{
	Direction direction;
	switch (_inputMode)
	{
	case 1:
		//KEYBOARD
		direction = checkPhoneme(LAST_PHONEME);
		_player->move(direction);
		//CHECK IF POWERUP IS USED
		if (_player->get_usePowerup())
		{
			usePowerUp();
		}
		break;
	case 0:
		//FPGA
		checkPhonemeFPGA();
		direction = checkPhoneme(LAST_PHONEME);
		_player->move(direction);
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
			_slowDownSound->play();
			_slowedDown = true;
			timerSlowDown->restart();
			timerSlowDown->start();
			break;
		case Destroy:
			clearList();
			_destroySound->play();
			break;

		default:
			break;
		}
		_currentPowerUp = nullptr;
		_currentPowerUpImage->setPixmap(QPixmap("images/noPowerUp.jpg"));
	}
	_player->set_usePowerup(false);
}

void Platform::slowDown()
{
	_listOfObstacles->premier();
	Obstacle* temp = _listOfObstacles->get_head();
	for (int i = 0; i < _listOfObstacles->get_longueur(); i++)
	{
		temp = _listOfObstacles->get_courant();
		if (temp->get_type() == powerUp)
			temp->set_speed(POWERUP_SLOWED_SPEED);
		else
			temp->set_speed(LASER_SLOWED_SPEED);
		_listOfObstacles->suivant();
	}
}

void Platform::speedUp()
{
	_listOfObstacles->premier();
	Obstacle* temp = _listOfObstacles->get_head();
	for (int i = 0; i < _listOfObstacles->get_longueur(); i++)
	{
		temp = _listOfObstacles->get_courant();
		if (temp->get_type() == powerUp)
			temp->set_speed(POWERUP_BASE_SPEED);
		else
			temp->set_speed(LASER_BASE_SPEED);
		_listOfObstacles->suivant();
	}
}
void Platform::clearList()
{
	_listOfObstacles->premier();
	Obstacle* temp = _listOfObstacles->get_head();
	_scene->removeItem(temp);
	_listOfObstacles->effacer();
	if (_listOfObstacles->get_longueur() > 0)
		clearList();
	else
		return;
}


Direction Platform::checkPhoneme(int input)
{
	switch (input)
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

void Platform::initiateCommunicationFPGA()
{
	_fpga = new CommunicationFPGA();
	if (!_fpga->estOk())
	{
		std::cout << _fpga->messageErreur() << endl;
		_fpgaDisconnected = true;
		return;
	}
	_fpgaDisconnected = false;
}

bool Platform::checkStatusFPGA()
{
	if (!_fpga->estOk())
		_fpgaDisconnected = true;
	if (_inputMode == 1)
	{
		if (_fpgaDisconnected)
		{
			_fpga = new CommunicationFPGA();
			if (_fpga->estOk())
			{
				initiateCommunicationFPGA();
				_fpgaDisconnected = false;
				return true;
			}
		}
		return false;
	}
	return true;
}

void Platform::checkPhonemeFPGA()
{
	if (_fpga == nullptr)
		return;
	if (!_fpga->lireRegistre(1, _fpgaValue))
	{
		std::cout << _fpga->messageErreur() << endl;
		return;
	}

	if (2 == (_fpgaValue & 2)){
		LAST_PHONEME = 2;
		std::cout << "FPGA BUTTON 0 : " << endl;
	}
	if (4 == (_fpgaValue & 4)){
		usePowerUp();
		std::cout << "FPGA BUTTON 1 : " << endl;
	}
	if (8 == (_fpgaValue & 8)){
		std::cout << "FPGA BUTTON 2 : " << endl;
	}
	if (1 == (_fpgaValue & 1)){
		LAST_PHONEME = 1;
		std::cout << "FPGA BUTTON 3 : " << endl;
	}
}

void Platform::checkCollision()
{
	CollisionRectangle* playerRect = new CollisionRectangle(_player->get_width(), _player->get_height(),
		_player->x(), _player->y());   //COLLISION RECTANGLE FOR PLAYER

	_listOfObstacles->premier();
	Obstacle* temp =_listOfObstacles->get_courant();
	for (int i = 0; i < _listOfObstacles->get_longueur(); i++)
	{
		CollisionRectangle* obstacleRect = new CollisionRectangle(temp->get_width(), temp->get_height(),
			temp->x(), temp->y());   //COLLISION RECTANGLE FOR OBSTACLE

		if (playerRect->checkIntersect(obstacleRect))
		{
			switch (temp->get_type())
			{
			case powerUp:
				if (_powerUpCollisionSound->state() == QMediaPlayer::PlayingState)
					_powerUpCollisionSound->setPosition(0);
				_powerUpCollisionSound->play();

				//DEEP COPIE OF CURRENT POWERUP
				if (_currentPowerUp == nullptr)
					_currentPowerUp = new PowerUp(temp);

				switch (_currentPowerUp->get_powerUpType())
				{
				case Slow:
					_currentPowerUpImage->setPixmap(QPixmap("images/slowDown.png"));
					break;
				case Destroy:
					_currentPowerUpImage->setPixmap(QPixmap("images/bomb.png"));
					break;
				default:
					break;
				}
				removeObstacle(temp);
				break;
			case hlaser:
				_player->set_life(_player->get_life() - temp->get_damage());
				_playerHealth->set_value(_player->get_life());
				_playerHealth->draw();
				//play laser sound
				if (_laserCollisionSound->state() == QMediaPlayer::PlayingState)
					_laserCollisionSound->setPosition(0);
				_laserCollisionSound->play();
				//explosion
				explosion = new Explosion();
				explosion->setPos(temp->pos());
				_scene->addItem(explosion);
				removeObstacle(temp);
				break;
			case vlaser:
				_player->set_life(_player->get_life() - temp->get_damage());
				_playerHealth->set_value(_player->get_life());
				_playerHealth->draw();
				//play laser sound
				if (_laserCollisionSound->state() == QMediaPlayer::PlayingState)
					_laserCollisionSound->setPosition(0);
				_laserCollisionSound->play();
				//explosion
				explosion = new Explosion();
				explosion->setPos(temp->pos().x(), temp->pos().y() + temp->get_height());
				_scene->addItem(explosion);
				removeObstacle(temp);
				break;
			default:
				break;
			}
		}
		delete obstacleRect;
		_listOfObstacles->suivant();  
		temp = _listOfObstacles->get_courant();

		//IF PLAYER DIES
		if (_player->get_life() <= 0)
			_gameState = GameOver;
	}
	delete playerRect;
	return;
}


void Platform::addToGame(TypeObstacle type)
{
	if (_listOfObstacles->get_longueur() == MAX_OBSTACLES_ACTIFS)
	{
		return;    //LIST FULL
	}

	Obstacle* temp;
	switch (type)
	{
	case hlaser:
		temp = new Hlaser();  
		_listOfObstacles->ajouter(temp);
		temp->spawnHorizontal();
		_scene->addItem(temp);
		temp->playSpawnSound();
		break;
	case vlaser:
		temp = new Vlaser();
		_listOfObstacles->ajouter(temp);
		temp->spawnVertical();
		_scene->addItem(temp);
		temp->playSpawnSound();
		break;
	case powerUp:
		temp = new PowerUp();
		temp->randomizeType();
		_listOfObstacles->ajouter(temp);
		temp->spawnVertical();
		_scene->addItem(temp);
		break;
	default:
		break;
	}
}

void Platform::removeObstacle(Obstacle* obstacle)
{
	if (_listOfObstacles->get_longueur() < 1)  //DOESN'T REMOVE IF LIST EMPTY
		return;

	_listOfObstacles->premier();
	Obstacle* temp = _listOfObstacles->get_courant();
	for (int i = 0; i < _listOfObstacles->get_longueur(); i++)
	{
		if (temp == obstacle) 
		{
			_scene->removeItem(temp);                     
			_listOfObstacles->effacer();           
		}
		_listOfObstacles->suivant();     
		temp = _listOfObstacles->get_courant();
	}
}


qint64 Platform::get_currentFrame()
{
	return currentFrameTime;
}


