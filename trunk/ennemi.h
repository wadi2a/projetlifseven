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

int Ennemi_Getposx(const Ennemi &e);

int Ennemi_Getposy(const Ennemi &e);

char Ennemi_Getdirection(const Ennemi &e);

void Ennemi_Setposx(Ennemi &e, const int &x);

void Ennemi_Setposy(Ennemi &e, const int &y);

void Ennemi_Setdirection(Ennemi &e, const char &dir);

int Ennemi_Getnbvie(const Ennemi &e);

void Ennemi_Setnbvie(Ennemi &e, const int &nbv);

void Ennemi_Decrementevie(Ennemi &e);

void Ennemi_Initialisation(Ennemi &e, const Terrain &t);

void Ennemi_mouvement(Ennemi &e, const Terrain &t);

bool Ennemi_PresenceSurTrajetBombe(const Ennemi &e, const Bombe &b);


#endif
