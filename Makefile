# Complier
CC=g++

#-g option for debugging, c++0x compiler, additional warnings
CFLAGS = -g -std=c++0x -Wall -pedantic 
SOURCES = ./src/*.cpp
BIN = calculator

# Compile everything

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(BIN) 



# The only thing to clean is the previously compiled project
clean:
	rm $(BIN) 
