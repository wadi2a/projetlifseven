#ifndef _Final
#define _Final
#include "jeu.h"
#include <SDL.h>

void Final_AllocationNombre(SDL_Surface * nombre[10]);

void Final_AllocationValeurRect(SDL_Rect & val, const int &x, const int &y);

void Final_AllocationImageFT(SDL_Surface *& terrain, SDL_Surface *& fond, const int &niveau);

void Final_AllocationImageMMBE(SDL_Surface *& mursolide, SDL_Surface *& mur ,SDL_Surface *& bombes, SDL_Surface *& explode, const int &niveau);

void Final_AllocationValeurRectMMBE(const Terrain &jeu,SDL_Surface *& ecran, SDL_Surface *& mursolide, SDL_Surface *& mur ,SDL_Surface *& bombes, SDL_Surface *& explode, SDL_Rect & murpos);

void Final_AllocationImagePE(SDL_Surface * ennemi[4], SDL_Surface * personnage[4] ,SDL_Surface *& persoact, SDL_Surface *& ennemiact, const int &niveau);

void Final_Menu(SDL_Event &event,int & niveau, int & win, int & quitter);

void Final_AffichageMechant(const dEnnemi &mechant, SDL_Surface * ennemiact,SDL_Surface * ecran, SDL_Rect &posennemi, int * tab);

void Final_MouvementEvent(SDL_Event &event,int & continuer, int & win, int & bombepos, Bombe *bombe,int & quitter, SDL_Surface * personnage[4], SDL_Surface *& persoactuel, const Terrain &jeu, Bomberman &perso );

void Final_TestInitBombe(int &initb, int & init_a, Bombe *& bombe);

void Final_PoseBombe(int &poser, Bombe *& bombe,  Terrain &jeu, const Bomberman &perso, int &init_a, int &initb, int &bombepos);

void Final_ExplosionBombe(int &poser,int &perte_v,int &explosion,int &temps_explosion,int &initb, int &possible_mb, Bombe *& bombe, Bomberman &perso, Terrain &jeu, dEnnemi &mechant, int &init_a);

void Final_AffichageExplosion(int &explosion, const int & temps_explosion,int &perte_v, Terrain &jeu);

void Final_AffichageEnnemis(const dEnnemi &mechant, SDL_Rect &posennemi, SDL_Surface *& ennemiact, SDL_Surface * ennemi[4],SDL_Surface *& ecran, char *en_dir, int * tab);

void Final_TestFinaux(dEnnemi &mechant, Bomberman &perso,Terrain &jeu,int &win,int &niveau, int &vie_niveau, int &perte_v, int &continuer, int &dead, Case * touche_explosion);

void Final_MouvementEnnemis(dEnnemi &mechant,const Jeu &bombermangame, Terrain &jeu);

void Final_LiberationMemoire(SDL_Surface * ecran, SDL_Surface * menu, SDL_Surface * gameover, SDL_Surface *nombre[10],SDL_Surface *terrain, SDL_Surface *bombes, SDL_Surface *mursolide, SDL_Surface * explode, SDL_Surface * mur,SDL_Surface *fond, SDL_Surface *personnage[4],SDL_Surface *ennemi[4]);

#endif

