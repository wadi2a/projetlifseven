#include "jeu.h"
#include <SDL/SDL.h>

void Jeu_Affichagetemporaire(const Terrain &t);
//Procédure temporaire d'affichae du terrain

void pause_sdl();

int main(void)
{
    SDL_Surface *ecran = NULL;
    SDL_Surface *terrain = NULL;
    SDL_Surface *bombes = NULL;
    SDL_Surface *mursolide = NULL;
    SDL_Surface *mur = NULL;
    SDL_Surface *personnage[4] = {NULL};
    SDL_Surface *persoactuel = NULL;
    SDL_Surface *ennemi = NULL;
    SDL_Event event;
    SDL_Surface *menu = NULL;
    SDL_Surface *gameover = SDL_LoadBMP("Menu/gameover.bmp");



     if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1) // Démarrage de la SDL. Si erreur alors..
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Ecriture de l'erreur
        exit(EXIT_FAILURE); // On quitte le programme
    }
    ecran = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Super Bomberman Deluxe Edition", NULL);

// Couleur de fond de la fenetre
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 17, 206, 112));
    SDL_Rect menpos;
    menpos.x = 0;
    menpos.y = 0;
    menu = SDL_LoadBMP("Menu/menu.bmp");
    SDL_BlitSurface(menu, NULL, ecran, &menpos);
    SDL_Flip(ecran); //MAJ de l'ecran


    int win;
    int quitter = 0;
    int niveau;
    int dead = 0;

// MENU
    int attente = 1;
    while(attente)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                attente = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_s:
                        niveau = 1;
                        attente = 0;
                        win = 1;

                        break;
                    case SDLK_ESCAPE :
                        win = 0;
                        quitter = 1;
                        attente = 0;
                        break;
                    default:
                        break;
                }

                break;
        }
    }







// Boucle de jeu
while(win)
{
// Affichage du fond Terrain
    SDL_Rect position;
    position.x = 212.5;
    position.y = 112.5;
    terrain = SDL_LoadBMP("LibNiveau/herbe/Terrain.bmp");
    SDL_BlitSurface(terrain, NULL, ecran, &position);
    SDL_Flip(ecran);


//Initialisation du terrain et affichage des murs

    dEnnemi mechant;
    Terrain jeu;
    Bomberman perso;
    Bombe * bombe;

    Jeu_InitRand();
    Bombe_InitialisationBombe(bombe);
    Jeu bombermangame;
    Jeu_ChoixNiveau(bombermangame,niveau);
    Jeu_ChoixMechant(bombermangame,niveau + 1);


    Jeu_Initialisation(bombermangame,jeu,mechant,perso);

// Affichage des cases

    int i,j;
    Case * cases;

    mursolide = SDL_LoadBMP("LibNiveau/herbe/mursolide.bmp");
    mur = SDL_LoadBMP("LibNiveau/herbe/mur.bmp");
    bombes = SDL_LoadBMP("LibNiveau/herbe/bombe.bmp");
    SDL_Rect murpos;

    for(i=0;i<=jeu.dim-1;i++)//y
    {
        for(j=0;j<=jeu.dim-1;j++)//x
        {
            cases=Terrain_Getcase(jeu,j,i);
            if(strcmp(cases->carre,"M") == 0)
            {
                murpos.x=212.5 + ( j * 25);
                murpos.y=112.5 + ( i * 25);
                SDL_BlitSurface(mur, NULL, ecran, &murpos);


            }else{
                if(strcmp(cases->carre,"S") == 0)
                {
                    murpos.x=212.5 + ( j * 25);
                    murpos.y=112.5 + ( i * 25);
                    SDL_BlitSurface(mursolide, NULL, ecran, &murpos);

                }

            }

        }


    }
//Chargement du Bomberman et des Ennemis
    personnage[0] = SDL_LoadBMP("LibNiveau/herbe/bombermanbas.bmp"); //bas
    personnage[1] = SDL_LoadBMP("LibNiveau/herbe/bombermanhaut.bmp"); //haut
    personnage[2] = SDL_LoadBMP("LibNiveau/herbe/bombermangauche.bmp"); // gauche
    personnage[3] = SDL_LoadBMP("LibNiveau/herbe/bombermandroit.bmp"); // droite
    persoactuel = personnage[0];
    SDL_Rect posbomberman;
    posbomberman.x=Bomberman_Getposx(perso) * 25 + 212.5;
    posbomberman.y=Bomberman_Getposy(perso) * 25 + 112.5;
    SDL_BlitSurface(persoactuel, NULL, ecran, &posbomberman);

    ennemi = SDL_LoadBMP("LibNiveau/herbe/explosioncentre.bmp");
    SDL_Rect posennemi;

    int * tab;
    tab = dEnnemi_GetPosition(mechant);

    for(i=0;i<=2*(mechant.liste_en.nb_en)-1;i=i+2)
    {
        posennemi.x=(tab[i] * 25) + 212.5;
        posennemi.y=(tab[i+1] * 25) + 112.5;
        SDL_BlitSurface(ennemi, NULL, ecran, &posennemi);

    }
    SDL_Flip(ecran); //MAJ de l'ecran




//Début de la boucle infinie avec gestion des mouvements et bombe
    int continuer = 1;
    int quitter = 0;
    int bombepos = 0;
    int poser = 0;
    int initb = 0;
    int tempsac = 0;



    SDL_EnableKeyRepeat(10, 10);




    while(continuer)
    {
        if(initb)
        {
                Bombe * bombe;
                Bombe_InitialisationBombe(bombe);
                initb = 0;
        }


        SDL_PollEvent(&event); /* Récupèration de l'évènement dans event */
        switch(event.type) /* Test du type d'évènement */
        {
            case SDL_QUIT: /* Si c'est un évènement de type "Quitter" */
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP:
                        Bomberman_mouvement(perso,jeu,2);
                        persoactuel = personnage[1];
                        break;
                    case SDLK_DOWN:
                        Bomberman_mouvement(perso,jeu,1);
                        persoactuel = personnage[0];
                        break;
                    case SDLK_RIGHT:
                        Bomberman_mouvement(perso,jeu,3);
                        persoactuel = personnage[3];
                        break;
                    case SDLK_LEFT:
                        Bomberman_mouvement(perso,jeu,4);
                        persoactuel = personnage[2];
                        break;
                    case SDLK_SPACE:
                        if(bombe->nb) bombepos = 1;
                        break;
                    case SDLK_ESCAPE :
                        continuer = 0;
                        quitter = 1;
                        win = 0;
                        break;


                    default:
                        break;
                }

                break;
        }

        if(bombepos)
        {

          poser = 1;
          bombe->nb--;
          int bombt = SDL_GetTicks();
          if(!(Bombe_bombe(bombe,jeu,perso.posx,perso.posy,bombt)))
          {
            Bombe_testament(bombe);
            poser = 0;
            bombe->nb++;
          }
          bombepos = 0;
        }

        if(poser)
        {
            tempsac = SDL_GetTicks();
            if(tempsac - bombe->temps >= 4000) // On explose la bombe
            {
                poser = 0;
                tempsac = 0;
                bombe->nb++;
                if (Bomberman_PresenceSurTrajetBombe(perso,bombe)) Bomberman_Decrementevie(perso);
                dEnnemi_PresenceSurBombe(mechant,bombe);
                Bombe_ExplosionSurTerrain(bombe,jeu);
                Bombe_testament(bombe);
                initb=1;

            }
        }




        // Reblittage de l'image
        dEnnemi_Mouvement(mechant,jeu);
        posbomberman.x=Bomberman_Getposx(perso) * 25 + 212.5;
        posbomberman.y=Bomberman_Getposy(perso) * 25 + 112.5;
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 17, 206, 112));
        SDL_BlitSurface(terrain, NULL, ecran, &position);
        for(i=0;i<=jeu.dim-1;i++)//y
        {
            for(j=0;j<=jeu.dim-1;j++)//x
            {
                cases=Terrain_Getcase(jeu,j,i);
                if(strcmp(cases->carre,"M") == 0)
                {
                    murpos.x=212.5 + ( j * 25);
                    murpos.y=112.5 + ( i * 25);
                    SDL_BlitSurface(mur, NULL, ecran, &murpos);


                }else{
                    if(strcmp(cases->carre,"S") == 0)
                    {
                        murpos.x=212.5 + ( j * 25);
                        murpos.y=112.5 + ( i * 25);
                        SDL_BlitSurface(mursolide, NULL, ecran, &murpos);
                    }else{
                        if(strcmp(cases->carre,"B") == 0)
                        {
                            murpos.x=212.5 + ( j * 25);
                            murpos.y=112.5 + ( i * 25);
                            SDL_BlitSurface(bombes, NULL, ecran, &murpos);
                        }
                    }
                }


         }
        }

        tab = dEnnemi_GetPosition(mechant);
        for(i=0;i<=2*(mechant.liste_en.nb_en)-1;i=i+2)
        {
            posennemi.x=(tab[i] * 25) + 212.5;
            posennemi.y=(tab[i+1] * 25) + 112.5;
            SDL_BlitSurface(ennemi, NULL, ecran, &posennemi);

        }
        // Fin de blittage de l'écran

        Jeu_PerteVieContactEnnemi(perso,mechant); // Test si contact ennemi
        if(perso.nb_vie == 0) // test nombre de vie bomberman
        {
                continuer = 0;
                dead = 1;
                win = 0;
        }

        if(mechant.liste_en.nb_en == 0 && perso.nb_vie > 0)
        {
                continuer = 0;
                win = 1;
                niveau = 2;
        }


        SDL_BlitSurface(persoactuel, NULL, ecran, &posbomberman);
        SDL_Flip(ecran);
        SDL_Delay(80);


    }

    Terrain_testament(jeu);
    dEnnemi_Testament(mechant);
}







// Test de Game Over ?
if(dead)
{
    SDL_BlitSurface(gameover, NULL, ecran, &menpos);
    SDL_Flip(ecran);
    SDL_Delay(5000);
}

    SDL_FreeSurface(persoactuel);
    SDL_FreeSurface(bombes);
    SDL_FreeSurface(personnage[0]);
    SDL_FreeSurface(personnage[1]);
    SDL_FreeSurface(personnage[2]);
    SDL_FreeSurface(personnage[3]);
    SDL_FreeSurface(ennemi);
    SDL_FreeSurface(mur);
    SDL_FreeSurface(mursolide);
    SDL_FreeSurface(terrain);
    SDL_FreeSurface(menu);
    SDL_FreeSurface(gameover);
    SDL_EnableKeyRepeat(0, 0);
    SDL_Quit();


    return EXIT_SUCCESS;
}
