COMPILER = g++
CFLAGS = -Wall -c -std=c++17 -pthread
LFLAGS = -o

object:
	@$(COMPILER) $(CFLAGS) main.cpp gpa.cpp

compile: object
	@$(COMPILER) $(LFLAGS) main.exe main.o gpa.o

rights: compile
	@chmod u+x main

run: rights
	@./main

clean:
	@rm main main.o