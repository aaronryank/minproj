OBJ    := dtoa.o
CC     := gcc
CFLAGS := -O3 -g -Wall -D__DTOA_TEST
EXE    := dtoa

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE)

clean:
	rm -f $(OBJ)