OBJ    := trigraphs.o
CC     := gcc
CFLAGS := -O3 -g -Wall
EXE    := trigraphs

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE)

clean:
	rm -f $(OBJ)