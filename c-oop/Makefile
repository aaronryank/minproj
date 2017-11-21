OBJ_1 := c-oop.o
OBJ_2 := polymorphism.o
CFLAGS := -g -Wall -O3
CC := gcc
EXE_1 := c-oop
EXE_2 := polymorphism

all: $(EXE_1) $(EXE_2)

$(EXE_1): $(OBJ_1)
	$(CC) $(CFLAGS) $(OBJ_1) -o $(EXE_1)

$(EXE_2): $(OBJ_2)
	$(CC) $(CFLAGS) $(OBJ_2) -o $(EXE_2)
