OBJ := main.o terminfo.o animation.o point.o rand.o wait.o
CC := gcc -g
CFLAGS := -Wall -DTEST

executable = snow

all: $(executable)

$(executable): $(OBJ);
	$(CC) $(CFLAGS) $(OBJ) -o $(executable)

clean:
	rm $(OBJ)

reset:
	rm $(OBJ) $(executable)
