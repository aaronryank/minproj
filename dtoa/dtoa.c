/* Copyright (C) 2016 Aaron Ryan Klingler
   Convert a double to a string

   Notable algorithm:  while (floor(val) != ceil(val))
   Pretty much the basis of this whole program         */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef BUFSIZE
#define BUFSIZE 1024
#endif

/* return decimal part of val */
int dec(double val)
{
    int mult = (int) val;

    while (floor(val) != ceil(val)) {
        mult *= 10;
        val *= 10;
    }

    int retval = (int) val - mult;

    return retval;
}

/* apparently I can't write a freaking string-reverse algorithm
   stackoverflow.com/a/784567/6850771 */
char *reverse(char *str)
{
    char tmp, *src, *dst;
    size_t len;
    if (str != NULL)
    {
        len = strlen (str);
        if (len > 1) {
            src = str;
            dst = src + len - 1;
            while (src < dst) {
                tmp = *src;
                *src++ = *dst;
                *dst-- = tmp;
            }
        }
    }
    return str;
}

/* itoa from K&R */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)        /* record sign */
        n = -n;                /* make n positive */
    i = 0;

    do {                       /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0);   /* delete it */

    if (sign < 0)
        s[i++] = '-';

    reverse(s);
    s[i] = '\0';
    return;
}

/* convert a double to a string */
char *dtoa(double val, char *str)
{
    char leading_integer[BUFSIZE]  = {0};
    char trailing_decimal[BUFSIZE] = {0};

    /* fill string with leading integer */
    itoa((int) val, leading_integer);

    /* fill string with the decimal part */
    itoa(dec(val), trailing_decimal);

    /* set given string to full decimal */
    strcpy(str, leading_integer);
    strcat(str, ".");
    strcat(str, trailing_decimal);

    return str;
}

#ifdef ___DTOA_TEST
int main()
{
    double dtest = 3.14159265358979;
    char *stest = malloc(sizeof(char *));
    printf("%s\n", dtoa(dtest, stest)); 
}
#endif