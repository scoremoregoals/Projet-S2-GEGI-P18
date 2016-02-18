#include "platform.h"
#include "vector2.h"
#include "runner.h"
#include "obstacle.h"
#include "liste.h"

#include <iostream>
#include <string>

/**

RESTE À AJOUTER			
			
-Runner : implementation dans  .cpp

-makefile : correction s'il y a lieu

-Sprites : ajout des sprites pour les multiples objets du jeu (a faire plus tard avec Qt)

-modifier le UML

DERNIER CHANGEMENTS: liste, makefile, lien entre obstacle et liste, platform et liste (include et constructor.
**/


using namespace std;


int main()
{ 
	//TESTS
	Vector2 vector(1,2);
	Runner player(vector, 1,1);
	cout << "player pos : " << player.get_position()->get_positionX() << endl;
	
	Vector2* valid[4];
	valid[0] = new Vector2(6,2);
	valid[1] = new Vector2(2,2);
	valid[2] = new Vector2(3,2);
	valid[3] = new Vector2(4,2);
	
	Obstacle obstacle(1, 2, 3, 4, 5, valid);
	cout << valid[0]->get_positionX() << endl;
	cout << valid[1]->get_positionX() << endl;
	cout << valid[2]->get_positionX() << endl;
	cout << valid[3]->get_positionX() << endl;
	obstacle.spawn();
	cout << "obstacle pos : " << obstacle.get_position()->get_positionX() << endl;
	
	
	return 0;
}














