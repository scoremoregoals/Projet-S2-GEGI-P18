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
#include "vector2.h"
#include "rectangle.h"
#include <list>
#include "liste.h"
#include "id.h"
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
	void effacerObstacle(Obstacle* obstacle);
	/**
	 * @brief      Change the direction with the received input(FPGA)
	 *
	 * @param[in]  input  The value of the FPGA
	 *
	 * @return     The new Direction of the runner
	 */
	Direction checkPhoneme(int input);
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
	void clearListe();
	/**
	 * @brief      Slow the obstacle speed
	 */
	void slowDown();
	/**
	 * @brief      Speed up the obstacle speed
	 */
	void speedUp();

	//getters
	Runner* get_player() { return _player; }
	Liste* get_listeObstaclesActifs() { return _listeObstaclesActifs; }
	QGraphicsView* get_view() { return _view; }

public slots:
	void Update();
	void ajouterAuJeu(TypeObstacle type);

private:
	int _level;
	bool _levelup;
	bool _gameOver;
	bool _slowedDown;
	PowerUp* _currentPowerUp;
	Runner* _player;
	GameState _gameState;
	Liste* _listeObstaclesActifs;
	QGraphicsScene* _scene;
	QGraphicsView* _view;
	QGraphicsPixmapItem* _gameOverImage;
	QGraphicsPixmapItem* _currentPowerUpImage;
	BackGround* _background;

	//sounds
	QMediaPlayer* _bgMusic;
	QMediaPlayer* _laserCollisionSound;
	QMediaPlayer* _powerUpCollisionSound;
	QMediaPlayer* _gameOverSound;
	QMediaPlayer* _destroySound;
	QMediaPlayer* _slowDownSound;

	//time
	QTimer* timerFrame;
	QElapsedTimer* timerElapsed;
	QElapsedTimer* timerSlowDown;
	qint64 currentFrameTime;
	qint64 totalPauseTime;
	qint64 timeSinceLastPause;
	qint64 pauseTime;

	//texts
	Text* _playerHealth;
	Text* _gameTime;
	Text* _levelText;
	QGraphicsTextItem* currentPowerUpText;
};

#endif //PLATFORM_H
