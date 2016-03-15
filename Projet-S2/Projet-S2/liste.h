#ifndef LISTE_H
#define LISTE_H

#include <iostream>
#include <string>
#include <iomanip>

#include "obstacle.h"

using namespace std;


typedef Obstacle Objet;

/// Determine une liste d'obstacle choisis 
/** \class Liste
Determine un liste...
Permet d'initialiser une liste et de faire des operations sur ses elements
*/

class Liste
{
public:
	Liste();                   ///< Constructeur de base
	~Liste();                  ///< Destructeur
	void ajouter(Obstacle* obstacle);            ///< ajouter un element la liste (cree un objet et l'ajoute à la tete)
	void suivant();            ///< le courant avance de un element dans la liste
	int precedent();            ///< le courant recule de un element dans la liste
	void premier();           ///< l'element courant devient le premier de la liste
	void dernier();           ///< l'element courant devient le dernier de la liste
	void effacer();             ///< efface l'element courant de la liste

	void set_courant(Objet* objet);          ///< fixer l'element courant
	void set_head(Objet* objet);             ///< fixer la tete de la liste
	int get_longueur() const;               /// obtenir la longueur de la liste
	Objet* get_dernier() const;                     ///< obtenir le dernier element
	Objet* get_courant() const;                    ///< obtenir l'element courant
	Objet* get_head() const;                       ///< obtenir la tete de la liste

private:
	Objet* p_courant;
	Objet* p_head;
	Objet* p_dernier;
	int p_longueur;
};

#endif