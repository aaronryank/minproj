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

int trexpos = 0;
int jumping = 0;
int jumpdur = 0;
int score   = 0;
int highscore = 0;
int barrier_pause = 0;

int rand_upto(int high)
{
    return rand() % high; 
}

void print_score(void)
{
    screen_set( 0, 7 );
    printf("Score: %d", score/10);
}

int play_game(void)
{
    srand(time(NULL));

    char *screen = malloc(MAXWORD);

    score = 0;
    trexpos = 0;
    jumping = 0;
    jumpdur = 0;
    barrier_pause = 0;

    init_screen(&screen);

    forever {

        cls();
        load_screen(&screen);
        printf("\n\n\n\n\n%s\n", screen);
        fflush(stdout);

        trex();

        if ((trexpos == DEFAULT_TREX_POS) && (screen[2] == '|')) {

            if ((score/10) > highscore)
                highscore = score/10;

            printf("\n\nGAME OVER!!!\nScore: %d Highscore: %d\nPress 'Enter' to restart, 'Q' to quit...", score/10, highscore);

            int c;

            while ((c = getchar()) != '\n')
                if (c == 'q')
                    return 0;

            return 1;

        }

        fflush(stdout);

        print_trex();
        print_score();

        usleep(100000/SPEED);
    }

    free(screen);
}