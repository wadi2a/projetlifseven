#ifndef _Jeu
#define _Jeu
#include "dennemis.h"
#include "bomberman.h"

struct sJeu
{
    int niveau;
    int nb_mechant;
};typedef struct sJeu Jeu;

void Jeu_InitRand();

void Jeu_PerteVieContactEnnemi(Bomberman &b, const dEnnemi &e);

void Jeu_ChoixNiveau(Jeu &j, const int &niv);

void Jeu_ChoixMechant(Jeu &j, const int &mech);

void Jeu_Initialisation(const Jeu &j, Terrain &t, dEnnemi &l, Bomberman &b);

//void Jeu_Posebombe();


#endif
