
#ifndef _Terrain
#define _Terrain
#include "case.h"

struct sTerrain
{
     unsigned int dim = 15;
     Case *plateau;

};
typedef struct sTerrain Terrain;

void Terrain_initialisation(Terrain & t, const int &niveau);
// Initilialise le terrain en case vide et affecte les murs et murs solides en foncton du niveau.

void Terrain_changeetat(Terrain &t, const int &posx, const int &posy, const);
// Change l'état du terrain initialisé et supprime un mur (apparition du vide).

void Terrain_testament(Terrain &t);
// Vide correctement en mémoire le Terrain.

#endif
