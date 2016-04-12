#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QMediaPlayer>
#include <QKeyEvent>
#include <QObject>
#include <QList>
#include <QElapsedTimer>
#include <QtWidgets>
#include <QFontDataBase>

#include "Headers/obstacle.h"
#include "Headers/runner.h"
#include "Headers/liste.h"
#include "Headers/Hlaser.h"
#include "Headers/Vlaser.h"
#include "Headers/powerUp.h"
#include "Headers/global.h"
#include "Headers/Text.h"
#include "Headers/animation.h"
#include "Headers/background.h"
#include "CommunicationFPGA.h"
#include "Headers/rectangle.h"
#include "Headers/explosion.h"

enum GameState
{
	NotInitialized,
	Running,
	Paused,
	GameOver
};

class Platform : public QObject
{
	Q_OBJECT
public:
	/**
	 * @brief      Initialize all the attribute of the class... and much more
	 */
	Platform();

	/**
	 * @brief      Deconstructor
	 */
	virtual ~Platform();

	/**
	* @brief      creates game scene and view in QGraphics and initiates them
	*/
	void createScene();

	/**
	* @brief      initializes game settings (platform attributes)
	*/
	void initializeSettings();
	/**
	* @brief      creates player, list of obstacles, current power up section and initiates them
	*/
	void createObjects();

	/**
	* @brief      load game sounds from ressources
	*/
	void loadSounds();

	/**
	* @brief      create text Objects
	*/
	void createTexts();

	/**
	 * @brief      Remove an obstacle
	 *
	 * @param      obstacle  To object to remove
	 */
	void removeObstacle(Obstacle* obstacle);

	/**
	* @brief      add obstacle to the game relative to the gametime
	*/
	void Platform::addObstacles();

	/**
	 * @brief      Change the direction with the received input(FPGA)
	 *
	 * @param[in]  input  The value of the FPGA or KEYBOARD
	 *
	 * @return     The new Direction of the runner
	 */
	Direction checkPhoneme(int input);

	/**
	* @brief      gathers input from fpga and changes LAST_PHONEME
	*/
	void checkPhonemeFPGA();

	/**
	* @brief      checks input according to selected input method
	*/
	void checkInput();

	/**
	* @brief      checks if fpga is disconnected
	*/
	bool checkStatusFPGA();

	/**
	* @brief      initiate communication with fpga and checks status
	*/
	void initiateCommunicationFPGA();
	/**
	* @brief      checks if slow power up used by the player should end (5 seconds)
	*/
	void checkSlowPowerUpEnd();

	/**
	* @brief      Draw the texts on the screen (gametime, player health)
	*/
	void drawTexts();

	/**
	* @brief      Move the obstacles active in the game
	*/
	void moveObstacle();

	/**
	* @brief      checks if 10 seconds has passed and level up
	*			  adds 1 to max obstacles each level
	*/
	void checkLevelUp();

	/**
	 * @brief      Look if the runner collide with something
	 */
	void checkCollision();

	/**
	 * @brief      Start frame time, music and focus window
	 */
	void initializeGame();

	/**
	 * @brief      Activate the power up
	 */
	void usePowerUp();

	/**
	 * @brief      Clear the current obstacle list
	 */
	void clearList();
	/**
	 * @brief      Slow the obstacle speed
	 */
	void slowDown();
	/**
	 * @brief      Speed up the obstacle speed
	 */
	void speedUp();

	/**
	* @brief      Set input method for controls (in interface -> comboBox)
	*/
	void set_inputMode(int mode) { _inputMode = mode; }

	/**
	* @brief      Change the direction with the received input(FPGA)
	*
	* @param[in]  type of the obstacle to add
	*/
	void addToGame(TypeObstacle type);

	/**
	* @brief      Initializes settings for gamestate Gameover
	*/
	void initializeGameOver();

	/**
	* @brief      Updates sounds and animation for gameover scene
	*/
	void updateGameOver();

	
	qint64 get_currentFrame();

	QGraphicsView* get_view() { return _view; }
	
signals:
	void gameover();

public slots:
	/**
	* @brief      Updates the game each FRAMETIME 
	*/
	void Update();



private:
	int _level;
	bool _levelup;
	bool _gameOver;
	bool _slowedDown;
	int _inputMode;
	int _fpgaValue;
	bool _fpgaDisconnected;
	int gameoverCount;

	//OBJECTS
	Runner* _player;
	GameState _gameState;
	Liste* _listOfObstacles;
	QGraphicsScene* _scene;
	QGraphicsView* _view;
	QGraphicsPixmapItem* _gameOverImage;
	QGraphicsPixmapItem* _scoreHUD;
	QGraphicsPixmapItem* _currentPowerHUD;
	PowerUp* _currentPowerUp;
	BackGround* _background;
	CommunicationFPGA* _fpga;
	Explosion* explosion;

	//CURRENT POWERUP
	QGraphicsPixmapItem* _currentPowerUpImage;
	QGraphicsPixmapItem* _powerUpRect;

	//TEXTURES
	QPixmap _vLaserTexture;
	QPixmap _hLaserTexture;
	QPixmap _slowPowerUpTexture;
	QPixmap _destroyPowerUpTexture;
	QPixmap _playerTexture;
	QPixmap _backgroundTexture;
	QPixmap _gameOverTexture;
	QPixmap _noPowerUpTexture;

	//SOUNDS
	QMediaPlayer* _bgMusic;
	QMediaPlayer* _laserCollisionSound;
	QMediaPlayer* _powerUpCollisionSound;
	QMediaPlayer* _gameOverSound;
	QMediaPlayer* _destroySound;
	QMediaPlayer* _slowDownSound;

	//TIMERS
	QTimer* timerFrame;
	QElapsedTimer* timerElapsed;
	QElapsedTimer* timerSlowDown;
	qint64 currentFrameTime;

	//TEXTS
	Text* _playerHealth;
	Text* _gameTime;
	Text* _levelText;
	QGraphicsTextItem* currentPowerUpText;
	QFont starWarsFont;

	
};

#endif //PLATFORM_H
