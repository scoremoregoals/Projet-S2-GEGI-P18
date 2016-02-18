#include "platform.h"
#include "vector2.h"
#include "runner.h"
#include "obstacle.h"

#include <iostream>
#include <string>

/**

RESTE À AJOUTER
-Platform : implementation .cpp
			include liste, ajout liste a constructeur
			
-Obstacle : implementation .cpp
			apporter les modifs pour pouvoir utiliser les obstacles dans la liste (un lien vers autres obstacle, changer constructeur dans cet optique etc)
			
-Runner : implementation .cpp

-Liste :	Ajout de la liste pour contenir les obstacle (.h et .cpp, modifier celui de l'APP 3)
			Ajout includes appropriés (platform, main)

-makefile : ajout de liste, correction s'il y a lieu

-Sprites : ajout des sprites pour les multiples objets du jeu (a faire plus tard avec Qt)

-modifier le UML

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














