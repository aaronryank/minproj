/* Copyright (C) 2017 Ryan Klingler
   Decrypt a string at specified time

   Useful for ... nothing, but it's kinda cool */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* I hate warnings */
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#define WAIT_TIME 100000

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*x))
#define DECODED(t)    ((t->tm_year == TM_YR) && \
                       (t->tm_yday == TM_YD-1) && \
                       (t->tm_hour == TM_HR) && \
                       (t->tm_min == TM_MIN) && \
                       (t->tm_sec == TM_SEC))

#define TM_YR  117
#define TM_YD  26
#define TM_HR  17
#define TM_MIN 28
#define TM_SEC 50

const char *msg = "Hello, world!";

const char *ASCII = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 `~!@#$%^&*()_-+={}[]:\";'<>,.?/\\|";

void print_rand(int len)
{
    int i;
    for (i = 0; i < len; i++)
        putchar(ASCII[rand() % strlen(ASCII)]);
}

int main(void)
{
    srand(time(NULL));

    int l = strlen(msg);
    int hour = -1;

    time_t cur = time(NULL);
    struct tm *tm_struct = localtime(&cur);

    while (!DECODED(tm_struct))
    {
        cur = time(NULL);
        tm_struct = localtime(&cur);

        printf("Decoding: ");
        print_rand(l);
        putchar('\n');

        usleep(WAIT_TIME);
        fflush(stdout);
    }

    printf("!!!!FOUND STRING!!!!\n");
    printf("String decoded: %s\n", msg);
}
