CC=gcc
FLAGS=-Wall -g 
LIBS=-lpthread -ltermbox
OUT=simulate
INCLUDE=-I headers/
OBJS=./out/particle.o ./out/main.o

$(OUT): $(OBJS) ./out
	$(CC) $(FLAGS) $(LIBS) $(INCLUDE) -o $(OUT) $(OBJS) 

./out:
	mkdir ./out

./out/particle.o: particle.c headers/particle.h
	$(CC) $(FLAGS) $(INCLUDE) -o ./out/particle.o -c particle.c 

./out/main.o: main.c headers/main.h headers/constants.h headers/particle.h 
	$(CC) $(FLAGS) $(INCLUDE) -o ./out/main.o -c main.c 

.Phony: run

run:
	./$(OUT)

clean:
	rm $(OUT) out/*
