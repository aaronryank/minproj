#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "gamedefs.h"

#ifdef _WIN32
# include <windows.h>
# include <conio.h>
#endif

int main(void)
{

#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &csbi);

    SMALL_RECT windowSize = {0 , 0 , (SCREENSIZE>strlen(intro[0]) ? SCREENSIZE : strlen(intro[0])) , 10}; //change the values
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);
#endif

    display_intro();

    while (
        play_game()
    );

#ifdef _WIN32
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &csbi.srWindow);
#endif

    cls();
}