include Makefile.properties

all: build run

clean:
	rm main

build: main.c
	$(CC) $(CC_FLAGS) \
	main.c \
	-o main

run:
	./main
