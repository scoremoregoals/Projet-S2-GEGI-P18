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

int main()
{ 
	return 0;
}
















