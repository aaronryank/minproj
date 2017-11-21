OBJ    := morse.o
CC     := gcc
CFLAGS := -O3 -g -Wall
EXE    := morse

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE)

clean:
	rm -f $(OBJ)