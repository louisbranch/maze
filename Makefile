FLAGS=-Wall -g
CC=gcc
all:
	$(CC) ${FLAGS} src/allegro_maze.c -o bin/maze -lallegro -lallegro_primitives
clean:
	rm -f bin/maze
