CXX = g++
CC = gcc
CFLAGS = -Wall -std=c++17 -pthread -lsqlite3
LFLAGS = -o
OBJ_DIR = build
HEADS_DIR = include
SRC_DIR = src
SRC = $(SRC_DIR)/gpa.cpp $(SRC_DIR)/main.cpp $(SRC_DIR)/student.cpp $(SRC_DIR)/uuid.cpp $(SRC_DIR)/database.cpp $(SRC_DIR)/school.cpp $(SRC_DIR)/menu.cpp

OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

all: run

build/%.o: src/%.cpp
	@$(CXX) -c -o $@ $(CFLAGS) $<

sqlite3/sqlite: sqlite3/sqlite3.c sqlite3/shell.c
	@$(CC) -o $@ $^ -lpthread -ldl

build/sqlite3.o : sqlite3/sqlite3.c
	@$(CC) -o $@ -c $^

main.exe: $(OBJ) build/sqlite3.o
	@$(CXX) $(OBJ) build/sqlite3.o $(LFLAGS) main.exe

run: main.exe sqlite3/sqlite
	@./main.exe

clean:
	@rm main.exe $(OBJ_DIR)/* tmp/*