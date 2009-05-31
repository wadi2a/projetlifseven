/**
 * \file dennemis.h
 * \brief Déclarations des types et fonctions pour l'utilisation d'un ensemble d'Ennemis au cours d'une partie de Bomberman.
 *
 * Ce fichier d'en-tête permet la gestion de plusieurs Ennemi pendant une partie. Ce fichier contient les fonctions qui permettent le mouvement, et
 * l'affectation sur le terrain lors de l'Initialisation.
*/
#ifndef _desEnnemi
#define _desEnnemi
#include "ennemi.h"
#include "liste.h"

struct sdEnnemi {
    Liste liste_en;
    int time;
};typedef struct sdEnnemi dEnnemi;

/**
@brief Fonction qui Initialise la liste d'Ennemis et les affecte sur le Terrain
@param e une liste d'ennemi en donnée/résultat
@param t un Terrain en donnée
@param nb un Entier en donnée

Cette fonction prend en paramètre une Liste d'ennemi non initialisée, un Terrain et un entier nb qui correspond au nombre d'Ennemis à initialiser.
Une fois la liste initialisée, chaque Ennemi de la liste est affecté au Terrain, chacun des Ennemis ayant une position différente.
*/
void dEnnemi_Initialisation(dEnnemi & e, const Terrain &t, const int & nb);

/**
@brief Fonction qui Initialise la liste d'Ennemis et les affecte sur le Terrain
@param e une liste d'ennemi en donnée/résultat
@param m un pointeur sur Ennemi

Cette fonction prend en paramètre une Liste d'ennemi initialisée, et un pointeur sur Ennemi. Cette fonction supprime l'Ennemi qui correspond
à l'Ennemi pointé de la liste. Mais l'Ennemi doit appartenir à la Liste pour être utilisé.
*/
void dEnnemi_SupprimeEnnemi(dEnnemi & e, Ennemi * m);

/**
@brief Fonction qui supprime proprement en Mémoire la liste d'Ennemis
@param e une liste d'ennemi en donnée/résultat

Cette fonction prend en paramètre une Liste d'ennemi initialisée. Elle supprime proprement en mémoire la liste d'ennemis.
*/
void dEnnemi_Testament(dEnnemi & e);

/**
@brief Fonction qui gère le mouvement de chaque Ennemis de la liste
@param e une liste d'ennemi en donnée/résultat
@param t un Terrain en donnée

Cette fonction prend en paramètre une Liste d'ennemi initialisée, et un Terrain. Elle gère de manière aléatoire le mouvement des Ennemis de la liste d'Ennmis en vérifiant
si le mouvement est possible. Cette fonction utilise la fonction de mouvement du module Ennemi.
*/
void dEnnemi_Mouvement(dEnnemi & e, const Terrain &t);

/**
@brief Fonction qui teste si un Ennemi est sur le rayon d'explosion de la Bombe
@param e une liste d'ennemi en donnée/résultat
@param b un pointeur sur Bombe
@param t un Terrain en donnée/résultat

Cette fonction prend en paramètre une Liste d'ennemi initialisée, un Terrain et une Bombe. Elle teste si chaque ennemis de la liste est présent sur le rayon de la Bombe.
Si oui, elle supprime l'ennemi en utilisant la fonction du module.
*/
void dEnnemi_PresenceSurBombe(dEnnemi & e, Bombe * b, Terrain &t);

/**
@brief Fonction qui renvoie les positions des Ennemis de la Liste.
@param e une liste d'ennemi en donnée/résultat
@return un Tableau d'entier

Cette fonction prend en paramètre une Liste d'ennemi initialisée. Elle renvoie un tableau d'entiers pour chaque Ennemis de la liste qui correspondent aux positions
de chaques Ennemis ( t[0] = posx du 1er ennemi, t[1] = posy du 1er ennemi etc ...).
*/
int * dEnnemi_GetPosition(dEnnemi & e);

/**
@brief Fonction qui gère le mouvement de chaque Ennemis de la liste
@param e une liste d'ennemi en donnée/résultat
@return un Tableau de caractère

Cette fonction prend en paramètre une Liste d'ennemi initialisée. Elle renvoie un tableau de caractères pour chaque Ennemis de la liste qui correspondent aux directions
de chaques Ennemis.
*/
char * dEnnemi_GetDirection(dEnnemi & e);

/**
@brief Fonction qui teste si un Ennemi de la liste touche une explosion
@param e une liste d'ennemi en donnée/résultat
@param t un Terrain en donnée

Cette fonction prend en paramètre une Liste d'ennemi initialisée et un Terrain t. Elle teste pour chaque Ennemis de la liste s'il touche une explosion
lorsque la fonction est appelée. Si oui, l'ennemis est supprimer à l'aide de la fonction de suppression du module.
*/
void dEnnemi_ToucheExplosion(dEnnemi & e, const Terrain &t);

#endif
