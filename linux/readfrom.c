/* readfrom.c - Copyright (C) 2016 Aaron Ryan Klingler

   Read from specified file, starting at specified bytes (readfrom FILE BYTES)
   Useful for sorting through long files. I wrote it to see how far 'alphanumerical' had gotten.
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char i;
	int err;
	FILE *f;

	if (argc != 3) {
		fprintf(stderr,"Usage: readfrom <FILE> <BYTES>\n");
		return -1;
	}
	
	f = fopen(argv[1],"r");
	if (!f) {
		err = errno;
		fprintf(stderr,"Error opening file %s: %s\n",argv[1],strerror(err));
		return -1;
	}

	if (fseek(f,atoi(argv[2]),SEEK_SET) == -1) {
		err = errno;
		fprintf(stderr,"Error seeking file %s to offset %d: %s\n",argv[1],atoi(argv[2]),strerror(err));
		return -1;
	}

	while ((i = getc(f)) != EOF)
		putchar(i);

	if (fclose(f) == EOF) {
		err = errno;
		fprintf(stderr,"Error closing file %s: %s\n",argv[1],strerror(err));
		return -1;
	}
}
