COMPILER = g++
CFLAGS = -Wall -c -std=c++17 -pthread
LFLAGS = -o

compile:
	@$(COMPILER) $(CFLAGS) main.cpp gpa.cpp student.cpp
	@$(COMPILER) $(LFLAGS) main.exe main.o gpa.o student.o

run: compile
	@./main.exe

clean:
	@rm main.exe *.o