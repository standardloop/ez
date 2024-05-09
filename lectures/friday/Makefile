all: build run

build: main.c
	gcc -E main.c -o main.i
	gcc -S main.i -o main.s
	gcc -c main.s -o main.o
	gcc main.o -o main

clean:
	rm main.i
	rm main.s
	rm main.o
	rm main

run:
	./main
