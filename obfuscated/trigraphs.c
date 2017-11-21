/* Copyright (C) 2016 Aaron Ryan Klingler
 * Translate any code to use trigraphs.
 */

#include <stdio.h>

void print_trigraph(char c)
{
	switch (c) {
	case '#':  printf("?\?="); break;
	case '\\': printf("?\?/"); break;
	case '^':  printf("?\?'"); break;
	case '[':  printf("?\?("); break;
	case ']':  printf("?\?)"); break;
	case '|':  printf("?\?!"); break;
	case '{':  printf("?\?<"); break;
	case '}':  printf("?\?>"); break;
	case '~':  printf("?\?-"); break;
	default:   putchar(c);     break;
	}
}

int main(void)
{
	char c;
	while ((c = getchar()) != EOF)
		print_trigraph(c);
}
