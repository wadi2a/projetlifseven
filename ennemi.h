/**
 * \file ennemi.h
 * \brief Déclarations des types et fonctions pour l'utilisation d'un seul Ennemi au cours d'une partie de Bomberman.
 *
 * Ce fichier d'en-tête permet la gestion d'un Ennemi pendant une partie. Ce fichier contient les fonctions qui permettent le mouvement, et
 * l'affectation sur le terrain lors de l'Initialisation.
 * Il contient aussi les fonctions de modifications des champs de la structure (vie, bombe, direction, positions). A l'inverse, le fichier contient
 * les fonctions pour obtenir ces mêmes informations.
*/
#ifndef _Ennemi
#define _Ennemi
#include "bombe.h"

struct sEnnemi {
    int posx;
    int posy;
    char direction;
    int nb_vie;
};
typedef struct sEnnemi Ennemi;

/**
@brief Fonction qui affecte en mémoire dynamique l'ennemi
@param e un pointeur sur Ennemi en donnée/résultat

Cette fonction prend en paramètre un pointeur sur Ennemi préablement initialisé à NULL et le fait pointer sur un Ennemi stocké en mémoire
dynamique.
*/
void Ennemi_Creation(Ennemi *& e);

/**
@brief Renvoie la position x de l'Ennemi en paramètre
@param e un pointeur sur Ennemi
@return un Entier

Cette fonction prend en paramètre un pointeur sur Ennemi pointant sur un Ennemi. Elle renvoie la position x qui correspond au champs posx de la
structure ennemi. Cette fonction est un accesseur.
*/
int Ennemi_Getposx(Ennemi * e);

/**
@brief Renvoie la position y de l'Ennemi en paramètre
@param e un pointeur sur Ennemi
@return un Entier

Cette fonction prend en paramètre un pointeur sur Ennemi e pointant sur un Ennemi. Elle renvoie la position y qui correspond au champs posy de la
structure ennemi. Cette fonction est un accesseur.
*/
int Ennemi_Getposy(Ennemi * e);

/**
@brief Renvoie la direction de l'Ennemi en paramètre
@param e un pointeur sur Ennemi
@return un Caractère

Cette fonction prend en paramètre un pointeur sur Ennemi e pointant sur un Ennemi. Elle renvoie sa direction qui correspond au champs direction de la structure Ennemi.
Cette fonction est un accesseur.
*/
char Ennemi_Getdirection(Ennemi * e);

/**
@brief Affecte un entier à la postion x de l'Ennemi
@param e un pointeur sur Ennemi
@param x un Entier en donnée

Cette fonction prend en paramètre un pointeur sur Ennemi e pointant sur un Ennemi et un entier x. Cette fonction affecte la valeur du paramètre x au champs posx de la structure Ennemi
sur lequel le pointeur e pointe. L'entier x doit avoir une valeur entre 0 et la dimension du plateau - 1 pour être valable.
Cette fonction est un mutateur.
*/
void Ennemi_Setposx(Ennemi * e, const int &x);

/**
@brief Affecte un entier à la postion y de l'Ennemi
@param e un pointeur sur Ennemi
@param y un Entier en donnée

Cette fonction prend en paramètre un pointeur sur Ennemi e pointant sur un Ennemi et un entier y. Cette fonction affecte la valeur du paramètre y au champs posy de la structure Ennemi
sur lequel le pointeur e pointe. L'entier y doit avoir une valeur entre 0 et la dimension du plateau - 1 pour être valable.
Cette fonction est un mutateur.
*/
void Ennemi_Setposy(Ennemi * e, const int &y);

/**
@brief Affecte la direction dir à l'Ennemi
@param e un pointeur sur Ennemi
@param dir un Caractère en donnée

Cette fonction prend en paramètre un Bomberman b et un caractère dir. Cette fonction affecte la valeur du paramètre dir au champs direction de la structure Ennemi.
Le caractère dir doit être b,h,d ou g pour être valable. Cette fonction est un mutateur.
*/
void Ennemi_Setdirection(Ennemi * e, const char &dir);

/**
@brief Renvoie le nombre de vie de l'Ennemi
@param e un pointeur sur Ennemi
@return un Entier

Cette fonction prend en paramètre un pointeur sur Ennemi e pointant sur un Ennemi et renvoit le nombre de vies de l'Ennemi qui correspond au champs nb_vie de la structure Ennemi.
Cette fonction est un accesseur.
*/
int Ennemi_Getnbvie(Ennemi * e);

/**
@brief Affecte le nombre nbv de vie à l'Ennemi
@param e un pointeur sur Ennemi
@param nbv un Entier en donnée

Cette fonction prend en paramètre un pointeur sur Ennemi e pointant sur un Ennemi et un entier nbv. Cette fonction affecte la valeur du paramètre nbv au champs nb_vie de la structure Ennemi.
L'entier nbv doit avoir une valeur positve ou nulle. Cette fonction est un mutateur.
*/
void Ennemi_Setnbvie(Ennemi * e, const int &nbv);

/**
@brief Décrémente le nombre de vie de l'Ennemi
@param e un pointeur sur Ennemi

Cette fonction prend en paramètre un pointeur sur Ennemi e pointant sur un Ennemi. Elle décrémente le nombre de vie de l'Ennemi en utilisant le mutateur de vie du module.
*/
void Ennemi_Decrementevie(Ennemi * e);

/**
@brief Affectation sur le Terrain des Ennemis
@param e un pointeur sur Ennemi
@param t un Terrain en donnée initialisé

Cette fonction prend en paramètre un pointeur sur Ennemi e pointant sur un Ennemi et un Terrain t. Cette fonction affecte l'Ennemi de façon aléatoire
sur le Terrain. L'ennemi ne sera pas placé aux coordonnées (O,O),(1,0) et (0,1)
*/
void Ennemi_affectationsurterrain(Ennemi * e, const Terrain &t);

/**
@brief Gestion du mouvement de l'Ennemi
@param e un pointeur sur Ennemi
@param t un Terrain en donnée initialisé

Cette fonction prend en paramètre un pointeur sur Ennemi e pointant sur un Ennemi et un Terrain t. Cette fonction gère de manière aléatoire le mouvement des Ennemis en vérifiant
si le mouvement est possible. Cette fonction gère aussi le changement de direction en utilisant le mutateur de direction du module.
*/
void Ennemi_mouvement(Ennemi * e, const Terrain &t);

/**
@brief Teste si le Bomberman est présent sur le rayon d'explosion
@param e un pointeur sur Ennemi
@param b un pointeur sur Bombe
@param t un Terrain en donnée initialisé
@return un Booléen

Cette fonction prend en paramètre un pointeur sur Ennemi e pointant sur un Ennemi, le Terrain t et un pointeur b sur Bombe.
Lorsque la fonction est appellé, elle teste si l'Ennemi est présent ou pas sur le rayon d'explosion de la Bombe.
Elle renvoie "True" si oui, "False" sinon.
*/
bool Ennemi_PresenceSurTrajetBombe(Ennemi * e, Bombe * b,const Terrain &t);

/**
@brief Libère proprement en mémoire l'Ennemi
@param e un pointeur sur Ennemi

Cette fonction prend en paramètre un pointeur sur Ennemi e pointant sur un Ennemi. Elle libère proprement en mémoire l'Ennemi.
*/
void Ennemi_testament(Ennemi * e);


#endif
