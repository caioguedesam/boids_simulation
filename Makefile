CC = g++
GLFLAGS = -lGL -lGLU -lglut

all:
	$(CC) src/*.cpp -o boids $(GLFLAGS)
