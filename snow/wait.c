#include <time.h>

void _wait(int secs)
{
    time_t t = time(NULL);
    while ((t + secs) > time(NULL));
}
