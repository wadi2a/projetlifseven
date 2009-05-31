/**
 * \file jeu.h
 * \brief Déclarations des types et fonctions pour l'initialisation du jeu (niveau, nombre d'ennemis etc...)
 *
 * Ce fichier d'en-tête permet l'initialisation du Jeu, le choix du niveau, le nombre d'ennemis. La fonction d'initialisation permer
 * l'initialisation des Terrains et des Ennemis.
*/
#ifndef _Jeu
#define _Jeu
#include "dennemis.h"
#include "bomberman.h"

struct sJeu
{
    int niveau;
    int nb_mechant;
    int temps_mouvement;
};typedef struct sJeu Jeu;

/**
@brief Fonction qui initialise la fonction de randomisation.

A utiliser en début de programme et une seule fois (hors de boucle).
*/
void Jeu_InitRand();

/**
@brief Fonction qui supprime une vie au Bomberman s'il touche un Ennemi
@param b un Bomberman en donnée/résultat
@param e une Liste d'Ennemis en donnée

Teste si le Bomberman touche un des Ennemis de la liste. Si oui, il perd une vie en utilisant la fonction de décrementation
du module Bomberman.
*/
void Jeu_PerteVieContactEnnemi(Bomberman &b, const dEnnemi &e);

/**
@brief Fonction de choix de niveau
@param j un Jeu en donnée/résultat
@param niv un Entier en donnée

Fonction mutateur. Permet de choisir le niveau pour une partie, elle affecte la valeur niv au champs niveau de la structure Jeu. niv est compris entre 0 et 9.
*/
void Jeu_ChoixNiveau(Jeu &j, const int &niv);

/**
@brief Fonction de choix du nombre d'Ennemis
@param j un Jeu en donnée/résultat
@param mech un Entier en donnée

Fonction mutateur. Permet de choisir le nombre d'ennemis pour une partie, elle affecte la valeur mech au champs nb_mechant de la structure Jeu.
*/
void Jeu_ChoixMechant(Jeu &j, const int &mech);

/**
@brief Fonction d'initialisation du jeu
@param j un Jeu en donnée/résultat
@param t un Terrain en donnée/résultat
@param l une Liste d'ennemis en donnée/résultat
@param b un Bomberman en donnée/résultat
@param temps un Entier en donnée

Fonction qui Initialise le Terrain, la liste d'ennemis et le Bomberman en fonction des champs de la structure Jeu.
La structure Jeu doit être initialisée préablement. La valeur temps correspond à la vitesse de mouvement (en ms) des Ennemis sur le Terrain.
*/
void Jeu_Initialisation(Jeu &j, Terrain &t, dEnnemi &l, Bomberman &b, const int &temps);

#endif
