#include <stdlib.h>
#include <iostream>
#include "bombe.h"
#include <time.h>

bool Bombe_posebombe(Bombe &b, const int &posx, const int &posy,Terrain &t, const int &rayon)
{
   if (posx>=0 && posy>=0 )
   {
        Case *n;
        n = Terrain_Getcase(t,posx,posy);
        if(strcmp(n->carre,"mursolide") && strcmp(n->carre, "mur"))
        {
            b.x = posx;
            b.y = posy;
            b.r_exp = rayon;
            }else return false;
       }else return false;
    return true;
}

void Bombe_minuteur(const int &tmp)
{
        sleep(tmp);
}

void Bombe_ExplosionSurTerrain(const Bombe &b,Terrain &t)
{
    int i;
    Case *m;
// Test sur x>0
    for(i=1;i<=b.r_exp;i++)
    {
      m = Terrain_Getcase(t,b.x+i,b.y);
      if(strcmp(m->carre,"mursolide") == 0)
      {
        i=b.r_exp+1;
      }else{ if(strcmp(m->carre,"mur") == 0)
            {
                Case p;
                Case_initialisation(p);
                Terrain_Setcase(t,p,b.x+i,b.y);
                i=b.r_exp+1;
                }

        }
    }
// Test sur x<0
    if(b.x >= b.r_exp)
    {
        for(i=1;i<=b.r_exp;i++)
        {
        m = Terrain_Getcase(t,b.x-i,b.y);
        if(strcmp(m->carre,"mursolide") == 0)
        {
            i=b.r_exp+1;
        }else{ if(strcmp(m->carre,"mur") == 0)
                {
                    Case p;
                    Case_initialisation(p);
                    Terrain_Setcase(t,p,b.x-i,b.y);
                    i=b.r_exp+1;
                    }
            }
        }
    }
// Test sur y>0
    for(i=1;i<=b.r_exp;i++)
    {
      m = Terrain_Getcase(t,b.x,b.y+i);
      if(strcmp(m->carre,"mursolide") == 0)
      {
        i=b.r_exp+1;
      }else{ if(strcmp(m->carre,"mur") == 0)
            {
                Case p;
                Case_initialisation(p);
                Terrain_Setcase(t,p,b.x,b.y+i);
                i=b.r_exp+1;
                }
        }
    }

// Test sur y<0
    if(b.x >= b.r_exp)
    {
        for(i=1;i<=b.r_exp;i++)
        {
        m = Terrain_Getcase(t,b.x,b.y-i);
        if(strcmp(m->carre,"mursolide") == 0)
        {
            i=b.r_exp+1;
        }else{ if(strcmp(m->carre,"mur") == 0)
                {
                    Case p;
                    Case_initialisation(p);
                    Terrain_Setcase(t,p,b.x,b.y-i);
                    i=b.r_exp+1;
                    }
            }
        }
    }
}

void Bombe_bombe(Bombe &b, Terrain &t, const int &x, const int &y)
{
        if (Bombe_posebombe(b,x,y,t,1))
        {
                Bombe_minuteur(3);
                Case a;
                strcpy(a.carre,"bombe");
                Terrain_Setcase(t,a,x,y);
                Bombe_ExplosionSurTerrain(b,t);
        }
}
