#include "platform.h"
#include "vector2.h"
#include "runner.h"
#include "obstacle.h"
#include "Hlaser.h"
#include "Vlaser.h"
#include "powerUp.h"

#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime> 
#include <list>

/**

RESTE À AJOUTER			

-Sprites : ajout des sprites pour les multiples objets du jeu (a faire plus tard avec Qt)

-LOGIQUE DU JEU
	GAMELOOP -> ajouter aussi des fonctions Update() pour joueur/Obstacle qui update position vie, etc a chaque frame
	la position (0,0) est le coin superieur gauche
	logique pour le mouvement des obstacles/joueur (par rapport aux positions, "cases de jeu")
	-soit on drop l'idee des cases de jeu, ce qui fait que chaque obstacles/joueur aurait une position qui, a chaque frame, selon le mouvement demandé, 
		serait modifiée en x ou en y (augmentée ou diminuée) selon le speed. Le speed representerait de combien de pixels on fait avancer tel objet dans
		un mouvement.
		
	collisions entre obstacles et joueur
	fonctions runner::move(), platform::moveObtacles()
	inputs pour controler le jeu (mouvements, etc)
	
- Obstacles:
	Ajout des differents obstacles du jeu qui herite de Obstacle
	Lorsque c'est fait, enlever le constructeur de Obstacle, puisque c'est une classe abstract et on ne fait pas d'objet de cette classe
	
	

-modifier le UML

DERNIER CHANGEMENTS: -Debut de la fonction check collision, ajout d'une classe rectangle qui represente les rectangle de collision des objets du jeu
					-ajout d'un attribut TypeObstacle (enum) dans Obstacle qui permet a la fonction collision de savoir quel type d'obstacle est rencontré et faire
						les actions par conséquent
					 -Debut des fonctions Updates() qui sont appeler a chaque frame pour joueur/obstacle
					
					
**/


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
	//Initiate player, platform, list, validspawn pour spawn obstacles
	//ex. platform de 100x100
	Runner player(new Vector2(50,100), 100, 10, 10, 10);
	list<Obstacle*> liste;
	Platform platform(player, liste);

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

	//Creer moules obstacles, contucteur d'Obstacle car classes filles non impl�ment�s (laser, powerup)
	Obstacle* hLaser = new Obstacle(5, 3, 1, 1, 10, hlaser, horizontalValidSpawn);
	Obstacle* vLaser = new Obstacle(5, 10, 30, 2, 10, vlaser, verticalValidSpawn);
	Obstacle* powerUp1 = new Obstacle(5, 2, 2, 3, 0, powerUp, verticalValidSpawn);
	Obstacle* powerUp2 = new Obstacle(5, 2, 2, 4, 0, powerUp, verticalValidSpawn);

	//ajouter au tableau d'obstacle
	platform.creerObstacle(hLaser);
	platform.creerObstacle(vLaser);
	platform.creerObstacle(powerUp1);
	platform.creerObstacle(powerUp2);

	//ajouter 4 objets differents au jeu
	platform.ajouterAuJeu(0);
	platform.ajouterAuJeu(1);
	platform.ajouterAuJeu(2);
	platform.ajouterAuJeu(3);

	//debut game loop
	int userInput;
	do
	{
		//User input 1->haut, 2->bas, 3->gauche, 4->droite
		cout << "User Input : ";
		cin >> userInput;
		cout << endl;

		//Update frame
		Update(platform, userInput);

		//Draw frame
		Draw(platform);

	} while (userInput != 5);
	return 0;
}

















