#ifndef _Terrain
#define _Terrain
#include "case.h"


struct sTerrain
{
     int dim;
     Case *plateau;

};
typedef struct sTerrain Terrain;

void Terrain_initialisation(Terrain & t);
// Initilialise le terrain en case vide et affecte les murs et murs solides en foncton du niveau.

void Terrain_affectationaleatoire(Terrain &t);

void Terrain_testament(Terrain &t);
// Vide correctement en mémoire le Terrain.

Case * Terrain_Getcase(const Terrain &t,const int &posx,const int &posy);
// Accesseur du module terrain : on obtient une case

void Terrain_Setcase(Terrain &t, const Case &c, const int &posx,const int &poxy);
// Accesseur du module terrain : modifie une case par une autre à une telle position

#endif
