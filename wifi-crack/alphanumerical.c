/* alphanumerical.c - Copyright (C) 2016 Aaron Ryan Klingler

   Runs through every x-digit alphanumerical combination between 0... and Z..., x being argv[1].
   Useful for pentesting unchanged routers... if you have a few hours and a couple free gigabytes on your hands.
   If the LICENSE file was too long for you to read... same, man. Just don't remove the first line of this comment and you should be fine.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int increment_digit(int[], int, int);
void alphanumerical_print(int[], int);

const char alpha[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

int main(int argc, char *argv[])
{
	int size = 8;
	if (argc == 2)
		size = atoi(argv[1]);

	int digits[size];
	memset(digits,0,sizeof(digits));

	while (1) {
		alphanumerical_print(digits, size);
		if (!increment_digit(digits, size-1, 36))
			break;
	}
	return 0;
}

int increment_digit(int array[], int index, int limit)
{
	if (index == -1)
		return 0;

	array[index]++;
	if (array[index] == limit) {
		array[index] = 0;
		return increment_digit(array,index-1,limit);
	} else {
		return 1;
	}
}

void alphanumerical_print(int array[], int size)
{
	int i;
	for (i = 0; i < size; i++) {
		if (array[i] < 10)
			printf("%d",array[i]);
		else
			printf("%c",alpha[array[i]-10]);
	}
	putchar('\n');
}
