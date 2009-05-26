/**
 * \file terrain.h
 * \brief Déclarations des types et fonctions pour l'utilisation d'un Terrain au cours d'une partie de Bomberman.
 *
 * Ce fichier d'en-tête permet la gestion d'un Terrain : Initilisation à vide (ensemble des cases sont vides), affectation
 * aléatoire des murs solides et murs.
 */
#ifndef _Terrain
#define _Terrain
#include "case.h"


struct sTerrain
{
     int dim;
     Case *plateau;

};
typedef struct sTerrain Terrain;

/**
@brief Fonction d'initialisation d'un terrain affectant les cases à vide.
@param t un Terrain en donnée/résultat non initialisé.

Cette fonction affecte en mémoire dynamique un tableau de case d'une dimension 15, puis initialise l'ensemble des cases du terrain à l'état vide.
Le champ dimension du terrain est initialisé à 15.
*/
void Terrain_initialisation(Terrain & t);

/**
@brief Fonction d'affectation aléatoire des états mur et mur solide.
@param t un Terrain en donnée/résultat initialisé.

Cette fonction place de manière aléatoire les murs que le Bomberman peut exploser, et place les murs solides sur les positions x=y(+-)2
sauf la position (0,0).
*/
void Terrain_affectationaleatoire(Terrain &t);

/**
@brief Fonction de libération propre d'un Terrain en mémoire dynamique.
@param t un Terrain en donnée/résultat initialisé.

Cette fonction libère proprement en mémoire le Terrain qui est préablement initialisé.
*/
void Terrain_testament(Terrain &t);

/**
@brief Fonction d'acquisition d'une case à partir d'un Terrain
@param t un Terrain en donnée/résultat non initialisée.
@param  posx un entier en donnée.
@param  posy un entier en donnée.
@return Un pointeur sur Case.

Cette fonction renvoit un pointeur sur Case qui pointe sur la case aux coordonnées (posx,posy) sur le Terrain.
*/
Case * Terrain_Getcase(const Terrain &t,const int &posx,const int &posy);

/**
@brief Fonction de mutation d'un état d'une case du Terrain.
@param t un Terrain en donnée/résultat initialisé.
@param  c une Case en donnée.
@param  posx un entier en donnée.
@param  posy un entier en donnée.

Cette fonction modifie l'état de la Case aux coordonnées (posx,posy) sur le Terrain en prenant l'état de la Case c qui est initialisée.
*/
void Terrain_Setcase(Terrain &t, const Case &c, const int &posx,const int &poxy);
#endif
