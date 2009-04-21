#include "bombe.h"

void Bombe_InitialisationBombe(Bombe *& b)
{
        b = new Bombe;

}

bool Bombe_posebombe(Bombe * b, const int &posx, const int &posy,Terrain &t, const int &rayon)
{
   if (posx>=0 && posy>=0 )
   {
        Case *n;
        n = Terrain_Getcase(t,posx,posy);
        if(strcmp(n->carre,"S") && strcmp(n->carre, "M"))
        {
            b->x = posx;
            b->y = posy;
            b->r_exp = rayon;
            }else return false;
       }else return false;
    return true;
}

void Bombe_minuteur(const int &tmp)
{
        sleep(tmp);
}

void Bombe_ExplosionSurTerrain(const Bombe * b,Terrain &t)
{
    int i;
    Case *m;
// Test sur x>0
    for(i=1;i<=b->r_exp;i++)
    {
      m = Terrain_Getcase(t,b->x+i,b->y);
      if(strcmp(m->carre,"S") == 0)
      {
        i=b->r_exp+1;
      }else{ if(strcmp(m->carre,"M") == 0)
            {
                Case p;
                Case_initialisation(p);
                Terrain_Setcase(t,p,b->x+i,b->y);
                i=b->r_exp+1;
                }

        }
    }
// Test sur x<0
    if(b->x >= b->r_exp)
    {
        for(i=1;i<=b->r_exp;i++)
        {
        m = Terrain_Getcase(t,b->x-i,b->y);
        if(strcmp(m->carre,"S") == 0)
        {
            i=b->r_exp+1;
        }else{ if(strcmp(m->carre,"M") == 0)
                {
                    Case p;
                    Case_initialisation(p);
                    Terrain_Setcase(t,p,b->x-i,b->y);
                    i=b->r_exp+1;
                    }
            }
        }
    }
// Test sur y>0
    for(i=1;i<=b->r_exp;i++)
    {
      m = Terrain_Getcase(t,b->x,b->y+i);
      if(strcmp(m->carre,"S") == 0)
      {
        i=b->r_exp+1;
      }else{ if(strcmp(m->carre,"M") == 0)
            {
                Case p;
                Case_initialisation(p);
                Terrain_Setcase(t,p,b->x,b->y+i);
                i=b->r_exp+1;
                }
        }
    }

// Test sur y<0
    if(b->x >= b->r_exp)
    {
        for(i=1;i<=b->r_exp;i++)
        {
        m = Terrain_Getcase(t,b->x,b->y-i);
        if(strcmp(m->carre,"S") == 0)
        {
            i=b->r_exp+1;
        }else{ if(strcmp(m->carre,"M") == 0)
                {
                    Case p;
                    Case_initialisation(p);
                    Terrain_Setcase(t,p,b->x,b->y-i);
                    i=b->r_exp+1;
                    }
            }
        }
    }
    Case a;
    strcpy(a.carre,"V");
    Terrain_Setcase(t,a,b->x,b->y);
}

void Bombe_bombe(Bombe * b, Terrain &t, const int &x, const int &y)
{
        if (Bombe_posebombe(b,x,y,t,1))
        {
                Case a;
                strcpy(a.carre,"B");
                Terrain_Setcase(t,a,x,y);
                //Bombe_minuteur(3);
                //Bombe_ExplosionSurTerrain(b,t);
        }
}

void Bombe_testament(Bombe *b)
{
        delete b;
}
