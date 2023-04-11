isra:main.o enemy.o
	gcc main.o enemy.o -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -o isra -g; ./isra
main.o:main.c
	gcc -c main.c -g



