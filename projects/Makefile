include Makefile.properties


all: build run

clean:
	rm main

build: main.c
	$(CC) $(CC_FLAGS) \
	main.c \
	-o main

build_temps:
	$(CC) $(CC_FLAGS) \
	main.c \
	--save-temps \
	-o main

clean_temps:
	rm main.s
	rm main.i
	rm main.bc
	rm main.o
	rm main


run:
	./main
