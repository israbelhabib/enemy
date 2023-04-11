
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_getenv.h>
#include "SDL/SDL_mixer.h"
#include "fonction.h"

int main (int argc,char argv)
{
SDL_Event event ;
SDL_Init( SDL_INIT_VIDEO );
TTF_Init();
SDL_Surface *screen;
Minimap m;
Temps t;
personne p;

inittemps(&temps);
	inittempsenig(&tempsenig);
	initialiser_map (&m,screen) ;
	initialiserperso(&p);

screen=SDL_SetVideoMode (SCREEN_W, SCREEN_H,32,SDL_HWSURFACE|SDL_SRCALPHA|SDL_DOUBLEBUF|SDL_RESIZABLE);
 initmap(&m);


int boucle=1;
if ( SDL_Init (SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
{
printf ("Could not initialize SDL: %s.\n",SDL_GetError());
return -1;

}
screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_SWSURFACE|SDL_SWSURFACE|SDL_DOUBLEBUF);



while(boucle)
{
afficherminimap ( m, screen);
affichertemps (t, screen);
collisionPP(p, masque);
//animerminimap(&m);
while (SDL_PollEvent(&event))
{
switch (event.type)
{ case SDL_QUIT:
boucle=0;
break;

}
}SDL_Flip(screen);
}
return (0);
}
