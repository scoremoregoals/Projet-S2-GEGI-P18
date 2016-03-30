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

#include "obstacle.h"
#include "runner.h"
#include "rectangle.h"
#include "liste.h"
#include "Hlaser.h"
#include "Vlaser.h"
#include "powerUp.h"
#include "global.h"
#include "Text.h"
#include "animation.h"
#include "background.h"

using namespace std;

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
	 * @param[in]  input  The value of the FPGA
	 *
	 * @return     The new Direction of the runner
	 */
	Direction checkPhoneme(int input);
	Direction checkPhonemeFPGA();
	void checkInput();
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
	void initialize();

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
	Runner* _player;
	GameState _gameState;
	Liste* _listOfObstacles;
	QGraphicsScene* _scene;
	QGraphicsView* _view;
	QGraphicsPixmapItem* _gameOverImage;
	PowerUp* _currentPowerUp;
	QGraphicsPixmapItem* _currentPowerUpImage;
	BackGround* _background;

	//sounds
	QMediaPlayer* _bgMusic;
	QMediaPlayer* _laserCollisionSound;
	QMediaPlayer* _powerUpCollisionSound;
	QMediaPlayer* _gameOverSound;
	QMediaPlayer* _destroySound;
	QMediaPlayer* _slowDownSound;

	//timers
	QTimer* timerFrame;
	QElapsedTimer* timerElapsed;
	QElapsedTimer* timerSlowDown;
	qint64 currentFrameTime;

	//texts
	Text* _playerHealth;
	Text* _gameTime;
	Text* _levelText;
	QGraphicsTextItem* currentPowerUpText;
};

#endif //PLATFORM_H
