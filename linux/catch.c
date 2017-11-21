/* catch.c - Copyright (C) 2016 Aaron Ryan Klingler

   Catch all signals that would stop a program
   Very useful for when you don't want to integrate a signal catcher into a program
*/

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr,"Usage: catch PROGRAM...\n");
		return -1;
	}

	int i;
	char cmd[200];

	memset(cmd,0,sizeof(cmd));
	strcpy(cmd,argv[1]);
	for (i = 2; i < argc; i++) {
		strcat(cmd," ");
		strcat(cmd,argv[i]);
	}

	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		fprintf(stderr,"Error: Can't catch SIGINT\n");
	if (signal(SIGTERM, SIG_IGN) == SIG_ERR)
		fprintf(stderr,"Error: Can't catch SIGTERM\n");
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		fprintf(stderr,"Error: Can't catch SIGQUIT\n");
	if (signal(SIGTSTP, SIG_IGN) == SIG_ERR)
		fprintf(stderr,"Error: Can't catch SIGTSTP\n");
	system(cmd);
}
