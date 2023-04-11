#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include<SDL/SDL_getenv.h>
#include "SDL/SDL_mixer.h"
#include "fonction.h"

void initmap(Minimap *m)
{
m->image_miniature=IMG_Load("2.png");
    if (m->image_miniature==NULL)
    {
       return;
    }
m->pos_minimap.x=1000;
m->pos_minimap.y=0;
m->pos_minimap.w=1333;
m->pos_minimap.h=377;

m->image_bonhomme=IMG_Load("unnamed.png");
    if (m->image_bonhomme==NULL)
    {
       return;
    }
m->pos_bonhomme.x=0;
m->pos_bonhomme.y=60;
m->pos_bonhomme.w=11;
m->pos_bonhomme.h=11;
}

void afficherminimap (Minimap m, SDL_Surface * screen)
{
SDL_BlitSurface(m.image_miniature,NULL,screen,&m.pos_minimap);
SDL_BlitSurface(m.image_bonhomme,NULL,screen,&m.pos_bonhomme);
}

void affichertemps (Temps temps, SDL_Surface *screen) 
{
    char temps_str[10];
TTF_Font*police;
police=TTF_OpenFont("Aa.ttf",45);
if (police==NULL)
    printf ("erreur");
    sprintf(temps_str, "%02d:%02d:%02d", temps.heures, temps.minutes, temps.secondes);
    SDL_Color blanc = {255, 255, 255};
    SDL_Surface *texte = TTF_RenderText_Blended(police, temps_str, blanc);
    
    SDL_Rect pos ;
    pos.x = screen->w - texte->w - 10; 
    pos.y = 10; 
    SDL_BlitSurface(texte, NULL, screen, &pos);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);
}
/*/

SDL_Color getpixel(SDL_Surface *pSurface,int x,int y)//lezem n3dilha el masque 5tr hia fih elloun ak7el //mini
{	
	SDL_Color color;
	Uint32 col=0;
	char* pPosition=(char* ) pSurface->pixels;
	pPosition+= (pSurface->pitch * y);
	pPosition+= (pSurface->format->BytesPerPixel *x);
	memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
	SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
	return (color);
}
int  collisionparfaite(SDL_Surface *psurface,Personne p)
{	
	int tabx[7],taby[7],i;//7atit les position de x fi tableau mta3 x o hatit les position mat3 y fi tableau mta3 y o 3mlt coleur chntstih bih
	SDL_Color color1,color;//color lil test 
	color1.r = 0;
	color1.g = 0;
	color1.b = 0;
	tabx[0]=p.pos_perso.x;
	tabx[1]=(p.pos_perso.x)+((p.pos_perso.w)/2);
	tabx[2]=(p.pos_perso.x+p.pos_perso.w);
	tabx[3]=p.pos_perso.x;
	tabx[4]=p.pos_perso.x;
	tabx[5]=(p.pos_perso.x)+((p.pos_perso.w)/2);
	tabx[6]=(p.pos_perso.x+p.pos_perso.w);
	tabx[7]=(p.pos_perso.x+p.pos_perso.w);
	taby[0]=p.pos_perso.y;
	taby[1]=p.pos_perso.y;
	taby[2]=p.pos_perso.y;
	taby[3]=(p.pos_perso.y)+((p.pos_perso.h)/2);
	taby[4]=(p.pos_perso.y+p.pos_perso.h);
	taby[5]=(p.pos_perso.y+p.pos_perso.h);
	taby[6]=(p.pos_perso.y+p.pos_perso.h);
	taby[7]=(p.pos_perso.y)+((p.pos_perso.h)/2);
	
	for(i=0;i<8;i++)
	{
	color=getpixel(psurface,tabx[i],taby[i]);//trj3lik el coleur ili inty fih 
	if(color.r==color1.r && color.b==color1.b && color.g==color1.g)
	{
		return i;//trj3li indice win saret collision 

	}
	}
	return 10;//maasartch collision kain raja3li 1
	
}	

void collision(SDL_Surface *psurface,Personne *p)//il suffit saret collision scrolling leze nwkfo wktli collisionparfaite traja3 10 ya3ni mfmfch collision 
{	int i;
	i=collisionparfaite(psurface,*p);

	switch (i)//wkt tsir collisision el perso idizo chwya 
	{
		case 0 :p->pos_perso.y=p->pos_perso.y+20;
			break;
		case 1 :p->pos_perso.y=p->pos_perso.y+20;
			 break;
		case 2 :p->pos_perso.y=p->pos_perso.y+20;
			break;
		case 3 :p->pos_perso.x=p->pos_perso.x+20;
			break;
	        case 4 :p->pos_perso.y=p->pos_perso.y-20;
			break;
		case 5 :p->pos_perso.y=p->pos_perso.y-50; 
			break;
		case 6 :p->pos_perso.y=p->pos_perso.y-30; 
			break;
		case 7 :p->pos_perso.x=p->pos_perso.x-20;
			break;
		

	}
}

/*/
SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y)
{
    int m;
    SDL_Color color;
    Uint32 col=0;
    char* pPosition=(char*) pSurface ->pixels;
    pPosition+=(pSurface -> pitch*y);
    pPosition+=(pSurface->format->BytesPerPixel*x);
    memcpy (&col,GetPixel,pSurface->format->BytesPerPixel);
    SDL_GetRGB(col,pSurface->format,&color.r,&color.g,&color.b);
    return (color);
}

int collisionPP( Personne Personne, SDL_Surface * masque)
{
    
    int X,Y,W,H;
    int M;
    SDL_Color 
    Pos1,Pos2,Pos3,Pos4,Pos5,Pos6,Pos7,Pos8;
    X=M.posPersonne.x;
    Y=M.posPersonne.y;
    H=M.posPersonne.h;
    W=M.posPersonne.w;
    Pos1=GetPixel(m.imag2,X,Y);
    Pos2=GetPixel(m.imag2,X+W/2,Y);
    Pos3=GetPixel(m.imag2,X+W,Y);
    Pos4=GetPixel(m.imag2,X,Y+H/2);
    Pos5=GetPixel(m.imag2,X,Y+H);
    Pos6=GetPixel(m.imag2,X+W,Y);
    Pos7=GetPixel(m.imag2,X+W,Y+H);
    Pos8=GetPixel(m.imag2,X+W,Y+H/2);
    if((Pos1.r!=0 || Pos1.g!=0 && Pos1.b!=0) && (Pos2.r!=0 && Pos2.g!=0&&Pos2.b!=0) &&(Pos3.r!=0 && Pos3.g!=0&&Pos3.b!=0)&&
    (Pos4.r!=0 && Pos4.g!=0&&Pos4.b!=0) && (Pos5.r!=0 && Pos5.g!=0&&Pos5.b!=0)&&(Pos6.r!=0 && Pos6.g!=0&&Pos6.b!=0) && (Pos7.r!=0 && Pos7.g!=0&&Pos7.b!=0)&&(Pos8.r!=0 && Pos8.g!=0&&Pos8.b!=0))
    {
        return 1;
    }
    return 0;
}

/*/
void animerminimap(Minimap *m) {
    m->pos_minimap.x += 1;
    if (m->pos_minimap.x > 600) {
        m->pos_minimap.x = 10;
    }
}*/



