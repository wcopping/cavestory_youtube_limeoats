CC = g++
OBJECTS = main.cpp graphics.cpp game.cpp input.cpp sprite.cpp animatedsprite.cpp player.cpp level.cpp tinyxml2.cpp tile.cpp rectangle.cpp
OBJECT_NAME = main.out
INC1 = /home/wyatt/Projects/cavestory_youtube_limeoats/header
#INC2 = /usr/include/SDL2
LIB1 = ~/Downloads/SDL2_image-2.0.1
LIB2 = ~/Downloads/SDL2-2.0.5
INCDIRS = -I$(INC1) -I$(INC2)
INCLIBS = -L$(LIB1) -L$(LIB2)
CFLAGS = -Wall -Werror $(INCDIRS) $(INCLIBS) $(shell pkg-config --cflags --libs sdl2) -lSDL2_image -Wno-reorder -std=c++11

all:
	$(CC) $(OBJECTS) $(CFLAGS) -o $(OBJECT_NAME); ./$(OBJECT_NAME)

# Makefile skeleton

#OBJS = main.cpp
#
#CC = g++
#
#COMPILER_FLAG = -std=c++11
#
#OBJ_NAME = main.out
#
#all:
#	$(CC) $(OBJS) $(COMPILER_FLAG) -o $(OBJ_NAME); ./$(OBJ_NAME)
