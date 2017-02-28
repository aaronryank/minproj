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

const char *intro[] = {
    " _____    ______ _______   __   _____   ___  ___  ___ _____ ",
    "|_   _|   | ___ \\  ___\\ \\ /  / |  __ \\ / _ \\ |  \\/  ||  ___|",
    "  | |_____| |_/ / |__  \\ V /   | |  \\// /_\\ \\| .  . || |__  ",
    "  | |_____|    /|  __| /   \\   | | __ |  _  || |\\/| ||  __| ",
    "  | |     | |\\ \\| |___/ /^\\  \\ | |_\\ \\| | | || |  | || |___ ",
    "  \\_/     \\_| \\_\\____/\\/    \\/  \\____/\\_| |_/\\_|  |_/\\____/ "
};

void load_char(char c, char **buffer)
{
    int i, s = strlen(*buffer);

    for (i = 0; i < s-2; i++)
        (*buffer)[i] = (*buffer)[i+1];

    (*buffer)[i] = c;
}

void load_screen(char **buffer)
{
    barrier_pause = (barrier_pause == BARRIER_SPACE) ? 0 : barrier_pause+1;

    if ((rand_upto(BARRIER_CHANCE+1) == 3) && !barrier_pause)
        load_char('|', buffer);
    else
        load_char('_', buffer);

    score++;
}

void init_screen(char **screen)
{
    int i;

    for (i = 0; i < SCREENSIZE; i++)
        (*screen)[i] = '_';
}

void screen_set(int x, int y)
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    COORD coordScreen = { x, y };
    BOOL bSuccess = SetConsoleCursorPosition( hConsole, coordScreen );
    PERR( bSuccess, "SetConsoleCursorPosition" );
#else
    printf("\e[%d;%dH", y, x);
#endif
}

void display_intro(void)
{
    cls();
    printf("Welcome to...\n");

    int i;
    for (i = 0; i < 6; i++)
        printf("%s\n", intro[i]);

    printf("Press 'Enter' to continue...\n");
    getchar();
}