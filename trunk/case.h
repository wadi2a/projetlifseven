/**
 * \file case.h
 * \brief Déclarations des types et fonctions pour l'utilisation d'une Case au sein d'un terrain.
 *
 * Ce fichier d'en-tête permet la gestion d'une case pour un terrain du Bomberman. Ce fichier contient les fonctions d'initialisations
 * des cases.
 */
#ifndef _Case
#define _Case
#include <stdlib.h>
#include <iostream>
#include <time.h>

struct sCase
{
  char carre[20];
};
typedef struct sCase Case;

/**
@brief Initialise une case à vide.

@param a une Case en donnée/résultat non initialisée.

Cette fonction prend en paramètre une case non initialisée et l'initialise à l'état vide ou "V".

*/
void Case_initialisation(Case &a);
/**
@brief Initialise une case à l'état donné en paramètre.

@param a une Case en donnée/résultat non initialisée.
@param b une Case en donnée initialisée.

Cette fonction prend en paramètre une case non initialisée a et une case b initialisée à un certain état. La case a prendra l'état de la case b.

*/
void Case_setCase(Case &a, const Case &b);


#endif

