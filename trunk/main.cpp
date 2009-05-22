#include "final.h"

int main (int argc, char** argv)
{
    if ( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1) // Démarrage de la SDL. Si erreur alors..
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Ecriture de l'erreur
        SDL_Quit();
        exit(EXIT_FAILURE); // On quitte le programme
    }

    SDL_Surface *ecran = NULL;
    SDL_Surface *menu = NULL;
    SDL_Surface *gameover = SDL_LoadBMP("Menu/gameover.bmp");
    SDL_Surface *nombre[10] = {NULL};
    SDL_Event event;
    SDL_Surface *terrain = NULL;
    SDL_Surface *bombes = NULL;
    SDL_Surface *mursolide = NULL;
    SDL_Surface *explode = NULL;
    SDL_Surface *ennemiact = NULL;
    SDL_Surface *mur = NULL;
    SDL_Surface *personnage[4] = {NULL};
    SDL_Surface *persoactuel = NULL;
    SDL_Surface *ennemi[4] = {NULL};
    SDL_Surface *fond = NULL;
    SDL_Surface *load[5] = {NULL};
    SDL_Surface *menufin[2] = {NULL};
    SDL_Surface *mpause[3] = {NULL};

    ecran = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Super Bomberman - Deluxe Edition", NULL);

// Couleur de fond de la fenetre
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 17, 206, 112));

    SDL_Rect posniv, posvie;
    Final_AllocationValeurRect(posniv,(Sint16) 170,(Sint16) 3);
    Final_AllocationValeurRect(posvie,(Sint16) 119,(Sint16) 553);
    Final_AllocationNombre(nombre);
    Final_AllocationLoad(load);
    Final_AllocationMenuFin(menufin);
    Final_AllocationMenuPause(mpause);

    int win = 0;
    int quitter = 0;
    int niveau;
    int dead = 0;
    bool jeufin = false;


    SDL_Rect menpos;
    Final_AllocationValeurRect(menpos,0,0);
    menu = SDL_LoadBMP("Menu/menu.bmp");
do
{
    dead = 0;
    SDL_BlitSurface(menu, NULL, ecran, &menpos);
    SDL_Flip(ecran); //MAJ de l'ecran


// MENU
    Final_Menu(event,niveau,win,quitter,jeufin);
    Jeu bombermangame;
    Bomberman perso;
    int vie_niveau = 3;

// Boucle de jeu
while(win)
{
// Affichage du fond Terrain

    Final_ChargementEntreNiveau(load,ecran);


    SDL_BlitSurface(nombre[niveau], NULL, ecran, &posniv);
    SDL_Rect position;
    Final_AllocationValeurRect(position,(Sint16) 212.5,(Sint16) 112.5);
    Final_AllocationImageFT(terrain,fond,niveau);
    SDL_BlitSurface(fond, NULL, ecran, &menpos);
    SDL_BlitSurface(terrain, NULL, ecran, &position);
    SDL_Flip(ecran);

//Initialisation du terrain et affichage des murs

    dEnnemi mechant;
    Terrain jeu;
    Jeu_InitRand();
    Jeu_ChoixNiveau(bombermangame,niveau);
    Jeu_ChoixMechant(bombermangame,niveau + 1);
    Jeu_Initialisation(bombermangame,jeu,mechant,perso,400 - 50 * niveau);
    mechant.time=SDL_GetTicks();
    Bomberman_Setnbvie(perso,vie_niveau);
    SDL_BlitSurface(nombre[Bombeman_Getnbvie(perso)], NULL, ecran, &posvie);

// Affichage des cases

    Final_AllocationImageMMBE(mursolide,mur ,bombes,explode,niveau);
    SDL_Rect murpos;
    Final_AllocationValeurRectMMBE(jeu,ecran,mursolide,mur,bombes,explode,murpos);

//Chargement du Bomberman et des Ennemis

    Final_AllocationImagePE(ennemi,personnage,persoactuel,ennemiact,niveau);
    SDL_Rect posbomberman;
    Final_AllocationValeurRect(posbomberman,(Sint16) (Bomberman_Getposx(perso) * 25 + 212.5),(Sint16) (Bomberman_Getposy(perso) * 25 + 112.5));
    SDL_SetColorKey(persoactuel, SDL_SRCCOLORKEY, SDL_MapRGB(persoactuel->format, 255, 0, 0));
    SDL_BlitSurface(persoactuel, NULL, ecran, &posbomberman);
    SDL_Rect posennemi;
    char * en_dir;
    int * tab;
    tab = dEnnemi_GetPosition(mechant);
    SDL_SetColorKey(ennemiact, SDL_SRCCOLORKEY, SDL_MapRGB(ennemiact->format, 255, 0, 0));
    Final_AffichageMechant(mechant,ennemiact,ecran,posennemi,tab);
    SDL_Flip(ecran); //MAJ de l'ecran
    delete[] tab;

//Début de la boucle infinie avec gestion des mouvements et bombe
    int continuer = 1;
//    int quitter = 0;
    int bombepos = 0;
    int poser = 0;
    int initb = 1;
    int explosion = 0;
    int temps_explosion = 0;
    int possible_mb = 0;
    int perte_v = 0;
    int init_a = 0;
    Case * touche_explosion = NULL;
    Bombe * bombe = NULL;

    SDL_EnableKeyRepeat(10, 10);

// Le Jeu en lui même
while(continuer)
{
        Final_TestInitBombe(initb,init_a,bombe);
        Final_MouvementEvent(event,continuer,win,bombepos,bombe,quitter,personnage,persoactuel,jeu,perso,ecran,mpause,jeufin,menpos);
        Final_PoseBombe(poser,bombe,jeu,perso,init_a,initb,bombepos);
        Final_ExplosionBombe(poser,perte_v,explosion,temps_explosion,initb,possible_mb,bombe,perso,jeu,mechant,init_a);
        Final_AffichageExplosion(explosion,temps_explosion,perte_v,jeu);

        // Reblittage de l'image
        Final_MouvementEnnemis(mechant,bombermangame,jeu);
        Final_AllocationValeurRect(posbomberman,(Sint16) (Bomberman_Getposx(perso) * 25 + 212.5),(Sint16) (Bomberman_Getposy(perso) * 25 + 112.5));SDL_BlitSurface(fond, NULL, ecran, &menpos);
        SDL_BlitSurface(terrain, NULL, ecran, &position);
        SDL_BlitSurface(nombre[niveau], NULL, ecran, &posniv);
        SDL_BlitSurface(nombre[Bombeman_Getnbvie(perso)], NULL, ecran, &posvie);
        Final_AllocationValeurRectMMBE(jeu,ecran,mursolide,mur,bombes,explode,murpos);
        tab = dEnnemi_GetPosition(mechant);
        en_dir = dEnnemi_GetDirection(mechant);
        Final_AffichageEnnemis(mechant, posennemi,ennemiact, ennemi,ecran, en_dir, tab);
        delete[] tab;
        delete[] en_dir;
        // Fin de blittage de l'écran

        Final_TestFinaux(mechant,perso,jeu,win,niveau,vie_niveau,perte_v,continuer,dead,touche_explosion);
        SDL_SetColorKey(persoactuel, SDL_SRCCOLORKEY, SDL_MapRGB(persoactuel->format, 255, 0, 0));
        SDL_BlitSurface(persoactuel, NULL, ecran, &posbomberman);
        SDL_Flip(ecran);
        SDL_Delay(85);
    }

    Terrain_testament(jeu);
    dEnnemi_Testament(mechant);
    if(init_a) Bombe_testament(bombe);
    }
    if(dead && !jeufin)
    {
        SDL_BlitSurface(gameover, NULL, ecran, &menpos);
        SDL_Flip(ecran);
        SDL_Delay(1500);
        quitter = 0;
    }
    if(!quitter) Final_MenuFin(event,menufin,menpos,ecran,jeufin);

}while(!jeufin);

// Test de Game Over ?


    Final_LiberationMemoire(ecran,menu,gameover,nombre,terrain,bombes,mursolide,explode,mur,fond,personnage,ennemi,load,menufin,mpause);
    SDL_Quit();
    return EXIT_SUCCESS;
}

