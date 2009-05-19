#include "jeu.h"
#include <SDL.h>

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

    ecran = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Super Bomberman - Deluxe Edition", NULL);

// Couleur de fond de la fenetre
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 17, 206, 112));
    SDL_Rect menpos;
    menpos.x = 0;
    menpos.y = 0;
    menu = SDL_LoadBMP("Menu/menu.bmp");
    SDL_BlitSurface(menu, NULL, ecran, &menpos);
    SDL_Flip(ecran); //MAJ de l'ecran

    SDL_Rect posniv, posvie;
    posniv.x=170;
    posniv.y=3;
    posvie.x=119;
    posvie.y=553;

    nombre[0]=SDL_LoadBMP("Menu/nombre/0.bmp");
    nombre[1]=SDL_LoadBMP("Menu/nombre/1.bmp");
    nombre[2]=SDL_LoadBMP("Menu/nombre/2.bmp");
    nombre[3]=SDL_LoadBMP("Menu/nombre/3.bmp");
    nombre[4]=SDL_LoadBMP("Menu/nombre/4.bmp");
    nombre[5]=SDL_LoadBMP("Menu/nombre/5.bmp");
    nombre[6]=SDL_LoadBMP("Menu/nombre/6.bmp");
    nombre[7]=SDL_LoadBMP("Menu/nombre/7.bmp");
    nombre[8]=SDL_LoadBMP("Menu/nombre/8.bmp");
    nombre[9]=SDL_LoadBMP("Menu/nombre/9.bmp");




    int win = 0;
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
                        niveau = 3;
                        attente = 0;
                        win = 1;
                        SDL_Delay(70);

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
        SDL_Delay(70);
    }
    Jeu bombermangame;
    Bomberman perso;
    int vie_niveau = 3;

// Boucle de jeu
while(win)
{
// Affichage du fond Terrain


    SDL_BlitSurface(nombre[niveau], NULL, ecran, &posniv);
    SDL_Rect position;
    position.x = (Sint16) 212.5;
    position.y = (Sint16) 112.5;
    if(niveau == 1 || niveau == 4 || niveau == 7)
    {
            terrain = SDL_LoadBMP("LibNiveau/herbe/Terrain.bmp");
            fond = SDL_LoadBMP("Menu/font.bmp");
    }else{
        if(niveau == 2 || niveau == 5 || niveau == 8)
            {
                terrain = SDL_LoadBMP("LibNiveau/eau/Terrain.bmp");
                fond = SDL_LoadBMP("Menu/font2.bmp");
            }else{
                if(niveau == 3 || niveau == 6 || niveau == 9)
                {
                    terrain = SDL_LoadBMP("LibNiveau/espace/Terrain.bmp");
                    fond = SDL_LoadBMP("Menu/font3.bmp");
                }
            }
    }
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

    int i,j;
    Case * cases;

    if(niveau == 1 || niveau == 4 || niveau == 7)
    {
        mursolide = SDL_LoadBMP("LibNiveau/herbe/mursolide.bmp");
        mur = SDL_LoadBMP("LibNiveau/herbe/mur.bmp");
        bombes = SDL_LoadBMP("LibNiveau/herbe/bombe.bmp");
        explode = SDL_LoadBMP("LibNiveau/herbe/explosioncentre.bmp");
    }else{
        if(niveau == 2 || niveau == 5 || niveau == 8)
            {
                mursolide = SDL_LoadBMP("LibNiveau/eau/mursolide.bmp");
                mur = SDL_LoadBMP("LibNiveau/eau/mur.bmp");
                bombes = SDL_LoadBMP("LibNiveau/herbe/bombe.bmp");
                explode = SDL_LoadBMP("LibNiveau/eau/explosioncentre.bmp");
                SDL_SetColorKey(mur, SDL_SRCCOLORKEY, SDL_MapRGB(mur->format, 255, 0, 0));
                SDL_SetColorKey(explode, SDL_SRCCOLORKEY, SDL_MapRGB(explode->format, 255, 0, 0));
            }else{
                if(niveau == 3 || niveau == 6 || niveau == 9)
                {
                    mursolide = SDL_LoadBMP("LibNiveau/espace/mursolide.bmp");
                    mur = SDL_LoadBMP("LibNiveau/espace/mur.bmp");
                    bombes = SDL_LoadBMP("LibNiveau/espace/bombe.bmp");
                }
            }
    }

    SDL_Rect murpos;

    for(i=0;i<=jeu.dim-1;i++)//y
    {
        for(j=0;j<=jeu.dim-1;j++)//x
        {
            cases=Terrain_Getcase(jeu,j,i);
            if(strcmp(cases->carre,"M") == 0)
            {
                murpos.x=(Sint16) 212.5 + ( j * 25);
                murpos.y=(Sint16)112.5 + ( i * 25);
                SDL_BlitSurface(mur, NULL, ecran, &murpos);


            }else{
                if(strcmp(cases->carre,"S") == 0)
                {
                    murpos.x=(Sint16)212.5 + ( j * 25);
                    murpos.y=(Sint16)112.5 + ( i * 25);
                    SDL_BlitSurface(mursolide, NULL, ecran, &murpos);

                }else{
                        if(strcmp(cases->carre,"E") == 0)
                         {
                            murpos.x=(Sint16)212.5 + ( j * 25);
                            murpos.y=(Sint16)112.5 + ( i * 25);
                            SDL_BlitSurface(explode, NULL, ecran, &murpos);
                         }
                }
            }
        }
    }
//Chargement du Bomberman et des Ennemis

    if(niveau == 1 || niveau == 4 || niveau == 7)
    {
        personnage[0] = SDL_LoadBMP("LibNiveau/herbe/bombermanbas.bmp"); //bas
        personnage[1] = SDL_LoadBMP("LibNiveau/herbe/bombermanhaut.bmp"); //haut
        personnage[2] = SDL_LoadBMP("LibNiveau/herbe/bombermangauche.bmp"); // gauche
        personnage[3] = SDL_LoadBMP("LibNiveau/herbe/bombermandroit.bmp"); // droite
        persoactuel = personnage[0];

        ennemi[0] = SDL_LoadBMP("LibNiveau/herbe/ennemibas.bmp");
        ennemi[1] = SDL_LoadBMP("LibNiveau/herbe/ennemihaut.bmp");
        ennemi[2] = SDL_LoadBMP("LibNiveau/herbe/ennemigauche.bmp");
        ennemi[3] = SDL_LoadBMP("LibNiveau/herbe/ennemidroit.bmp");
        ennemiact = ennemi[0];
    }else{
        if(niveau == 2 || niveau == 5 || niveau == 8)
            {
                personnage[0] = SDL_LoadBMP("LibNiveau/eau/bombermanbas.bmp"); //bas
                personnage[1] = SDL_LoadBMP("LibNiveau/eau/bombermanhaut.bmp"); //haut
                personnage[2] = SDL_LoadBMP("LibNiveau/eau/bombermangauche.bmp"); // gauche
                personnage[3] = SDL_LoadBMP("LibNiveau/eau/bombermandroit.bmp"); // droite
                persoactuel = personnage[0];

                ennemi[0] = SDL_LoadBMP("LibNiveau/eau/ennemibas.bmp");
                ennemi[1] = SDL_LoadBMP("LibNiveau/eau/ennemihaut.bmp");
                ennemi[2] = SDL_LoadBMP("LibNiveau/eau/ennemigauche.bmp");
                ennemi[3] = SDL_LoadBMP("LibNiveau/eau/ennemidroit.bmp");
                ennemiact = ennemi[0];
            }else{
                if(niveau == 3 || niveau == 6 || niveau == 9)
                {
                    personnage[0] = SDL_LoadBMP("LibNiveau/espace/bombermanbas.bmp"); //bas
                    personnage[1] = SDL_LoadBMP("LibNiveau/espace/bombermanhaut.bmp"); //haut
                    personnage[2] = SDL_LoadBMP("LibNiveau/espace/bombermangauche.bmp"); // gauche
                    personnage[3] = SDL_LoadBMP("LibNiveau/espace/bombermandroit.bmp"); // droite
                    persoactuel = personnage[0];

                    ennemi[0] = SDL_LoadBMP("LibNiveau/espace/ennemibas.bmp");
                    ennemi[1] = SDL_LoadBMP("LibNiveau/espace/ennemihaut.bmp");
                    ennemi[2] = SDL_LoadBMP("LibNiveau/espace/ennemigauche.bmp");
                    ennemi[3] = SDL_LoadBMP("LibNiveau/espace/ennemidroit.bmp");
                    ennemiact = ennemi[0];
                }
            }
    }

    SDL_Rect posbomberman;
    posbomberman.x=(Sint16) (Bomberman_Getposx(perso) * 25 + 212.5);
    posbomberman.y=(Sint16) (Bomberman_Getposy(perso) * 25 + 112.5);
    SDL_SetColorKey(persoactuel, SDL_SRCCOLORKEY, SDL_MapRGB(persoactuel->format, 255, 0, 0));
    SDL_BlitSurface(persoactuel, NULL, ecran, &posbomberman);

    SDL_Rect posennemi;

    char * en_dir;
    int * tab;
    tab = dEnnemi_GetPosition(mechant);
    SDL_SetColorKey(ennemiact, SDL_SRCCOLORKEY, SDL_MapRGB(ennemiact->format, 255, 0, 0));

    for(i=0;i<=2*(mechant.liste_en.nb_en)-1;i=i+2)
    {
        posennemi.x=(Sint16)((tab[i] * 25) + 212.5);
        posennemi.y=(Sint16)((tab[i+1] * 25) + 112.5);
        SDL_BlitSurface(ennemiact, NULL, ecran, &posennemi);
    }
    SDL_Flip(ecran); //MAJ de l'ecran
    delete[] tab;

//Début de la boucle infinie avec gestion des mouvements et bombe
    int continuer = 1;
    int quitter = 0;
    int bombepos = 0;
    int poser = 0;
    int initb = 1;
    int tempsac = 0;
    int explosion = 0;
    int temps_explosion = 0;
    int possible_mb = 0;
    int perte_v = 0;
    int init_a = 0;

    Case * touche_explosion;
    Bombe * bombe = NULL;

    SDL_EnableKeyRepeat(10, 10);

while(continuer)
{
        if(initb)
        {
                bombe = Bombe_InitialisationBombe();
                initb = 0;
                init_a = 1;

        }

        SDL_PollEvent(&event); /* Récupèration de l'évènement dans event */
        switch(event.type) /* Test du type d'évènement */
        {
            case SDL_QUIT: /* Si c'est un évènement de type "Quitter" */
                continuer = 0;
                win = 0;
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
            init_a = 0;
            poser = 0;
            bombe->nb++;
            initb = 1;
          }
          bombepos = 0;
        }

        if(poser)
        {
            tempsac = SDL_GetTicks();
            if(tempsac - bombe->temps >= 2500) // On explose la bombe
            {
                poser = 0;
                tempsac = 0;
                bombe->nb++;
                if (Bomberman_PresenceSurTrajetBombe(perso,bombe,jeu))
                {
                    Bomberman_Decrementevie(perso);
                    perte_v = 1;
                }
                dEnnemi_PresenceSurBombe(mechant,bombe,jeu);
                Bombe_ExplosionSurTerrain(bombe,jeu);
                Bombe_testament(bombe);
                init_a = 0;
                explosion = 1;
                temps_explosion = SDL_GetTicks();
                initb=1;
                possible_mb = 1;

            }
        }

        if(explosion && SDL_GetTicks() - temps_explosion >= 500)
        {
             for(i=0;i<=jeu.dim-1;i++)//y
            {
                for(j=0;j<=jeu.dim-1;j++)//x
                {
                     cases=Terrain_Getcase(jeu,j,i);
                    if(strcmp(cases->carre,"E") == 0)
                    {
                        Case p;
                        strcpy(p.carre,"V");
                        Terrain_Setcase(jeu,p,j,i);
                    }

                }
            }
            explosion = 0;
            perte_v = 0;

        }



        // Reblittage de l'image
        int entime = SDL_GetTicks();
        if(entime - mechant.time >= bombermangame.temps_mouvement)
        {
            dEnnemi_Mouvement(mechant,jeu);
            mechant.time = entime;
        }
        posbomberman.x=(Sint16)(Bomberman_Getposx(perso) * 25 + 212.5);
        posbomberman.y=(Sint16)(Bomberman_Getposy(perso) * 25 + 112.5);
        SDL_BlitSurface(fond, NULL, ecran, &menpos);
        SDL_BlitSurface(terrain, NULL, ecran, &position);
        SDL_BlitSurface(nombre[niveau], NULL, ecran, &posniv);
        SDL_BlitSurface(nombre[Bombeman_Getnbvie(perso)], NULL, ecran, &posvie);
        for(i=0;i<=jeu.dim-1;i++)//y
        {
            for(j=0;j<=jeu.dim-1;j++)//x
            {
                cases=Terrain_Getcase(jeu,j,i);
                if(strcmp(cases->carre,"M") == 0)
                {
                    murpos.x=(Sint16) 212.5 + ( j * 25);
                    murpos.y=(Sint16) 112.5 + ( i * 25);
                    SDL_BlitSurface(mur, NULL, ecran, &murpos);


                }else{
                    if(strcmp(cases->carre,"S") == 0)
                    {
                        murpos.x=(Sint16) 212.5 + ( j * 25);
                        murpos.y=(Sint16) 112.5 + ( i * 25);
                        SDL_BlitSurface(mursolide, NULL, ecran, &murpos);
                    }else{
                        if(strcmp(cases->carre,"B") == 0)
                        {
                            murpos.x=(Sint16) 212.5 + ( j * 25);
                            murpos.y=(Sint16) 112.5 + ( i * 25);
                            SDL_BlitSurface(bombes, NULL, ecran, &murpos);
                        }else{
                            if(strcmp(cases->carre,"E") == 0)
                            {
                                murpos.x=(Sint16) 212.5 + ( j * 25);
                                murpos.y=(Sint16) 112.5 + ( i * 25);
                                SDL_BlitSurface(explode, NULL, ecran, &murpos);
                            }
                        }
                    }
                }
            }
        }


        tab = dEnnemi_GetPosition(mechant);
        en_dir = dEnnemi_GetDirection(mechant);
        for(i=0;i<=2*(mechant.liste_en.nb_en)-1;i=i+2)
        {
            posennemi.x=(Sint16)((tab[i] * 25) + 212.5);
            posennemi.y=(Sint16)((tab[i+1] * 25) + 112.5);
            if(en_dir[i/2] == 'b')
            {
                ennemiact = ennemi[0];
            }else{ if(en_dir[i/2] == 'h')
                    {
                            ennemiact = ennemi[1];
                    }else { if(en_dir[i/2] == 'g')
                            {
                                ennemiact = ennemi[2];
                            }else if(en_dir[i/2] == 'd')
                            {
                                ennemiact = ennemi[3];
                            }
                    }
            }
            // Changt position ennemi



            SDL_SetColorKey(ennemiact, SDL_SRCCOLORKEY, SDL_MapRGB(ennemiact->format, 255, 0, 0));
            SDL_BlitSurface(ennemiact, NULL, ecran, &posennemi);

        }
        delete[] tab;
        delete[] en_dir;
        // Fin de blittage de l'écran

        Jeu_PerteVieContactEnnemi(perso,mechant); // Test si contact ennemi
        if(perso.nb_vie == 0) // test nombre de vie bomberman
        {
                continuer = 0;
                dead = 1;
                win = 0;
        }

        touche_explosion = Terrain_Getcase(jeu,perso.posx,perso.posy);
        if(!strcmp(touche_explosion->carre,"E") && (!perte_v))
        {
             Bomberman_Decrementevie(perso);
             perte_v = 1;
        }

        dEnnemi_ToucheExplosion(mechant,jeu);

        if(mechant.liste_en.nb_en == 0 && perso.nb_vie > 0)
        {
                continuer = 0;
                win = 1;
                vie_niveau = Bombeman_Getnbvie(perso);
                niveau = niveau + 1;

        }
        SDL_SetColorKey(persoactuel, SDL_SRCCOLORKEY, SDL_MapRGB(persoactuel->format, 255, 0, 0));
        SDL_BlitSurface(persoactuel, NULL, ecran, &posbomberman);
        SDL_Flip(ecran);
        SDL_Delay(85);
    }

    Terrain_testament(jeu);
    dEnnemi_Testament(mechant);
    if(init_a) Bombe_testament(bombe);
}

// Test de Game Over ?
if(dead)
{
    SDL_BlitSurface(gameover, NULL, ecran, &menpos);
    SDL_Flip(ecran);
    SDL_Delay(5000);
}
    SDL_FreeSurface(ecran);
    SDL_FreeSurface(menu);
    SDL_FreeSurface(gameover);
    for(int i=0;i<10;i++) SDL_FreeSurface(nombre[i]);
    SDL_EnableKeyRepeat(0, 0);
    SDL_FreeSurface(terrain);
    SDL_FreeSurface(bombes);
    SDL_FreeSurface(mursolide);
    SDL_FreeSurface(explode);
    SDL_FreeSurface(mur);
    SDL_FreeSurface(fond);
    for(int i=0;i<4;i++)
    {
        SDL_FreeSurface(personnage[i]);
    }

    for(int i=0;i<4;i++)
    {
        SDL_FreeSurface(ennemi[i]);
    }
    SDL_Quit();

    return EXIT_SUCCESS;
}
