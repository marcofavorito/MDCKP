INCLUDE_DIR=include
SRC_DIR=src
LIB_DIR=lib
OBJ_DIR=obj
BIN_DIR=bin
DOCS_DIR=docs
TEST_DIR=tests

APP_NAME=mdckp
MAJOR=1
MINOR_RELEASE=0.1
VERSION=$(MAJOR).$(MINOR_RELEASE)
LIB_NAME=$(LIB_DIR)/lib$(APP_NAME).so
BIN_NAME=$(BIN_DIR)/mdckp

CC=g++
DEPS=
CFLAGS=-Wall -std=c++14
LIB_FLAGS=-shared -Wl,-soname,lib$(APP_NAME).so.$(MAJOR)
LIBS=-l$(APP_NAME)
LATEX=pdflatex -synctex=1 -interaction=nonstopmode

_OBJ = $(shell ls -1 src | sed -E "s/\.cpp|\.hpp//" | sort | uniq | sed ':a;N;$!ba;s/\n//g' | awk 1 ORS='.o ')
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

.PHONY: clean all build docs

all: build

build: build_lib build_bin

test: build
	$(CC) $(CFLAGS) $(TEST_DIR)/test_mdckp.cpp -I$(INCLUDE_DIR) -L$(LIB_DIR) -l$(APP_NAME) -o $(TEST_DIR)/a.out
	LD_LIBRARY_PATH="./lib" $(TEST_DIR)/a.out --success

docs:
	make -C $(DOCS_DIR) all

build_bin: $(BIN_NAME) build_lib

build_lib: $(LIB_NAME) $(LIB_NAME).$(MAJOR)

$(BIN_NAME): examples/mdckp.cpp $(LIB_NAME)
	$(CC) $< -o $@ -I$(INCLUDE_DIR) -L./lib $(LIBS) $(CFLAGS)

$(LIB_NAME): $(LIB_NAME).$(VERSION)
	ln -sfr $< $@

$(LIB_NAME).$(MAJOR): $(LIB_NAME).$(VERSION)
	ln -sfr $< $@

$(LIB_NAME).$(VERSION): $(OBJ)
	$(CC) $(LIB_FLAGS) -o $@ $^ $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c -fPIC $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/* $(LIB_DIR)/*
	make -C $(DOCS_DIR) clean