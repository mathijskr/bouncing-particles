CC=gcc
FLAGS=-Wall -g 
LIBS=-lpthread
OUT=simulate
INCLUDE=-I ../termbox/src/ -I headers/
OBJS=./out/termbox.o ./out/utf8.o ./out/particle.o ./out/main.o

$(OUT): $(OBJS)
	$(CC) $(FLAGS) $(LIBS) $(INCLUDE) -o $(OUT) $(OBJS) 

./out/termbox.o: ../termbox/src/termbox.c 
	$(CC) $(FLAGS) $(INCLUDE) -o ./out/termbox.o -c ../termbox/src/termbox.c 

./out/utf8.o: ../termbox/src/utf8.c
	$(CC) $(FLAGS) $(INCLUDE) -o ./out/utf8.o -c ../termbox/src/utf8.c 

./out/particle.o: particle.c headers/particle.h
	$(CC) $(FLAGS) $(INCLUDE) -o ./out/particle.o -c particle.c 

./out/main.o: main.c headers/main.h headers/constants.h headers/particle.h 
	$(CC) $(FLAGS) $(INCLUDE) -o ./out/main.o -c main.c 

.Phony: run

run:
	./$(OUT)

clean:
	rm $(OUT) out/*
