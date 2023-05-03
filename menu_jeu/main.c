#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "perso.h"

int main()
{

SDL_Surface *back;
SDL_Surface *coll;
perso p;
perso p2;
int continuer=1,droite=0,gauche=0,up=0,dir=2,droite2=0,gauche2=0,up2=0,dir2=2;
Uint32 dt, t_prev;
TTF_Init();

TTF_Font *police=NULL;
SDL_Surface *aziz=NULL;
SDL_Surface *number1=NULL;

	texte txte,socer;














///////////////////////////////////

SDL_Surface *screen;
	image imgbtn1,imgbtn2,imgbtn3,imge,imgbtn4,imgbtn5,imgbtn6,imgbtn7;
	Mix_Music *music;
	Mix_Chunk *mus;	
	texte txte1;
	SDL_Event event;	
	int done=1;	
	TTF_Init();
	  int Mode = 0;
	
	
        
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
	{printf("could not initiailize sdl :%s .\n",SDL_GetError());return -1;}
	
           SDL_WM_SetIcon(IMG_Load("icon.png"), NULL);
	screen=SDL_SetVideoMode(756,534,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	initBackground(&imge);
	initBtn1(&imgbtn1);
	initBtn2(&imgbtn2);
	initBtn3(&imgbtn3);
	initBtn5(&imgbtn5);
	initBtn6(&imgbtn6);
	initBtn7(&imgbtn7);
	init_audio(music);
	init_texte(&txte1);
/////////////////////////
initPerso(&p);
initPerso2(&p2);
////////////////////
	

	while(done){
	afficher_image_back(screen ,imge);
	afficher_image_btn(screen ,imgbtn1);
	afficher_image_btn(screen ,imgbtn2);
	afficher_image_btn(screen ,imgbtn3);
	afficher_texte(screen,txte1);
////////////////////

/////////////////
	while   (SDL_PollEvent(&event))
{	
	switch(event.type)
{
	case SDL_QUIT:
	done=0;
	break;
	case SDL_MOUSEBUTTONDOWN:
	if (event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=460 && event.motion.y>=400&& event.motion.x<=460 && event.motion.x>=270 ))
	done=0;
else
if(event.motion.y<=260&&event.motion.y>=200&&(event.motion.x<=450&&event.motion.x>=270))
    //NewGame(screen);

///////////////////////////

{

screen=SDL_SetVideoMode (1200,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_Init(SDL_INIT_VIDEO);
SDL_WM_SetCaption("perso aziz",NULL);
back=IMG_Load("1.jpg");

/////////score
police= TTF_OpenFont("avocado.ttf", 35);

SDL_Color blanco={105,6,203}; 
aziz=TTF_RenderText_Blended(police,"score :",blanco);
p.position_textee.x=15;
p.position_textee.y=10;

p.number[1];
p.valeur_score=0;








while (done)
{
///////tb3in score
p.number[1];
p.valeur_score++;
sprintf(p.number, "%d",(p.valeur_score));
number1= TTF_RenderText_Blended(police,p.number,blanco);
p.position_number.x=150;
p.position_number.y=10;



t_prev=SDL_GetTicks();


while(SDL_PollEvent(&event))
{
    switch (event.type)
    {
    case SDL_QUIT:
        done=0;
        break;

    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
case SDLK_ESCAPE:
                continuer = 0;
                screen = SDL_SetVideoMode(756, 540, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);





            case SDLK_RIGHT:
                droite=1;
                break;
            case SDLK_LEFT:
                gauche=1;
                break;
            case SDLK_UP:
                up=1;
                break;  

         case SDLK_d:
                droite2=1;
                break;
            case SDLK_q:
                gauche2=1;
                break;
            case SDLK_z:
                up2=1;
                break; 

      
        }
    break;

    case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                droite=0;
                dir=2;
                p.vitesse=0;
                break;
            case SDLK_LEFT:
                gauche=0;
                p.vitesse=0;
                dir=3;
                break;
            case SDLK_UP:
                up=0;
                break;    

           case SDLK_d:
                droite2=0;
                dir2=2;
                p2.vitesse=0;
                break;
            case SDLK_q:
                gauche2=0;
                p2.vitesse=0;
                dir2=3;
                break;
            case SDLK_z:
                up2=0;
                break; 

    
        }
    break;
    
    }
}
           	





if (droite==1)
{
    p.vitesse=10;
    p.acceleration+=0.5;
    p.direction=0;


}
if (gauche==1)
{
    p.vitesse=10;
    p.acceleration+=0.5;
    p.direction=1;

}
if (up==1){ 
saut(&p);

}
if (droite2==1)
{
    p2.vitesse=10;
    p2.acceleration+=0.5;
    p2.direction=0;
}
if (gauche2==1)
{
    p2.vitesse=10;
    p2.acceleration+=0.5;
    p2.direction=1;
}
if (up2==1) 
{
saut(&p2);
}


p.acceleration -=0.3;
p2.acceleration -=0.3;
if (p.acceleration<0 ) p.acceleration=0;
if (p.acceleration>4) p.acceleration=4;



if (p2.acceleration<0 ) p2.acceleration=0;
if (p2.acceleration>4 ) p2.acceleration=4;

SDL_Delay(1);
dt = SDL_GetTicks() - t_prev;
deplacerPerso(&p,dt);
animerPerso(&p);
deplacerPerso(&p2,dt);
animerPerso(&p2);

if ((p.vitesse==0)&&(p.acceleration==0))
{
    p.direction=dir;
}

p.position.y += p.vitesseV;
p.vitesseV += 10; 
if (p.position.y >= 355)
{
    p.vitesseV=0;
    p.position.y=355;
}

if ((p2.vitesse==0)&&(p2.acceleration==0))
{
    p2.direction=dir2;
}

p2.position.y += p2.vitesseV;
p2.vitesseV += 10; 
if (p2.position.y >= 355)
{
    p2.vitesseV=0;
    p2.position.y=355;
}





SDL_BlitSurface(back,NULL,screen,NULL);
SDL_BlitSurface(aziz,NULL,screen,&(p.position_textee));




SDL_BlitSurface(number1, NULL, screen,&p.position_number);
afficherPerso(p,screen);
afficherPerso(p2,screen);
  SDL_Flip(screen); 

SDL_Delay(50);
        }
SDL_FreeSurface(back);
SDL_FreeSurface(p.spritesheet);
        liberer_texte(txte);
SDL_FreeSurface(p2.spritesheet);
	SDL_Quit();













































}

////////////////////////////////////////
else
if(event.motion.y<=360&&event.motion.y>=300&&(event.motion.x<=450&&event.motion.x>=270))
 Settings(screen, &Mode);
	break;

case SDL_MOUSEMOTION:
if(event.motion.y<=260&&event.motion.y>=200&&(event.motion.x<=450&&event.motion.x>=270))
afficher_image_btn(screen ,imgbtn5);
SDL_Flip(screen);

init_audiobref(mus);




if(event.motion.y<=360&&event.motion.y>=300&&(event.motion.x<=450&&event.motion.x>=270))
afficher_image_btn(screen ,imgbtn6);
SDL_Flip(screen);
init_audiobref(mus);


if(event.motion.y<=460&&event.motion.y>=400&&(event.motion.x<=450&&event.motion.x>=270))
afficher_image_btn(screen ,imgbtn7);
SDL_Flip(screen);

init_audiobref(mus);
break;





}
}
SDL_Flip(screen);
SDL_Delay(990);
}


 liberer_image(imge);
 liberer_image(imgbtn1);
 liberer_image(imgbtn2);
 liberer_image(imgbtn3);
 liberer_image(imgbtn5);
 liberer_image(imgbtn6);
 liberer_image(imgbtn7);
 
 liberer_texte(txte1);
 init_audio(music);
 init_audiobref(mus);
 SDL_Quit();
	return 0;
}
	
