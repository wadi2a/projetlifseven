#ifndef _LISTE
#define _LISTE
#include "ennemi.h" // Inclus le type Elem dans le module.

struct sCellule
{
  Ennemi * en; // Champs comprenant un pointeur sur ennemi.
  struct sCellule * suivant; // pointeur sur cellule suivante.
  struct sCellule * precedent; // pointeur sur cellule precedente.

};
typedef struct sCellule Cellule;


struct sListe
{
  Cellule * prem; // Pointeur sur le premier element de la liste.
  unsigned int nb_elements; // le nombre d'éléments dans la liste.
  int nb_en;
};
typedef struct sListe Liste;


void initialise(Liste & l);
/* Precondition : l non initialisee
   Postcondition : la liste l est initialisee en tant que liste vide */

void initialise(Liste & l1, const Liste & l2);
/* Precondition : l1 non initialisee,
                  l2 prealablement initialisee et manipulee uniquement
                 a travers les operations du module
   Postcondition : la liste l1 initialisee correspond a une copie de l2
   (mais les 2 listes sont totalement independantes l'une de l'autre) */

void testament(Liste & l);
/* Precondition : l initialisee et manipulee uniquement
   a travers les operations du module
   Postcondition : l est detruite proprement en mémoire */


void ajoutEnTete(Ennemi * e,Liste & l);
/* Precondition : l et e initialises et manipules uniquement a travers les
                  operations de leurs modules respectifs
   Postcondition : e est ajoute en tete de l, et l.nb_elements est incremente  */

void suppressionEnTete(Liste & l);
/* Precondition : testListeVide(l)==false
   Postcondition : la liste l perd son premier element, et l.nb_elements est
   decremente */

void ajoutEnQueue(Ennemi * e, Liste & l);
/* Precondition : l et e initialises et manipules uniquement a travers les
                  operations de leurs modules respectifs
   Postcondition : e est ajoute en fin de la liste l, et l.nb_elements est incremente */

void suppressionEnQueue(Liste & l);
/* Precondition : testListeVide(l)==false
   Postcondition : la liste l perd son dernier element, et l.nb_elements est
   decremente */

bool estVide(const Liste & l);
/* Precondition : l prealablement initialisee et manipulee uniquement
                  a travers les operations du module
   Resultat : true si l est vide, false sinon */

#endif
