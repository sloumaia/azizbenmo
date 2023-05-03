#ifndef HEADER_H
#define HEADER_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 1397
#define SCREEN_W 1858




typedef struct 
{
	char * url ;
	SDL_Rect pos_img_affiche;
	SDL_Rect pos_img_ecran;
	SDL_Surface *img;

}image;
typedef struct
{
	SDL_Surface *txt;
	SDL_Rect pos_txt;
	SDL_Colour color_txt;
	TTF_Font *police;
}texte;


void initBackground(image *imge);
void initBtn1(image *imgbtn);
void initBtn2(image *imgbtn);
void initBtn3(image *imgbtn);
void initBtn5(image *imgbtn);
void initBtn6(image *imgbtn);
void initBtn7(image *imgbtn);
void initBtn4(image *imgbtn);
void afficher_image_back(SDL_Surface *screen ,image imge);
void afficher_image_btn(SDL_Surface *screen ,image imge);


void liberer_image(image imge);


void init_audio(Mix_Music *music);
void liberer_audio(Mix_Music *music); 

void init_audiobref(Mix_Chunk *music);
void liberer_audiobre(Mix_Chunk *music); 

void init_texte(texte *txte);
void afficher_texte(SDL_Surface *screen ,texte txte);
void liberer_texte(texte txte); 
void Settings(SDL_Surface *screen, int *Mode);
void NewGame(SDL_Surface *screen);

#endif




