#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "extern.h"

void print_snow(char snow[])
{
    int i, s = strlen(snow);
    for (i = 0; i < s; i++)
        printf("\e[%dm%c", ((_rand(10) == 3) ? 36 : 0), snow[i]);
}

void animate_snow(struct point snow[], int size, int rows, int columns)
{
    printf("\e[0;0H\e[2J");
    int i;

    char screen[columns];

//    while (snow[0].y <= rows) {
    while (1) {
        memset(screen, ' ', sizeof(screen));
        for (i = 0; i < size; i++) {
            if ((snow[i].x >= 0) && (snow[i].x < columns))
                screen[snow[i].x] = '*';
            snow[i].x += range3_urand();
        }
        print_snow(screen);
        putchar('\n');

        fflush(stdout);
        usleep(100000);
    }

    putchar('\n');
}
