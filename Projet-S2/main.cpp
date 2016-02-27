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
#include "mainwindow.h"
#include <QApplication>


using namespace std;

void Update(Platform& platform, int input)
{
	platform.Update(input);
}

void Draw(Platform& platform)
{

}


int main(int argc, char *argv[])
{ 
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	//Initiate player, platform, list, validspawn pour spawn obstacles
	//ex. platform de 100x100

	//liste of IDs
	ObstacleID* id[MAX_OBSTACLES_ACTIFS];
	for (int i = 0; i < MAX_OBSTACLES_ACTIFS; i++)
	{
		id[i] = new ObstacleID(i, false);
	}

	srand(time(NULL));

	Runner player(new Vector2(50,100), 100, 10, 10, 10);
	//list<Obstacle*> liste;
	Liste liste;

	Vector2* verticalValidSpawn[5];
	verticalValidSpawn[0] = new Vector2(10, 0);
	verticalValidSpawn[1] = new Vector2(30, 0);
	verticalValidSpawn[2] = new Vector2(50, 0);
	verticalValidSpawn[3] = new Vector2(70, 0);
	verticalValidSpawn[4] = new Vector2(90, 0);

	Vector2* horizontalValidSpawn[5];
	horizontalValidSpawn[0] = new Vector2(0, 10);
	horizontalValidSpawn[1] = new Vector2(0, 30);
	horizontalValidSpawn[2] = new Vector2(0, 50);
	horizontalValidSpawn[3] = new Vector2(0, 70);
	horizontalValidSpawn[4] = new Vector2(0, 90);

	Platform platform(player, liste, id, verticalValidSpawn, horizontalValidSpawn);

	//ajouter 4 objets differents au jeu
	platform.ajouterAuJeu(hlaser);
	platform.ajouterAuJeu(vlaser);
	platform.ajouterAuJeu(powerUp);
	platform.ajouterAuJeu(powerUp);

	//afficher valeurs initiales
	platform.get_player()->afficherDetails();
	Obstacle* temp = platform.get_listeObstaclesActifs()->get_head();
	cout << "valeurs initiales : " << endl;
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
		//User input 1->haut, 2->bas, 3->gauche, 4->droite
		cout << "User Input : ";
		cin >> userInput;
		cout << endl;

		//TEST AJOUT D'OBSTACLES
		if (userInput == 4)
		{
			platform.ajouterAuJeu(hlaser);
			platform.ajouterAuJeu(powerUp);
		}
		Update(platform, userInput);
		platform.effacerObstacle(platform.get_listeObstaclesActifs()->get_courant());

		//Draw frame
		Draw(platform);

	} while (userInput != 5);

	return a.exec();
}

















