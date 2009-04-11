#ifndef _Jeu
#define _Jeu
#include "dennemis.h"
#include "bomberman.h"

struct sJeu
{
        int niveau;
}

void Jeu_InitRand();

void Jeu_Initialisation();

void Jeu_PerteVieContactEnnemi();

void Jeu_Posebombe();


#endif
