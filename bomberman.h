/**
 * \file bomberman.h
 * \brief Déclarations des types et fonctions pour l'utilisation (mouvement, poser une bombe) du Bomberman au cours d'une partie de Bomberman.
 *
 * Ce fichier d'en-tête permet la gestion du Bomberman pendant une partie. Ce fichier contient les fonctions qui permettent le mouvement, l'action de
 * poser une bombe. Il contient aussi les fonctions de modifications des champs de la structure (vie, bombe, direction, positions). A l'inverse, le fichier contient
 * les fonctions pour obtenir ces mêmes informations.
*/
#ifndef _Bomberman
#define _Bomberman
#include "bombe.h"
// Document Doxygen en cours le 26 mai !!
struct sBomberman {
    int posx;
    int posy;
    char direction;
    int nb_vie;
    int nb_bombe;
};
typedef struct sBomberman Bomberman;

/**
@brief Renvoie la position x du Bomberman
@param b un Bomberman en donnée
@return un Entier

Cette fonction prend en paramètre un Bomberman b et renvoit sa coordonnée x qui correspond au champs posx de la structure Bomberman.
Cette fonction est un accesseur.
*/
int Bomberman_Getposx(const Bomberman &b);

/**
@brief Renvoie la position y du Bomberman
@param b un Bomberman en donnée
@return un Entier

Cette fonction prend en paramètre un Bomberman b et renvoit sa coordonnée y qui correspond au champs posy de la structure Bomberman.
Cette fonction est un accesseur.
*/
int Bomberman_Getposy(const Bomberman &b);

/**
@brief Renvoie la direction du Bomberman ('h','b','g' ou 'd')
@param b un Bomberman en donnée
@return un Caractère

Cette fonction prend en paramètre un Bomberman b et renvoit sa direction qui correspond au champs direction de la structure Bomberman.
Cette fonction est un accesseur.
*/
char Bomberman_Getdirection(const Bomberman &b);

/**
@brief Renvoie le nombre de Bombe disponible du Bomberman
@param b un Bomberman en donnée
@return un Entier

Cette fonction prend en paramètre un Bomberman b et renvoit le nombre de bombes du Bomberman disponble qui correspond au champs nb_bombe de la structure Bomberman.
Cette fonction est un accesseur.
*/
int Bomberman_Getbombe(const Bomberman &b);

/**
@brief Renvoie le nombre de vie du Bomberman
@param b un Bomberman en donnée
@return un Entier

Cette fonction prend en paramètre un Bomberman b et renvoit le nombre de vies du Bomberman qui correspond au champs nb_vie de la structure Bomberman.
Cette fonction est un accesseur.
*/
int Bombeman_Getnbvie(const Bomberman &b);

/**
@brief Affecte un x nombre de Bombes au Bomberman
@param b un Bomberman en donnée/résultat
@param nb un Entier en donnée

Cette fonction prend en paramètre un Bomberman b et un entier nb. Cette fonction affecte la valeur du paramètre nb au champs nb_bombe de la structure Bomberman.
Cette fonction est un mutateur.
*/
void Bomberman_Setbombe(Bomberman &b, const int &nb);

/**
@brief Affecte un entier à la postion x du Bomberman
@param b un Bomberman en donnée/résultat
@param nb un Entier en donnée

Cette fonction prend en paramètre un Bomberman b et un entier nb. Cette fonction affecte la valeur du paramètre nb au champs posx de la structure Bomberman.
L'entier nb doit avoir une valeur entre 0 et la dimension du plateau - 1 pour être valable. Cette fonction est un mutateur.
*/
void Bomberman_Setposx(Bomberman &b, const int &nb);

/**
@brief Affecte un entier à la postion y du Bomberman
@param b un Bomberman en donnée/résultat
@param nb un Entier en donnée

Cette fonction prend en paramètre un Bomberman b et un entier nb. Cette fonction affecte la valeur du paramètre nb au champs posy de la structure Bomberman.
L'entier nb doit avoir une valeur entre 0 et la dimension du plateau - 1 pour être valable. Cette fonction est un mutateur.
*/
void Bomberman_Setposy(Bomberman &b, const int &nb);

/**
@brief Affecte la direction nb au Bomberman
@param b un Bomberman en donnée/résultat
@param nb un Caractère en donnée

Cette fonction prend en paramètre un Bomberman b et un caractère nb. Cette fonction affecte la valeur du paramètre nb au champs direction de la structure Bomberman.
Le caractère nb doit être b,h,d ou g pour être valable. Cette fonction est un mutateur.
*/
void Bomberman_Setdirection(Bomberman &b, const char &nb);

/**
@brief Affecte le nombre nbv de vie au Bomberman
@param b un Bomberman en donnée/résultat
@param nbv un Entier en donnée

Cette fonction prend en paramètre un Bomberman b et un entier nbv. Cette fonction affecte la valeur du paramètre nbv au champs nb_vie de la structure Bomberman.
L'entier nbv doit avoir une valeur positve ou nulle. Cette fonction est un mutateur.
*/
void Bomberman_Setnbvie(Bomberman &b, const int &nbv);

/**
@brief Incrémente le nombre de vie du Bomberman
@param b un Bomberman en donnée/résultat initialisé

Cette fonction prend en paramètre un Bomberman b. Elle incrémente le nombre de vie du Bomberman en utilisant le mutateur de vie du module.
*/
void Bomberman_Incrementevie(Bomberman &b);

/**
@brief Décrémente le nombre de vie du Bomberman
@param b un Bomberman en donnée/résultat initialisé

Cette fonction prend en paramètre un Bomberman b. Elle décrémente le nombre de vie du Bomberman en utilisant le mutateur de vie du module.
*/
void Bomberman_Decrementevie(Bomberman &b);

/**
@brief Initialisation du Bomberman
@param b un Bomberman en donnée/résultat non initialisé

Cette fonction prend en paramètre un Bomberman b. Elle initialise les champs de la structure Bomberman (position, vie, bombes et direction).
*/
void Bomberman_Initialisation(Bomberman &b);

/**
@brief Gestion du mouvement du Bomberman
@param b un Bomberman en donnée/résultat initialisé
@param t un Terrain en donnée initialisé
@param pos un Entier en donnée

Cette fonction prend en paramètre un Bomberman b, le Terrain t et un entier pos qui correspond au cas du mouvement (1,2,3 ou 4 pour h,b,g et d).
Lorsque le cas est 1 (ou haut) la fonction teste si le mouvement est possible (case Vide ou "V" et dans le plateau).
Lorsque le cas est 2 (ou bas) la fonction teste si le mouvement est possible (case Vide ou "V" et dans le plateau).
Lorsque le cas est 3 (ou droite) la fonction teste si le mouvement est possible (case Vide ou "V" et dans le plateau).
Lorsque le cas est 4 (ou gauche) la fonction teste si le mouvement est possible (case Vide ou "V" et dans le plateau).
*/
void Bomberman_mouvement(Bomberman &b, const Terrain &t,const int &pos);

/**
@brief Teste si le Bomberman est présent sur le rayon d'explosion
@param a un Bomberman en donnée initialisé
@param b un pointeur sur Bombe
@param t un Terrain en donnée initialisé
@return un Booléen

Cette fonction prend en paramètre un Bomberman a, le Terrain t et un pointeur b sur Bombe.
Lorsque la fonction est appellé, elle teste si le Bomberman est présent ou pas sur le rayon d'explosion de la Bombe.
Elle renvoie "True" si oui, "False" sinon.
*/
bool Bomberman_PresenceSurTrajetBombe(const Bomberman &a, Bombe * b, const Terrain &t);

#endif

