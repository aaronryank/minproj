#include <stdio.h>
#include <math.h>

#define quit(ordinal,val) \
                      do { \
                          if (val) \
                              printf("%s%d ",ordinal,val); \
                          if (elem <= 0) { \
                              putchar('\n'); \
                              return; \
                          } \
                      } while (0)

int orbital(int *elem, int max)
{
    (*elem) -= max;
    return (*elem < 0) ? (max - abs(*elem)) : max;
}

void config(int elem)
{
    if (elem > 118)
        return;

    printf("%d\t-> ",elem);

    int orbital_maxes[] = {2, 2, 6, 2, 6, 10, 2, 6, 10, 2, 6, 14, 10, 2, 6, 14, 10, 2, 6};
    int orbitals[19] = {0};
    char *orbital_str[] = {"1s","2s","2p","3s","3p","3d","4s","4p","4d","5s","5p","4f","5d","6s","6p","5f","6d","7s","7p"};

    int i;
    for (i = 0; i < 19; i++) {
        orbitals[i] = orbital(&elem,orbital_maxes[i]);
        quit(orbital_str[i],orbitals[i]);
    }
}

int main(void)
{
    int i;
    for (i = 1; i <= 200; i++)
        config(i);
}
