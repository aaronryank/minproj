#include <stdlib.h>
#include <time.h>

int _rand(int mod)
{
    return rand() % mod;
}

int range3_urand()
{
    int s = _rand(2);

    return (_rand(2) == 0) ? -s : s;
}
