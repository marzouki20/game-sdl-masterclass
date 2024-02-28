prog:test.o fct.o music.o image.o 
	gcc test.o fct.o music.o image.o -o prog -lSDL -g -lSDL_image -lSDL_mixer -lSDL_ttf 
test.o:test.c
	gcc -c test.c -g
fct.o:fct.c
	gcc -c fct.c -g
music.o:music.c
	gcc -c music.c -g
image.o:image.c
	gcc -c image.c -g

