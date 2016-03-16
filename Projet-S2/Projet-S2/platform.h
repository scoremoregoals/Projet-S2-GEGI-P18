#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
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

using namespace std;

enum GameState
{
	NotInitialized,
	Running,
	Paused
};

class Platform : public QObject
{
	Q_OBJECT
public:
	Platform();
	Platform(Runner * player, Liste& liste);// ObstacleID* id[MAX_OBSTACLES_ACTIFS]);
	virtual ~Platform();

	void effacerObstacle(Obstacle* obstacle);
	Direction checkPhoneme(int input);
	void checkCollision();
	void initialize();

	//getters
	Runner* get_player() { return _player; }
	Liste* get_listeObstaclesActifs() { return _listeObstaclesActifs; }
	QGraphicsView* get_view() { return _view; }

public slots:
	void Update();
	void ajouterAuJeu(TypeObstacle type);

private:
	Runner* _player;
	int _level;
	bool _isPaused;
	bool _gameRunning;
	GameState _gameState;
	Liste* _listeObstaclesActifs;
	QGraphicsScene* _scene;
	QTimer* timerFrame;
	QElapsedTimer* timerElapsed;
	QGraphicsView* _view;
	qint64 currentFrameTime;
	qint64 lastFrameTime;
	qint64 timeSinceLastFrame;
	Text* _playerHealth;
	Text* _gameTime;
};

#endif //PLATFORM_H
