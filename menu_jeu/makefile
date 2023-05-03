prog: main.o fct.o perso.o
	gcc fct.o perso.o main.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer
main.o: main.c
	gcc -c main.c
fct.o: fct.c
	gcc -c fct.c
perso.o:perso.c
	gcc -c perso.c -g

