#include "enemy.h"


void main()
{
    //declare simple variables
    int done = 1;
    enemie f;
	

    bool running=true;
	SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO );

    SDL_Surface *screen, *bg, *hero;

    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("isra", NULL); //window title

    SDL_Rect bgPos,camera;
    bgPos.x = 0;
    bgPos.y = 0;

	camera.x = 1280;
	camera.y= 0;
	camera.w = 1280;
	camera.h = 720;

bg = IMG_Load("Assets/graphic/stages/backgtest.png");


    SDL_Rect heropos;
    heropos.x = 20;
    heropos.y = 480;
    heropos.w=200;
    heropos.h=200;

hero = IMG_Load("Assets/graphic/hero/hero_test.png");


	inisialiser_enemie (&f);

SDL_EnableKeyRepeat(200,0); 

while(running)
{

while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
		done = 0;
		running=false;
		break;
        case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
				case SDLK_ESCAPE:
                
		done = 0;
		running=false;
                break;
                
                case SDLK_RIGHT:
			heropos.x +=30;	
                break;

                case SDLK_LEFT :
				heropos.x -=30;
      		     break;
				case SDLK_UP :
				heropos.y -=30;
				break;
				case SDLK_DOWN :
				heropos.y +=30;

			}
		break;

	    }
    }


update_ennemi(&f , screen , heropos );
moveIA(&f, screen, heropos);
SDL_BlitSurface(bg, &camera, screen, &bgPos);
SDL_BlitSurface(hero, NULL, screen, &heropos);
afficher_enemie (&f,screen);


SDL_Flip(screen);
SDL_Delay(16);

}

SDL_FreeSurface(screen);
SDL_Quit();
}
