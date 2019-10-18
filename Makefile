CC=cc
FLAGS=-g 
LIBS=-lpthread
IN=main.c particle.c  ../termbox/src/termbox.c ../termbox/src/utf8.c
OUT=main
INCLUDE=-I ../termbox/src/ -I headers/

make:
	$(CC) $(FLAGS) $(LIBS) $(INCLUDE) $(IN) -o $(OUT)

.Phony: run

run:
	./main

clean:
	rm main
