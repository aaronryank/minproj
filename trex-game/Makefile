OBJ := kbhit.o main.o game.o cls.o screen.o trex.o
CC := gcc
CFLAGS := -g -Wall -lm

EXECUTABLE := trex64.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXECUTABLE)

clean:
	rm $(OBJ)

reset:
	rm $(OBJ) $(EXECUTABLE)
