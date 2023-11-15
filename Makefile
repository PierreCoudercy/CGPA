COMPILER = g++
CFLAGS = -Wall -c -std=c++17 -pthread -l sqlite3
LFLAGS = -o

compile:
	@$(COMPILER) $(CFLAGS) main.cpp gpa.cpp student.cpp uuid/uuid.cpp
	@$(COMPILER) $(LFLAGS) main.exe main.o gpa.o student.o uuid.o

run: compile
	@./main.exe

clean:
	@rm main.exe *.o