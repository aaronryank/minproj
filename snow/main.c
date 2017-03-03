#include <stdlib.h>
#include <time.h>
#include "extern.h"

int main(int argc, char *argv[])
{
    int r = terminfo('r');
    int c = terminfo('c');
    int i, j, count, jump;
    struct point snow[50];

    if (argc < 3) {
        jump = 15;
        count = 50;
    } else if (argc != 3) {
        jump = atoi(argv[1]);
        count = atoi(argv[2]);
    }

    srand(time(0));
    for (i = 0, j = 0; (i < count) && (j < c); i++, j += _rand(jump))
        snow[i] = p_init(j+1, 1);

    animate_snow(snow, i, r, c);

    return 0;
}
