#ifndef _GAMEDEFS_H
#define _GAMEDEFS_H

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <stdio.h>

/*******************************************
 *Game variables. Modify to change the game*
 *******************************************/

#define SPEED          2   /* Default: 2  */
#define BARRIER_CHANCE 5   /* Default: 5  */
#define BARRIER_SPACE  5   /* Minimum: 4  */
#define SCREENSIZE     40  /* Default: 40 */
#define JUMPLEN        7   /* Default: 8, should be an even # */

/*******************************
 *DO NOT MODIFY PAST THIS LINE *
 *******************************/

extern int  rand_upto(int);
extern void load_char(char, char**);
extern void load_screen(char**);
extern void init_screen(char**);
extern void jump_trex(int);
extern void trex(void);
extern void trex_print(void);
extern void screen_set(int, int);
extern void cls(void);
extern void print_trex(void);
extern void print_score(void);
extern int  play_game(void);
extern void display_intro(void);

extern int trexpos, jumping, jumpdur, score, highscore, barrier_pause;
extern const char *intro[];

/* Windows-specific macro */
#ifdef _WIN32
#include <windows.h>
#define PERR(bSuccess, api) {if(!(bSuccess)) printf("%s: Error %d from %s on line %d\n", __FILE__, (int) GetLastError(), api, (int) __LINE__);}
#endif

#define DEFAULT_TREX_POS 5
#define BASE_SLEEP_DUR   100000 /* Default: 100000 */

#ifndef MAXWORD
#define MAXWORD 1024
#endif

#define rand_range(min, max) \
        ((rand() % (int)(((max) + 1) - (min))) + (min))

#define strset(str, set)  memset(str, 0, 1024); \
                          memcpy(str, set, strlen(set));

#define forever while(1)

#endif // gamedefs.h