CXX = g++
CFLAGS = -Wall -std=c++17 -pthread -l sqlite3
LFLAGS = -o
OBJ_DIR = obj/
HEADS_DIR = headers/
SRC_DIR = src/
SRC = $(SRC_DIR)/gpa.cpp $(SRC_DIR)/main.cpp $(SRC_DIR)/student.cpp $(SRC_DIR)/uuid.cpp

OBJ = $(patsubst $(SRC)%.cpp,$(OBJS)/%.o,$(SRC))
#DEP = $(patsubst $(SRC)%.cpp,$(OBJS)/%.o,%(SRC))

all: run

obj/%.o: src/%.cpp
	$(CXX) -c -o $@ $(CFLAGS) $<

main.exe: $(OBJ)
	$(CXX) $(OBJ) $(LFLAGS) main.exe

run: main.exe
	@./main.exe

clean:
	@rm main.exe obj/*.o