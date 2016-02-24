#include "liste.h"


Liste::Liste()
{
   p_courant = NULL; 
   p_head = NULL;
   p_dernier = NULL;
   p_longueur = 0;
}

Liste::~Liste()
{}



void Liste::ajouter(Objet& objet)                 ///< ajouter un element la liste (cree un objet et l'ajoute à la tete)
{
   objet.set_lien(p_head);
   p_head = &objet;
   p_courant = &objet;
   if (p_longueur == 0)
      p_dernier = &objet;
   p_longueur ++;  
}

void Liste::suivant()               ///< le courant avance de un element dans la liste
{
   if (p_longueur < 2)
   {
      //cout << "Seulement 0 ou 1 element, pas de suivant" << endl;       ///< traces pour deboguage
      return;
   }
   if (p_courant == p_dernier)
   {
      //cout << "Bout de la liste" << endl;               ///< traces pour deboguage
      return;
   }

   p_courant = p_courant->get_lien();
   return;
}

int Liste::precedent()                        ///< le courant recule de un element dans la liste
{
   if (p_longueur == 0)
   {
      //cout << "Liste vide, pas de precedent" << endl;         ///< traces pour deboguage
      return 1;
   }
   if (p_longueur > 0 && p_courant == p_head)
   {
      //cout << "Debut de la liste" << endl;             ///< traces pour deboguage
      return 2;
   }
   
   Objet* temp = p_head;
   int compteur = 0;
   while (temp->get_lien() != NULL && compteur < p_longueur)
   {
      if (temp->get_lien() == p_courant)
      {
         p_courant = temp;
         return 0;
      }
      compteur++;
      temp = temp->get_lien();
   }
   return -1;
}

void Liste::premier()               ///< l'element courant devient le premier de la liste
{
   if (p_head == NULL)
   {
      cout << "plat->head est null" << endl;
      return;
   }
   if (p_longueur > 0)
   {
      p_courant = p_head;
      return;
   }
   else
   {
      cout << "Liste vide, pas de premier" << endl;
   }
}

void Liste::dernier()                          ///< l'element courant devient le dernier de la liste
{
   if (p_dernier == NULL)
   {
      cout << "plat->dernier est null" << endl;
      return;
   }
   if (p_longueur > 0)
   {
      p_courant = p_dernier;
      return;
   }
   else
   {
      cout << "Liste vide, pas de dernier" << endl;
   }
}


void Liste::effacer()                                 ///< efface l'element courant de la liste
{
   //precedent() =>> 0 = worked, 1 = Vide, 2 = debut, -1 = erreur
   Objet* temp = p_courant;

   if (p_courant == p_dernier)
   {
      int resultat = precedent();
      //Liste de plus de 1 element
      if (resultat == 0)
      {
         p_courant->set_lien(NULL);
         delete temp;
         temp = NULL;
         p_longueur--;
         p_dernier = p_courant;
      }
      //Liste Vide
      else if (resultat ==  1)
      {
         cout << "Rien a effacer, Liste vide" << endl;
      }
      //Juste 1 element, la liste devient vide
      else if(resultat == 2)
      {
         p_head = NULL;
         delete temp;
         temp = NULL;
         p_courant = NULL;
         p_dernier = NULL;
         p_longueur--;
      }
      else
         cout << "Erreur dans precedent()" << endl;
   }
   else
   {
      int resultat = precedent();
      if (resultat == 0)
      {
         p_courant->set_lien(temp->get_lien());
         delete temp;
         p_longueur--;
      }
      else if (resultat ==  1)
      {
         cout << "Rien a effacer, Liste vide" << endl;
      }
      else if (resultat == 2)
      {
         p_head = p_courant->get_lien();
         delete p_courant;
         p_courant = p_head;
         p_longueur--;
      }
      else
         cout << "Erreur dans precedent()" << endl;
   }  
}

void Liste::set_courant(Objet* objet)          ///< fixer l'element courant
{
   p_courant = objet;
}

void Liste::set_head(Objet* objet)         ///< fixer la tete de la liste
{
   p_head = objet;
}

int Liste::get_longueur() const                 ///< obtenir la longueur de la liste
{
   return p_longueur;
}

Objet* Liste::get_courant() const                ///< obtenir l element courant
{
   if (p_courant == NULL)
   {
      cout << "plat->courant est null" << endl;
      return NULL;
   }
   else
      return p_courant;
}
 
Objet* Liste::get_head() const                 ///< obtenir la tete de la liste
{
   if (p_head == NULL)
   {
      cout << "plat->head est null" << endl;
      return NULL;
   }
   else
      return p_head;
}

Objet* Liste::get_dernier() const         ///< obtenir le dernier element
{
   if (p_dernier == NULL)
   {
      cout << "plat->dernier est null" << endl;
      return NULL;
   }
   else
      return p_dernier;
}

