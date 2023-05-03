#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "header.h"


void initBackground(image *imge)
{
imge->url="0.png";
imge->img= IMG_Load(imge->url);
	if(imge->img==NULL){
		printf("Unable to load imge : %s\n",SDL_GetError());
		return;
}
	imge->pos_img_ecran.x=0;
	imge->pos_img_ecran.y=0;
	imge->pos_img_affiche.x=0;
	imge->pos_img_affiche.y=0;
	imge->pos_img_affiche.w=SCREEN_W ;
	imge->pos_img_affiche.h=SCREEN_H;
}






void initBtn1(image *imgbtn)
{
	imgbtn->url="2.png";
	imgbtn->img = IMG_Load(imgbtn->url);
		if (imgbtn->img== NULL){
			printf("unable to load background imge :%s",SDL_GetError());
			return;
				}

	imgbtn->pos_img_ecran.x=270;
	imgbtn->pos_img_ecran.y=200;

}
void initBtn5(image *imgbtn)
{
	imgbtn->url="5.png";
	imgbtn->img = IMG_Load(imgbtn->url);
		if (imgbtn->img== NULL){
			printf("unable to load background imge :%s",SDL_GetError());
			return;
				}

	imgbtn->pos_img_ecran.x=270;
	imgbtn->pos_img_ecran.y=200;

}
void initBtn6(image *imgbtn)
{
	imgbtn->url="6.png";
	imgbtn->img = IMG_Load(imgbtn->url);
		if (imgbtn->img== NULL){
			printf("unable to load background imge :%s",SDL_GetError());
			return;
				}

	imgbtn->pos_img_ecran.x=270;
	imgbtn->pos_img_ecran.y=300;

}
void initBtn7(image *imgbtn)
{
	imgbtn->url="7.png";
	imgbtn->img = IMG_Load(imgbtn->url);
		if (imgbtn->img== NULL){
			printf("unable to load background imge :%s",SDL_GetError());
			return;
				}

	imgbtn->pos_img_ecran.x=270;
	imgbtn->pos_img_ecran.y=400;

}

void initBtn2(image *imgbtn)
{
	imgbtn->url="3.png";
	imgbtn->img = IMG_Load(imgbtn->url);
		if (imgbtn->img== NULL){
			printf("unable to load background imge :%s",SDL_GetError());
			return;
				}
	
	imgbtn->pos_img_ecran.x=270;
	imgbtn->pos_img_ecran.y=300;
}

void initBtn3(image *imgbtn)
{
	imgbtn->img = IMG_Load("4.png");
		if (imgbtn->img== NULL){
printf("unable to load background imge :%s",SDL_GetError());
			return;
				}
	imgbtn->pos_img_ecran.x=270;
	imgbtn->pos_img_ecran.y=400;
}


void afficher_image_back(SDL_Surface *screen ,image imge)
{
SDL_BlitSurface(imge.img , &imge.pos_img_affiche , screen , &imge.pos_img_ecran );
}

void afficher_image_btn(SDL_Surface *screen ,image imge)
{
SDL_BlitSurface(imge.img , NULL , screen , &imge.pos_img_ecran );	

}


void liberer_image(image imge)
{SDL_FreeSurface(imge.img);
}


void init_audio(Mix_Music *music)
{
if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{printf("%s",SDL_GetError());}
music=Mix_LoadMUS("music.mp3");
Mix_PlayMusic(music,-1);
Mix_VolumeMusic(MIX_MAX_VOLUME/3.5);
}

void liberer_audio(Mix_Music *music)
{
	Mix_FreeMusic(music);
}



void init_audiobref(Mix_Chunk *music)
{

Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
music=Mix_LoadWAV("aziz.wav");
Mix_PlayChannel(-1,music,0);
if (music==NULL)printf("%s",SDL_GetError());
}


void liberer_audiobre(Mix_Chunk *music)
{
	Mix_FreeChunk(music);
}


void init_texte(texte *txte)
{
	TTF_Init();
	txte->police=TTF_OpenFont("Ubuntu-BoldItalic.ttf",45);
	txte->color_txt.r=192;
	txte->color_txt.g=192;
	txte->color_txt.b=192;
	
	txte->pos_txt.x=80;
	txte->pos_txt.y=85;
}


void afficher_texte(SDL_Surface *screen, texte txte)
{
txte.txt=TTF_RenderText_Blended(txte.police , "only the bravest can survive",txte.color_txt);
SDL_BlitSurface(txte.txt,NULL,screen,&txte.pos_txt);
}

void liberer_texte(texte txte)
{
	TTF_CloseFont(txte.police);
	TTF_Quit();

}

void Settings(SDL_Surface *screen, int *Mode)
{
   
    SDL_Surface *Seting = NULL;//backgroud

    SDL_Rect positionSeting;

    SDL_Surface *Option = NULL;

    SDL_Rect positionOption;

    SDL_Surface *Plus = NULL;
    SDL_Surface *plus = NULL;

    SDL_Rect positionPlus;

    SDL_Surface *Moins = NULL;
    SDL_Surface *moins = NULL;

    SDL_Rect positionMoins;

    SDL_Surface *Normal = NULL;
    SDL_Surface *FullScreen = NULL;

    SDL_Rect positionFullscreen;


    SDL_Surface *full_screnn = NULL;

    SDL_Rect positionfull_screnn;

    SDL_Surface *Quit = NULL;

    SDL_Rect positionQuit;

    SDL_Event event;

    int continuer = 1;
    int volume = 128;
    int niv_volume = 1;

    
    Seting = IMG_Load("0.png");
    screen = SDL_SetVideoMode(756, 540, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("SETTINGS", NULL);
    positionSeting.x = 0;
    positionSeting.y = 0;
    
    Option = IMG_Load("Settings/Option.png");
    positionOption.x =180;
    positionOption.y =100;
    
    Moins = IMG_Load("Settings/Moins.png");
    moins = IMG_Load("Settings/moins.png");
    positionMoins.x =260;
    positionMoins.y = 210;
    
    Plus = IMG_Load("Settings/Plus.png");
    plus = IMG_Load("Settings/plus.png");
    positionPlus.x = 510;
    positionPlus.y = 210;
    
    Normal = IMG_Load("Settings/Normal.png");
    FullScreen = IMG_Load("Settings/Fullscreen.png");
    positionFullscreen.x = 380;
    positionFullscreen.y = 300;
    
    Quit = IMG_Load("Settings/Quit.png");
    positionQuit.x =546;
    positionQuit.y = 140;
    
    full_screnn = IMG_Load("Settings/full screnn.png");
    positionfull_screnn.x =290;
    positionfull_screnn.y =250;
    //SDL_EnableKeyRepeat(0, 50);

    while (continuer)
    {

      SDL_WaitEvent(&event);
      switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            if (*Mode == 0)
            {
                SDL_BlitSurface(Quit, NULL, screen, &positionQuit);
                SDL_Flip(screen);
                screen = SDL_SetVideoMode(756, 540, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
            }
            else
            {
                screen = SDL_SetVideoMode(756, 540, 32, SDL_HWSURFACE | SDL_FULLSCREEN);
                SDL_Flip(screen);
            }
            SDL_WM_SetCaption("war of mine", NULL);
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer = 0;
                if (*Mode == 0)
                {
                    SDL_BlitSurface(Quit, NULL, screen, &positionQuit);
                    SDL_Flip(screen);
                    screen = SDL_SetVideoMode(756, 540, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                }
                else
                {
                    screen = SDL_SetVideoMode(756, 540, 32, SDL_HWSURFACE | SDL_FULLSCREEN);
                    SDL_Flip(screen);
                }

                  SDL_WM_SetCaption("Game Menu", NULL);
                break;
            case SDLK_LEFT:
                if (niv_volume == 1)
                {
                    niv_volume = 2;
                    Mix_VolumeMusic(volume / 2);
                    volume = volume / 2;
                }
                else if (niv_volume == 2)
                {
                    niv_volume = 3;
                    Mix_VolumeMusic(volume / 2);
                    volume = volume / 2;
                }
                else if (niv_volume == 3)
                {
                    niv_volume = 4;
                    Mix_VolumeMusic(volume / 2);
                    volume = volume / 2;
                }
                else if (niv_volume == 4)
                {
                    niv_volume = 5;
                    Mix_VolumeMusic(0);
                    volume = 0;
                }
                SDL_BlitSurface(Moins, NULL, screen, &positionMoins);
                SDL_Flip(screen);
                break;
            case SDLK_RIGHT:
                if (niv_volume == 5)
                {
                    niv_volume = 6;
                    volume = 16;
                    Mix_VolumeMusic(volume);
                }
                else if (niv_volume == 6)
                {
                    niv_volume = 7;
                    volume = volume * 2;
                    Mix_VolumeMusic(volume);
                }
                else if (niv_volume == 7)
                {
                    niv_volume = 8;
                    volume = volume * 2;
                    Mix_VolumeMusic(volume);
                }
                else if (niv_volume == 8)
                {
                    niv_volume = 1;
                    volume = volume * 2;
                    Mix_VolumeMusic(volume);
                }
                SDL_BlitSurface(Plus, NULL, screen, &positionPlus);
                SDL_Flip(screen);
                break;
            case SDLK_f:
                *Mode = 1;
                screen = SDL_SetVideoMode(1000, 540, 32, SDL_HWSURFACE | SDL_FULLSCREEN);
                SDL_BlitSurface(FullScreen, NULL, screen, &positionFullscreen);
              
                SDL_Flip(screen);
                break;
            case SDLK_n:
                *Mode = 0;
                screen = SDL_SetVideoMode(756, 540, 32, SDL_HWSURFACE | SDL_ANYFORMAT);
                SDL_BlitSurface(Normal, NULL, screen, &positionFullscreen);
                SDL_Flip(screen);
                break;
            }
            break;
        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                if (event.button.x > 260 && event.button.x < 380 && event.button.y > 210 && event.button.y < 330)
                {
                    if (niv_volume == 1)
                    {
                        niv_volume = 2;
                        Mix_VolumeMusic(volume / 2);
                        volume = volume / 2;
                    }
                    else if (niv_volume == 2)
                    {
                        niv_volume = 3;
                        Mix_VolumeMusic(volume / 2);
                        volume = volume / 2;
                    }
                    else if (niv_volume == 3)
                    {
                        niv_volume = 4;
                        Mix_VolumeMusic(volume / 2);
                        volume = volume / 2;
                    }
                    else if (niv_volume == 4)
                    {
                        niv_volume = 5;
                        Mix_VolumeMusic(0);
                        volume = 0;
                    }
                    SDL_BlitSurface(Moins, NULL, screen, &positionMoins);
                    SDL_Flip(screen);
                }
                else if (event.button.x > 610 && event.button.x < 730 && event.button.y > 210 && event.button.y < 330)
                {
                    if (niv_volume == 5)
                    {
                        niv_volume = 6;
                        volume = 16;
                        Mix_VolumeMusic(volume);
                    }
                    else if (niv_volume == 6)
                    {
                        niv_volume = 7;
                        volume = volume * 2;
                        Mix_VolumeMusic(volume);
                    }
                    else if (niv_volume == 7)
                    {
                        niv_volume = 8;
                        volume = volume * 2;
                        Mix_VolumeMusic(volume);
                    }
                    else if (niv_volume == 8)
                    {
                        niv_volume = 1;
                        volume = volume * 2;
                        Mix_VolumeMusic(volume);
                    }
                    SDL_BlitSurface(Plus, NULL, screen, &positionPlus);
                    SDL_Flip(screen);
                }
                else if (event.button.x > 350 && event.button.x < 400 && event.button.y > 280 && event.button.y < 320)
                {
                    *Mode = 1;
                    screen = SDL_SetVideoMode(1000, 540, 32, SDL_HWSURFACE | SDL_FULLSCREEN);
                    SDL_BlitSurface(FullScreen, NULL, screen, &positionFullscreen);
                    SDL_Flip(screen);
                }
                else if (event.button.x > 350 && event.button.x < 400 && event.button.y > 280 && event.button.y < 320)
                {
                    *Mode = 0;
                    screen = SDL_SetVideoMode(756, 542, 32, SDL_HWSURFACE | SDL_ANYFORMAT);
                    SDL_BlitSurface(Normal, NULL, screen, &positionFullscreen);
                    SDL_Flip(screen);
                }
                else if (event.button.x >530 && event.button.x < 560 && event.button.y > 100&& event.button.y < 180)
                {
                    continuer = 0;
                    if (*Mode == 0)
                    {
                        SDL_BlitSurface(Quit, NULL, screen, &positionQuit);
                        SDL_Flip(screen);
                        screen = SDL_SetVideoMode(756, 542, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                    }
                    else
                    {
                        screen = SDL_SetVideoMode(756, 542, 32, SDL_HWSURFACE | SDL_FULLSCREEN);
                        SDL_Flip(screen);
                    }
                    break;
                }
            }
            break;
        }
        SDL_BlitSurface(Seting, NULL, screen, &positionSeting);
        SDL_BlitSurface(Option, NULL, screen, &positionOption);
        SDL_BlitSurface(full_screnn, NULL, screen, &positionfull_screnn);
        SDL_BlitSurface(moins, NULL, screen, &positionMoins);
        SDL_BlitSurface(plus, NULL, screen, &positionPlus);
        if (*Mode == 0)
        {
           
          SDL_BlitSurface(Normal, NULL, screen, &positionFullscreen);
        }
        else
        {

            SDL_BlitSurface(FullScreen, NULL, screen, &positionFullscreen);
        }
        SDL_Flip(screen);
    }
    SDL_FreeSurface(Seting);
    SDL_FreeSurface(Option);
    SDL_FreeSurface(Moins);
    SDL_FreeSurface(moins);
    SDL_FreeSurface(Plus);
    SDL_FreeSurface(plus);
    SDL_FreeSurface(Normal);
    SDL_FreeSurface(FullScreen);
    SDL_FreeSurface(Quit);
}
void NewGame(SDL_Surface *screen)
{
    SDL_Surface *NGame = NULL;

    SDL_Rect positionNGame;

    SDL_Event event;

    int continuer = 1;

    NGame = IMG_Load("newgame.JPG");
    screen = SDL_SetVideoMode(750, 500, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("NEW GAME", NULL);

    positionNGame.x = 0;
    positionNGame.y = 0;
    while (continuer)
    {
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer = 0;
                screen = SDL_SetVideoMode(756, 540, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                SDL_WM_SetCaption("you are welcome", NULL);
                break;
            }
            break;
        }

        SDL_BlitSurface(NGame, NULL, screen, &positionNGame);
        SDL_Flip(screen);
    }
    SDL_FreeSurface(NGame);
}





