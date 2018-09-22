INCLUDE_DIR=./include
SRC_DIR=./src
LIB_DIR=lib
OBJ_DIR=obj
BIN_DIR=bin

CC=g++
DEPS=
CFLAGS=-std=c++14

_OBJ = $(shell ls -1 src | sed -E "s/\.cpp|\.hpp//" | sort | uniq | sed ':a;N;$!ba;s/\n//g' | awk 1 ORS='.o ')
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

$(BIN_DIR)/test_main: $(OBJ) test/test.cpp
	$(CC) -o $@ $^ -I $(INCLUDE_DIR) $(CFLAGS) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: clean

clean:
	rm $(OBJ_DIR)/*.o $(BIN_DIR)/*
