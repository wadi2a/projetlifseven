/**
 * \file bombe.h
 * \brief Déclarations des types et fonctions pour l'utilisation d'une Bombe au cours d'une partie de Bomberman.
 *
 * Ce fichier d'en-tête permet la gestion d'une bombe au cours d'une partie. La gestion de l'explosion avec disparition des murs
 * ainsi que le test de l'état d'une case avant de poser une Bombe (on peut poser une bombe que sur une case vide).
 */
#ifndef _Bombe
#define _Bombe
#include "terrain.h"
#include <time.h>

struct sBombe
{
    int x;
    int y;
    int r_exp;
    int temps;
    int nb;
};
typedef struct sBombe Bombe;

/**
@brief Initialise une Bombe.
@return Un pointeur sur Bombe qui pointe en mémoire sur la Bombe initialisée

Cette fonction qui ne prend pas de paramètres, affecte en mémoire dynamique une bombe. Cette bombe ne possède pour le
moment aucune coordonnées relative au Terrain.
*/
Bombe * Bombe_InitialisationBombe();

/**
@brief Teste si on peut poser une Bombe à une certaine coordonnée.
@param b un pointeur sur Bombe
@param posx un entier en donnée
@param posy un entier en donnée
@param t un Terrain en donnée/résultat
@param rayon un entier en donnée
@return un Booléen

Cette fonction prend en paramètre un pointeur sur Bombe et les coordonnées où on veut poser la Bombe. Cette fonction va tester
si on peut poser la bombe aux coordonnées (posx,posy).C'est à dire si les coordonnées existent et si la case est vide ou "V".
Si oui, elle affecte à la bombe les coordonnées en paramètre, son rayon d'explosion et renvoit True. Sinon elle renvoit False.

*/
bool Bombe_posebombe(Bombe * b, const int &posx, const int &posy, Terrain &t, const int &rayon);

/**
@brief Explosion des murs autour d'une bombe.
@param b un pointeur sur Bombe en donnée
@param t un Terrain en donnée/résultat

Cette fonction change l'état des cases à l'état mur ou "M", qui se trouvent dans le rayon d'explosion horizontalement et verticalement
par rapport à la Bombe. Ces cases passent à l'état vide ou "V".

*/
void Bombe_ExplosionSurTerrain(const Bombe * b,Terrain &t);

/**
@brief Pose une bombe aux coordonnées données si c'est possible
@param b un pointeur sur Bombe
@param t un Terrain en donnée/résultat
@param posx un entier en donnée
@param posy un entier en donnée
@param time un entier en donnée
@return un Booléen

Cette fonction prend en paramètre un pointeur sur Bombe et les coordonnées où on veut poser la Bombe. Elle appelle la fonction Bombe_posebome,
si le résultat est True, elle modifie l'état de la Case où la bombe est posée (état "B"), et affecte l'heure où est posé la bombe dans le champs
temps de la Bombe, afin de calculer le temps d'explosion. Elle renvoir True si la bombe est posée, False sinon.

*/
bool Bombe_bombe(Bombe * b, Terrain &t, const int &x, const int &y,const int &time);

/**
@brief Libère proprement en mémoire dynamique la Bombe.
@param b un pointeur sur Bombe

Cette fonction va libérer proprement dans la mémoire dynamique la Bombe en utilisant le pointeur sur Bombe fournis.
*/
void Bombe_testament(Bombe *b);
#endif
