# Complier
CC=g++

#-g option for debugging, c++0x compiler, additional warnings
CFLAGS =  -std=c++0x #-Wall -pedantic 
EXFLAGS = 
SOURCES = ./src/*.cpp
BIN = calculator

# Compile everything

all:
	$(CC) $(CFLAGS) $(EXFLAGS) $(SOURCES) -o $(BIN) -lcurl 



# The only thing to clean is the previously compiled project
clean:
	rm $(BIN) 
