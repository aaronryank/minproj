#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "gamedefs.h"

#ifdef _WIN32
# include <conio.h>
# include <windows.h>
#endif

void jump_trex(int key)
{
    if (key == ' ')
        jumping = 1;

    if (jumping == 1) {

        if (jumpdur++ < (JUMPLEN/2))
            trexpos--;
        else
            trexpos++;

        if (jumpdur >= JUMPLEN) {
            jumping = 0;
            jumpdur = 0;
            trexpos = DEFAULT_TREX_POS;
        }
    }
    else {
        trexpos = DEFAULT_TREX_POS;
    }
}

void trex(void)
{
    int key = _kbhit();

#ifdef _WIN32
    if (key)
        jump_trex(_getch());
    else
        jump_trex(0);
#else
    jump_player(key);
#endif
}

void print_trex(void)
{
    int height = trexpos;
    if (height < 3)
        height = 3;

    screen_set( 3, height );
    putchar('t');
}