#ifndef _Bombe
#define _Bombe
#include "terrain.h"

struct sBombe
{
    int x;
    int y;
    int r_exp;
};
typedef struct sBombe Bombe;

bool Bombe_posebombe(Bombe &b, const int &posx, const int &posy, Terrain &t, const int &rayon);
//Pose une bombe aux coordonnées x et y, sur le plateau du jeu, il doit s'agir d'une case vide. Renvoit vrai si la bombe est posée, faux sinon.

void Bombe_minuteur(const int &tmp);
//Minuteur de tmp s

void Bombe_ExplosionSurTerrain(const Bombe &b,Terrain &t);
//Explosion de la bombe avec suppresion des murs cassables à partir du point d'impact et sur le rayon définis dans la structure

void Bombe_bombe(Bombe &b, Terrain &t, const int &x, const int &y);
#endif
