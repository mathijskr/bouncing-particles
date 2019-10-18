CC=tcc
IN=main.c  ../termbox/src/termbox.c ../termbox/src/utf8.c
OUT=main
INCLUDE=-I ../termbox/src/ -I headers/

make:
	$(CC) $(INCLUDE) $(IN) -o $(OUT)

.Phony: run

run:
	./main

clean:
	rm main
