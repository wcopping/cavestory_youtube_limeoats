CC = g++
OBJECTS = main.cpp graphics.cpp game.cpp
OBJECT_NAME = main.out
INC1 = /home/wyatt/Projects/cavestory_youtube_limeoats/header
INCDIRS = -I$(INC1)
CFLAGS = -Wall -Werror $(INCDIRS) $(shell pkg-config --cflags --libs sdl2)

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
