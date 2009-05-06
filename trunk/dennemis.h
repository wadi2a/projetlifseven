#ifndef _desEnnemi
#define _desEnnemi
#include "ennemi.h"
#include "liste.h"

struct sdEnnemi {
    Liste liste_en;
    int time;
};typedef struct sdEnnemi dEnnemi;

void dEnnemi_Initialisation(dEnnemi & e, const Terrain &t, const int & nb);
// Initilialise la liste et rajoute le nombre d'ennemis en les affectant sur le terrain. nb >=1

void dEnnemi_SupprimeEnnemi(dEnnemi & e, Ennemi * m);
// Supprime l'ennemi m s'il est égal à m donné en paramètre. Suppression propore en mémoire

void dEnnemi_Testament(dEnnemi & e);
// Supprime proprement en mémoire la liste d'ennemis

void dEnnemi_Mouvement(dEnnemi & e, const Terrain &t);
// Effectue les mouvements sur l'ensemble des ennemis du terrain

void dEnnemi_PresenceSurBombe(dEnnemi & e, Bombe * b, const Terrain &t);
// Teste si l'ensemble des ennemis sont present a coté de l'explosion d'une bombe. Si oui perte de vie.

int * dEnnemi_GetPosition(dEnnemi & e);
// Renvois un tableau de taille 2*nb_ennemis contenant x et y pour chaque ennemis dans l'ordre de la liste

char * dEnnemi_GetDirection(dEnnemi & e);


#endif
