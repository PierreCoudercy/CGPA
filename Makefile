COMPILER = g++
CFLAGS = -Wall -c -std=c++17 -pthread
LFLAGS = -o

object:
	@$(COMPILER) $(CFLAGS) main.cpp gpa.cpp

compile: object
	@$(COMPILER) $(LFLAGS) main.exe main.o gpa.o

#rights: compile
#	@chmod u+x main.exe

run: compile
	@./main.exe

clean:
	@rm main.exe main.o