/* timer.c - Copyright (C) 2016 Aaron Ryan Klingler

   Time a program with any number of arguments
   Useful for checking how long it takes your program to execute
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr,"Usage: timer <PROGRAM> ARGUMENTS...\n");
		return -1;
	}

	int i, state = 1;
	int start, end;
	char cmd[200];
	memset(cmd,0,sizeof(cmd));
	
	for (i = state; i < argc; i++) {
		strcat(cmd,argv[i]);
		strcat(cmd," ");
	}

	printf("Executing %s...\n",cmd);

	start = time(0);
	system(cmd);
	end = time(0);

	printf("Time: %d to %d (%d seconds)\n",start,end,(end - start));
	return 0;
}
