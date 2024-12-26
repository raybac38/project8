## Makefile

CC=gcc

CFLAGS=-Wall -g
LFLAGS=-lGL -lm -lpthread -ldl -lrt -lX11

RAYLIB=./raylib/src/libraylib.a
RAYLIB_LIB=./raylib/src/
SRC_DIR=./src/
INCLUDE_DIR=./include/
BIN_DIR=./bin/


SRC= $(wildcard $(SRC_DIR)*.c)
OBJ= $(patsubst $(SRC_DIR)%.c, $(BIN_DIR)%.o, $(SRC)) 

EXEC=main

all: init_bin $(EXEC)

$(EXEC):$(OBJ)
	gcc -o $(EXEC) $^ $(RAYLIB) $(LFLAGS)

$(BIN_DIR)%.o:$(SRC_DIR)%.c
	gcc -c -o $@ $^ -I $(INCLUDE_DIR) -I $(RAYLIB_LIB)

init_bin:
	-mkdir bin

clean:
	-@ rm -r $(BIN_DIR)
	-@ rm $(EXEC)
	-@ echo "Cleanup"
