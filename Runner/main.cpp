#include "platform.h"
#include "vector2.h"
#include "runner.h"
#include "obstacle.h"
#include "liste.h"

#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime> 

/**

RESTE À AJOUTER			

-Sprites : ajout des sprites pour les multiples objets du jeu (a faire plus tard avec Qt)

-LOGIQUE DU JEU
	logique pour le mouvement des obstacles/joueur (par rapport aux positions, "cases de jeu")
	collisions entre obstacles et joueur
	fonctions runner::move(), platform::moveObtacles()
	inputs pour controler le jeu (mouvements, etc
	boucle de jeu
	
- Obstacles:
	Ajout des differents obstacles du jeu qui herite de Obstacle
	
	

-modifier le UML

DERNIER CHANGEMENTS: Completer lien entre liste et les obstacles de la plateform
					la liste contient les obstacles qui sont actifs et un tableau dans plateform contient les "moules"
**/


using namespace std;

int main()
{ 	
	//TESTS
	srand((unsigned)time(0)); 
	Vector2* positions[MAX_POSITIONS];
	for (int i = 0; i < MAX_POSITIONS; i++)
	{
		positions[i] = new Vector2(i, i);
	}
	
	Vector2* validSpawn[MAX_VALIDSPAWN];
	for (int i = 0, j = MAX_POSITIONS-1; i < MAX_VALIDSPAWN, j > (MAX_POSITIONS - MAX_VALIDSPAWN) -1; i++, j--)
	{
		validSpawn[i] = positions[j];
	}
	
	Runner player;
	Liste liste;
	Platform platform(player, 1, positions, liste);
	Obstacle obstacle1(1,2,3,1,5, validSpawn);
	Obstacle obstacle2(1,2,3,2,5, validSpawn);
	Obstacle obstacle3(1,2,3,3,5, validSpawn);
	Obstacle obstacle4(1,2,3,4,5, validSpawn);
	platform.creerObstacle(obstacle1);
	platform.creerObstacle(obstacle2);
	platform.creerObstacle(obstacle3);
	platform.creerObstacle(obstacle4);
	
	platform.ajouterAuJeu(obstacle4);
	platform.ajouterAuJeu(obstacle3);
	platform.ajouterAuJeu(obstacle2);
	platform.ajouterAuJeu(obstacle1);
	
	cout << "id : " << platform.get_listeObstacles()->get_courant()->get_ID() << endl;
	platform.get_listeObstacles()->suivant();
	cout << "id : " << platform.get_listeObstacles()->get_courant()->get_ID() << endl;
	platform.get_listeObstacles()->suivant();
	cout << "id : " << platform.get_listeObstacles()->get_courant()->get_ID() << endl;
	platform.get_listeObstacles()->suivant();
	cout << "id : " << platform.get_listeObstacles()->get_courant()->get_ID() << endl;
	platform.get_listeObstacles()->suivant();
	cout << "id : " << platform.get_listeObstacles()->get_courant()->get_ID() << endl;
	platform.get_listeObstacles()->suivant();
	return 0;
}
















