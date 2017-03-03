#include "point.h"

struct point p_init(int x, int y)
{
    struct point temp;

    temp.x = x;
    temp.y = y;

    return temp;
}
