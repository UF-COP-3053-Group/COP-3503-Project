# Complier
CC=g++

# Compile everything
all:
	$(CC) -o calculator ./src/*.cpp

# The only thing to clean is the previously compiled project
clean:
	rm calculator