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
	Platform();
	virtual ~Platform();

	void effacerObstacle(Obstacle* obstacle);
	Direction checkPhoneme(int input);
	void checkCollision();
	void initialize();
	void usePowerUp();
	void clearListe();

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
	PowerUp* _currentPowerUp;
	Runner* _player;
	GameState _gameState;
	Liste* _listeObstaclesActifs;
	QGraphicsScene* _scene;
	QGraphicsView* _view;
	QGraphicsPixmapItem* _gameOverImage;
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
	qint64 currentFrameTime;
	qint64 totalPauseTime;
	qint64 timeSinceLastPause;
	qint64 pauseTime;

	//texts
	Text* _playerHealth;
	Text* _gameTime;
	Text* _levelText;
};

#endif //PLATFORM_H
