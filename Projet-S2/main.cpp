#include "platform.h"
#include "vector2.h"
#include "runner.h"
#include "obstacle.h"
#include "Hlaser.h"
#include "Vlaser.h"
#include "powerUp.h"
#include "id.h"

#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime> 
#include <list>
#include "mainwindow.h"
#include <QApplication>


using namespace std;


void Update(Platform& platform, int input)
{
	platform.Update(input);
}

void Draw(Platform& platform)
{
	//draw background
	//draw obstacles
	//draw player
}


int main(int argc, char *argv[])
{ 
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	
	//Initiate player, platform, list, validspawn pour spawn obstacles
	//ex. platform de 100x100, dimension dans obstacle.h

	//liste of IDs
	ObstacleID* id[MAX_OBSTACLES_ACTIFS];
	for (int i = 0; i < MAX_OBSTACLES_ACTIFS; i++)
	{
		id[i] = new ObstacleID(i, false);
	}

	srand(time(NULL));

	Runner player(new Vector2(0,0), 100, 10, 10, 10);
	player.set_position(new Vector2(SCREEN_WIDTH / 2 - player.get_width() / 2, SCREEN_HEIGHT - player.get_height()));
	Liste liste;
	Platform platform(player, liste, id);

	//ajouter 4 objets differents au jeu
	platform.ajouterAuJeu(hlaser);
	platform.ajouterAuJeu(vlaser);
	platform.ajouterAuJeu(powerUp);
	platform.ajouterAuJeu(powerUp);

	//afficher valeurs initiales
	cout << "valeurs initiales : " << endl;
	platform.get_player()->afficherDetails();
	Obstacle* temp = platform.get_listeObstaclesActifs()->get_head();
	for (int i = 0; i < platform.get_listeObstaclesActifs()->get_longueur(); i++)
	{
		temp->afficherDetails();
		platform.get_listeObstaclesActifs()->suivant();
		temp = platform.get_listeObstaclesActifs()->get_courant();
	}

	//debut game loop
	int userInput;
	do
	{
		cout << endl;
		//User input 1->haut, 2->bas, 3->gauche, 4->droite
		cout << "User Input : ";
		cin >> userInput;

		//TEST AJOUT D'OBSTACLES
		if (userInput == 4)
		{
			platform.ajouterAuJeu(hlaser);
			platform.ajouterAuJeu(powerUp);
		}
		Update(platform, userInput);
		//TEST EFFACE OBSTACLE
		//platform.effacerObstacle(platform.get_listeObstaclesActifs()->get_courant());

		//Draw frame
		Draw(platform);

	} while (userInput != 5);
	return a.exec();
}

















