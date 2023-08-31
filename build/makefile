OBJS = ../src/*

CC = g++

# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -W

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2main -lSDL2

OBJ_NAME = main

all:
	$(CC) -g --std=c++17  $(OBJS).cpp $(LINKER_FLAGS) -o $(OBJ_NAME)
