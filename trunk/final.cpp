#include "final.h"


void Final_AllocationNombre(SDL_Surface * nombre[10])
{
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
}

void Final_AllocationValeurRect(SDL_Rect & val, const int &x, const int &y)
{
        val.x=x;
        val.y=y;
}

void Final_AllocationImageFT(SDL_Surface *& terrain, SDL_Surface *& fond, const int &niveau)
{
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
}

void Final_AllocationImageMMBE(SDL_Surface *& mursolide, SDL_Surface *& mur ,SDL_Surface *& bombes, SDL_Surface *& explode, const int &niveau)
{
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
                bombes = SDL_LoadBMP("LibNiveau/eau/bombe.bmp");
                explode = SDL_LoadBMP("LibNiveau/eau/explosioncentre.bmp");
                SDL_SetColorKey(mur, SDL_SRCCOLORKEY, SDL_MapRGB(mur->format, 255, 0, 0));
                SDL_SetColorKey(bombes, SDL_SRCCOLORKEY, SDL_MapRGB(bombes->format, 255, 0, 0));
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
}

void Final_AllocationValeurRectMMBE(const Terrain &jeu,SDL_Surface *& ecran, SDL_Surface *& mursolide, SDL_Surface *& mur ,SDL_Surface *& bombes, SDL_Surface *& explode, SDL_Rect & murpos)
{
        Case * cases;
        int i,j;
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
}

void Final_AllocationImagePE(SDL_Surface * ennemi[4], SDL_Surface * personnage[4] ,SDL_Surface *& persoactuel, SDL_Surface *& ennemiact, const int &niveau)
{
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
}

void Final_Menu(SDL_Event &event,int & niveau, int & win, int & quitter, bool &jeufin)
{
        int attente = 1;
        while(attente)
        {
            SDL_WaitEvent(&event);
            switch(event.type)
            {
                case SDL_QUIT:
                    attente = 0;
                    jeufin = true;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_s:
                            niveau = 1;
                            attente = 0;
                            win = 1;
                            SDL_Delay(70);
                            break;
                        case SDLK_ESCAPE :
                            win = 0;
                            quitter = 1;
                            attente = 0;
                            jeufin = true;
                            break;
                        default:
                            break;
                    }

                    break;
            }
            SDL_Delay(70);
        }
}

void Final_AffichageMechant(const dEnnemi &mechant, SDL_Surface * ennemiact,SDL_Surface * ecran, SDL_Rect &posennemi, int * tab)
{

    for(int i=0;i<=2*(mechant.liste_en.nb_en)-1;i=i+2)
    {
        Final_AllocationValeurRect(posennemi, (Sint16)((tab[i] * 25) + 212.5),(Sint16)((tab[i+1] * 25) + 112.5));
        SDL_BlitSurface(ennemiact, NULL, ecran, &posennemi);
    }
}

void Final_MenuPause(SDL_Surface *mpause[3], SDL_Surface *ecran, SDL_Rect &menpos, bool &jeufin,int &quitter, int &continuer, int &win, SDL_Event &event)
{
      bool final=true;
      SDL_BlitSurface(mpause[0], NULL, ecran, &menpos);
      SDL_Flip(ecran);
      int mode = 1;


      while(final)
        {
        event.type = (Uint8) NULL;


        SDL_WaitEvent(&event); /* Récupèration de l'évènement dans event */
        switch(event.type) /* Test du type d'évènement */
        {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP:
                        if(mode == 2)
                        {
                            mode=1;
                            SDL_BlitSurface(mpause[0], NULL, ecran, &menpos);
                            SDL_Flip(ecran);
                            SDL_Delay(80);
                        }else{
                            if (mode == 3)
                            {
                                mode=2;
                                SDL_BlitSurface(mpause[1], NULL, ecran, &menpos);
                                SDL_Flip(ecran);
                                SDL_Delay(80);
                            }
                        }
                        break;
                    case SDLK_DOWN:
                        if(mode == 1)
                        {
                            mode=2;
                            SDL_BlitSurface(mpause[1], NULL, ecran, &menpos);
                            SDL_Flip(ecran);
                            SDL_Delay(80);
                        }else{if (mode == 2)
                            {
                                mode=3;
                                SDL_BlitSurface(mpause[2], NULL, ecran, &menpos);
                                SDL_Flip(ecran);
                                SDL_Delay(80);
                            }
                        }
                        break;
                    case SDLK_SPACE:
                        if(mode == 1)
                        {
                                final = false;
                        }
                        if(mode == 2)
                        {
                                final = false;
                                jeufin = false;

                                continuer = 0;
                                win = 0;
                                quitter = 1;

                        }
                        if(mode == 3)
                        {
                                final = false;
                                jeufin = true;

                                continuer = 0;
                                quitter = 1;
                                win = 0;


                        break;
                    default:
                        break;
                }
                break;
        }
    }
}
}

void Final_MouvementEvent(SDL_Event &event,int & continuer, int & win, int & bombepos, Bombe *bombe,int & quitter, SDL_Surface * personnage[4], SDL_Surface *& persoactuel, const Terrain &jeu, Bomberman &perso, SDL_Surface *ecran, SDL_Surface *mpause[3], bool &jeufin, SDL_Rect &menpos)
{       event.type = (Uint8) NULL;

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
                            Final_MenuPause(mpause,ecran,menpos,jeufin,quitter,continuer,win,event);

                        break;


                    default:
                        break;
                }

                break;
        }
}


void Final_TestInitBombe(int &initb, int & init_a, Bombe *& bombe)
{
    if(initb)
        {
                bombe = Bombe_InitialisationBombe();
                initb = 0;
                init_a = 1;

        }
}

void Final_PoseBombe(int &poser, Bombe *& bombe,  Terrain &jeu, const Bomberman &perso, int &init_a, int &initb, int &bombepos)
{
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
}

void Final_ExplosionBombe(int &poser,int &perte_v,int &explosion,int &temps_explosion,int &initb, int &possible_mb, Bombe *& bombe, Bomberman &perso, Terrain &jeu, dEnnemi &mechant, int &init_a)
{
        if(poser)
        {
            int tempsac = SDL_GetTicks();
            if(tempsac - bombe->temps >= 2500) // On explose la bombe
            {
                poser = 0;
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
}


void Final_AffichageExplosion(int &explosion, const int & temps_explosion,int &perte_v, Terrain &jeu)
{
        Case * cases;
        if(explosion && SDL_GetTicks() - temps_explosion >= 500)
        {
             for(int i=0;i<=jeu.dim-1;i++)//y
            {
                for(int j=0;j<=jeu.dim-1;j++)//x
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
}

void Final_AffichageEnnemis(const dEnnemi &mechant, SDL_Rect &posennemi, SDL_Surface *& ennemiact, SDL_Surface * ennemi[4],SDL_Surface *& ecran, char *en_dir, int * tab)
{
    for(int i=0;i<=2*(mechant.liste_en.nb_en)-1;i=i+2)
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
}


void Final_TestFinaux(dEnnemi &mechant, Bomberman &perso,Terrain &jeu,int &win,int &niveau, int &vie_niveau, int &perte_v, int &continuer, int &dead, Case * touche_explosion)
{
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
}

void Final_MouvementEnnemis(dEnnemi &mechant,const Jeu &bombermangame, Terrain &jeu)
{
         int entime = SDL_GetTicks();
         if(entime - mechant.time >= bombermangame.temps_mouvement)
         {
             dEnnemi_Mouvement(mechant,jeu);
             mechant.time = entime;
         }
}

void Final_LiberationMemoire(SDL_Surface * ecran, SDL_Surface * menu, SDL_Surface * gameover, SDL_Surface *nombre[10],SDL_Surface *terrain, SDL_Surface *bombes, SDL_Surface *mursolide, SDL_Surface * explode, SDL_Surface * mur,SDL_Surface *fond, SDL_Surface *personnage[4],SDL_Surface *ennemi[4], SDL_Surface *load[5],SDL_Surface * menufin[2], SDL_Surface *mpause[3])
{
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
    for(int i=0;i<5;i++)
    {
        SDL_FreeSurface(load[i]);
    }
    SDL_FreeSurface(menufin[0]);
    SDL_FreeSurface(menufin[1]);
    SDL_FreeSurface(mpause[0]);
    SDL_FreeSurface(mpause[1]);
    SDL_FreeSurface(mpause[2]);
}

void Final_AllocationLoad(SDL_Surface *load[5])
{

    load[0]=SDL_LoadBMP("Menu/load/load1.bmp");
    load[1]=SDL_LoadBMP("Menu/load/load2.bmp");
    load[2]=SDL_LoadBMP("Menu/load/load3.bmp");
    load[3]=SDL_LoadBMP("Menu/load/load4.bmp");
    load[4]=SDL_LoadBMP("Menu/load/load5.bmp");
}

void Final_ChargementEntreNiveau(SDL_Surface *load[5], SDL_Surface *&ecran)
{
        SDL_Rect posload;
        Final_AllocationValeurRect(posload,0,0);
        SDL_BlitSurface(load[0], NULL, ecran, &posload);
        int tempsboucle = SDL_GetTicks();
        while( SDL_GetTicks() - tempsboucle < 6000)
        {
                if(SDL_GetTicks() - tempsboucle < 2000 && SDL_GetTicks() - tempsboucle > 1000)
                {
                    SDL_BlitSurface(load[1], NULL, ecran, &posload);
                }
                if(SDL_GetTicks() - tempsboucle < 3000 && SDL_GetTicks() - tempsboucle > 2000)
                {
                    SDL_BlitSurface(load[2], NULL, ecran, &posload);
                }

                if(SDL_GetTicks() - tempsboucle < 4000 && SDL_GetTicks() - tempsboucle > 3000)
                {
                    SDL_BlitSurface(load[3], NULL, ecran, &posload);
                }

                if(SDL_GetTicks() - tempsboucle < 5000 && SDL_GetTicks() - tempsboucle > 4000)
                {
                    SDL_BlitSurface(load[4], NULL, ecran, &posload);
                }

                if(SDL_GetTicks() - tempsboucle < 6000 && SDL_GetTicks() - tempsboucle > 5000)
                {
                    SDL_BlitSurface(load[4], NULL, ecran, &posload);
                }
                SDL_Flip(ecran);
        }
        SDL_Delay(1000);

}

void Final_MenuFin(SDL_Event &event, SDL_Surface *menufin[2],SDL_Rect &menpos, SDL_Surface *ecran, bool &jeufin)
{
      bool final=true;
      SDL_BlitSurface(menufin[0], NULL, ecran, &menpos);
      SDL_Flip(ecran);
      int mode = 1;


      while(final)
        {
        event.type = (Uint8) NULL;


        SDL_WaitEvent(&event); /* Récupèration de l'évènement dans event */
        switch(event.type) /* Test du type d'évènement */
        {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP:
                        mode=1;
                        SDL_BlitSurface(menufin[0], NULL, ecran, &menpos);
                        SDL_Flip(ecran);
                        break;
                    case SDLK_DOWN:
                        mode=2;
                        SDL_BlitSurface(menufin[1], NULL, ecran, &menpos);
                        SDL_Flip(ecran);
                        break;
                    case SDLK_SPACE:
                        if(mode == 1)
                        {
                                final = false;
                        }
                        if(mode == 2)
                        {
                                final = false;
                                jeufin = true;
                        }
                        break;
                    default:
                        break;
                }
                break;
        }
    }

}


void Final_AllocationMenuFin(SDL_Surface * menufin[2])
{
    menufin[0]=SDL_LoadBMP("Menu/menuf/1.bmp");
    menufin[1]=SDL_LoadBMP("Menu/menuf/2.bmp");

}

void Final_AllocationMenuPause(SDL_Surface * mpause[3])
{
    mpause[0]=SDL_LoadBMP("Menu/pause/1.bmp");
    mpause[1]=SDL_LoadBMP("Menu/pause/2.bmp");
    mpause[2]=SDL_LoadBMP("Menu/pause/3.bmp");

}

