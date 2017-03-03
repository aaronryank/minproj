CC=gcc -g -Wall -Wextra -trigraphs -digraphs
OBJ=hello.o
EXEC=ob

compile: $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

clean:
	rm $(OBJ) hello.c.*

reset:
	rm $(OBJ) hello.c.* ob
