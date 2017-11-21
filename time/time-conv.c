/* timer.c - Copyright (C) 2016 Aaron Ryan Klingler

   This will convert minutes and seconds to seconds and print the total and average.
   Useful for evaluating Track/XC times.
*/

#include <stdio.h>
#include <string.h>

int parse(char *);
char *unparse(int);

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Usage: time MM:SS...\n");
		return -1;
	}

	//int m = atoi(strtok(argv[1], ":")) * 60;
	//int s = atoi(strtok(NULL, ":"));
	//printf("Converted: %d seconds\n", (m + s));

	int i, x;
	for (i = 1, x = 0; i < argc; x += parse(argv[i++]));
	printf("Total: %d (%s)\n", x, unparse(x));
	printf("Average: %d (%s)\n", (x / (argc - 1)), unparse(x / (argc - 1)));
}

int parse(char *p)
{
	int m = atoi(strtok(p,":")) * 60;
	int s = atoi(strtok(NULL,":"));

	printf("%d seconds\n", (m + s));
	return (m + s);
}

char *unparse(int p)
{
	int m = p / 60;
	int s = p % 60;
	char formatted[100];

	sprintf(formatted, "%d:%d", m, s);
	return formatted;
}
