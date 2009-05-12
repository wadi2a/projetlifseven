#include "bombe.h"

Bombe * Bombe_InitialisationBombe()
{
        Bombe * b = new Bombe;
        b->nb=1;
        return b;

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

void Bombe_ExplosionSurTerrain(const Bombe * b,Terrain &t)
{
    int i;
    Case *m;
// Test sur x>0
    for(i=1;i<=b->r_exp;i++)
    {

      if(b->x + i == t.dim  ) break;
      else{

        m = Terrain_Getcase(t,b->x+i,b->y);
        if(strcmp(m->carre,"S") == 0)
        {
            break;
        }else{ if(strcmp(m->carre,"M") == 0)
                {
                    Case p;
                    strcpy(p.carre,"E");
                    Terrain_Setcase(t,p,b->x+i,b->y);
                    break;
                }else{
                    if(strcmp(m->carre,"V") == 0)
                    {
                        Case p;
                        strcpy(p.carre,"E");
                        Terrain_Setcase(t,p,b->x+i,b->y);
                    }
                }

        }

        }
    }
// Test sur x<0


        for(i=1;i<=b->r_exp;i++)
        {
            if(b->x - i < 0) break;
            else{
                m = Terrain_Getcase(t,b->x-i,b->y);
                if(strcmp(m->carre,"S") == 0)
                {
                    break;
                }else{ if(strcmp(m->carre,"M") == 0)
                    {
                        Case p;
                        strcpy(p.carre,"E");
                        Terrain_Setcase(t,p,b->x-i,b->y);
                        break;
                    }else{
                    if(strcmp(m->carre,"V") == 0)
                    {
                        Case p;
                        strcpy(p.carre,"E");
                        Terrain_Setcase(t,p,b->x-i,b->y);
                    }
                }
                }
            }
        }

// Test sur y>0
    for(i=1;i<=b->r_exp;i++)
    {
      if(b->y + i == t.dim  ) break;
      else{
      m = Terrain_Getcase(t,b->x,b->y+i);
      if(strcmp(m->carre,"S") == 0)
      {
        break;
      }else{ if(strcmp(m->carre,"M") == 0)
            {
                Case p;
                strcpy(p.carre,"E");
                Terrain_Setcase(t,p,b->x,b->y+i);
                break;
                }else{
                    if(strcmp(m->carre,"V") == 0)
                    {
                        Case p;
                        strcpy(p.carre,"E");
                        Terrain_Setcase(t,p,b->x,b->y+i);
                    }
                }
        }
      }
    }

// Test sur y<0


        for(i=1;i<=b->r_exp;i++)
        {
            if(b->y - i < 0) break;
      else{
        m = Terrain_Getcase(t,b->x,b->y-i);
        if(strcmp(m->carre,"S") == 0)
        {
            break;
        }else{ if(strcmp(m->carre,"M") == 0)
                {
                    Case p;
                    strcpy(p.carre,"E");
                    Terrain_Setcase(t,p,b->x,b->y-i);
                    break;
                    }else{
                        if(strcmp(m->carre,"V") == 0)
                        {
                            Case p;
                            strcpy(p.carre,"E");
                            Terrain_Setcase(t,p,b->x,b->y-i);
                        }
                    }
            }
        }
        }

    Case a;
    strcpy(a.carre,"E");
    Terrain_Setcase(t,a,b->x,b->y);
}

bool Bombe_bombe(Bombe * b, Terrain &t, const int &x, const int &y,const int &time)
{
        if (Bombe_posebombe(b,x,y,t,2))
        {
                Case a;
                strcpy(a.carre,"B");
                Terrain_Setcase(t,a,x,y);
                b->temps = time;
                return true;
        }
        return false;
}

void Bombe_testament(Bombe *b)
{
        delete b;
}
