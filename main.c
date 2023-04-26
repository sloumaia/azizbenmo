#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#include "perso.h"


int main()
{ 



TTF_Init();
SDL_Surface *screen;
TTF_Font *police=NULL;
SDL_Surface *texte1=NULL;
SDL_Surface *number1=NULL;


TTF_Font *text=NULL;
SDL_Surface *texte=NULL;
TTF_Font *text2=NULL;
SDL_Surface *texte2=NULL;
SDL_Event event;
SDL_Surface *back;
SDL_Surface *coll;
perso p;
perso p2;
int continuer=1,droite=0,gauche=0,up=0,dir=2,droite2=0,gauche2=0,up2=0,dir2=2;
Uint32 dt, t_prev;
SDL_Surface *v1;
v1=IMG_Load("2.png");
SDL_Rect posv1;
posv1.x=450;
posv1.y=-40;








screen=SDL_SetVideoMode (1200,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_Init(SDL_INIT_VIDEO);
SDL_WM_SetCaption("perso aziz",NULL);
back=IMG_Load("1.jpg");
initPerso(&p);
initPerso2(&p2);
police= TTF_OpenFont("avocado.ttf", 35);

SDL_Color blanco={105,6,203}; 
texte1=TTF_RenderText_Blended(police,"score :",blanco);
p.position_textee.x=15;
p.position_textee.y=20;


//gestion de score
 





p.number[1];
p.valeur_score=0;




while (continuer)
{

p.number[1];

p.valeur_score++;
sprintf(p.number, "%d",(p.valeur_score));
number1= TTF_RenderText_Blended(police,p.number,blanco);
p.position_number.x=170;
p.position_number.y=20;

t_prev=SDL_GetTicks();


while(SDL_PollEvent(&event))
{
    switch (event.type)
    {
    case SDL_QUIT:
        continuer=0;
        break;

    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
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
afficherPerso(p,screen);
afficherPerso(p2,screen);
SDL_BlitSurface(texte,NULL,screen,&(p.position_textee));
SDL_BlitSurface(texte2,NULL,screen,&(p2.position_textee));


SDL_BlitSurface(texte1, NULL, screen,&p.position_textee);
SDL_BlitSurface(number1, NULL, screen,&p.position_number);

SDL_BlitSurface(v1,NULL,screen,&posv1);
SDL_Flip(screen);
SDL_Delay(50);



}

TTF_CloseFont(police);
return 0;
}

