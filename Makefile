#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa main
# Autor		: Gabriel Teixeira Carvalho (gabrielteixeirac@dcc.ufmg.br)
# Histórico	: 2021-11-23 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CXX = g++

BIN = bin
SRC = src
OBJ = obj
TMP = tmp
INC = include

OBJS = $(OBJ)/main.o $(OBJ)/geradorderodadas.o $(OBJ)/quicksort.o  $(OBJ)/heap.o $(OBJ)/intercalador.o $(OBJ)/memlog.o
HDRS = $(INC)/geradorderodadas.hpp $(INC)/quicksort.hpp $(INC)/heap.hpp $(INC)/entidade.hpp $(INC)/intercalador.hpp $(INC)/memlog.hpp

CXXFLAGS = -c -std=c++11 -Wall -I$(INC)

EXE = $(BIN)/main

all: $(EXE)

$(BIN)/main: $(OBJS) | $(BIN) $(TMP)
	$(CXX) -o $(BIN)/main $(OBJS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp | $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/geradorderodadas.o: $(HDRS) $(SRC)/geradorderodadas.cpp | $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(OBJ)/geradorderodadas.o $(SRC)/geradorderodadas.cpp

$(OBJ)/quicksort.o: $(HDRS) $(SRC)/quicksort.cpp | $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(OBJ)/quicksort.o $(SRC)/quicksort.cpp

$(OBJ)/heap.o: $(HDRS) $(SRC)/heap.cpp | $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(OBJ)/heap.o $(SRC)/heap.cpp

$(OBJ)/intercalador.o: $(HDRS) $(SRC)/intercalador.cpp | $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(OBJ)/intercalador.o $(SRC)/intercalador.cpp

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.cpp | $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.cpp

$(OBJ):
	mkdir $(OBJ)

$(BIN):
	mkdir $(BIN)

$(TMP):
	mkdir $(TMP)

clean:
	rm $(BIN) $(OBJ) $(TMP) -rf