#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define _dev_urand_init()    fd = open("/dev/urandom", O_RDONLY);

const char *SPECIAL = "!@#$%^&*()_+-={}[]:<>?";

int fd;

unsigned int _dev_urand()
{
    int x;

    if (read(fd, &x, 1) != 1)
        fprintf(stderr, "Error reading from `/dev/urandom'\n");

    return x;
}

void rand_int()
{
    int i = _dev_urand() % 10;

    putchar(i + '0');
}

void rand_char()
{
    int i = _dev_urand() % 26;

    putchar(i + 'a');
}

void rand_special()
{
    int i = _dev_urand() % 23;

    putchar(SPECIAL[i]); 
}

void parse(char *s)
{
    int i;
    for (i = 0; s[i]; i++) {
        switch (s[i]) {
          case 'X': rand_char();
                    break;
          case 'Y': rand_int();
                    break;
          case 'Z': rand_special();
                    break;
          default:  putchar(s[i]);
        }
    }

    putchar('\n');
}

int main(int argc, char *argv[])
{
    _dev_urand_init();
    if (argc == 1) {
        char buf[1024] = {0};
        scanf("%s", &buf);

        parse(buf);
        return 0;
    }

    int i;
    for (i = 1; i < argc; i++)
        parse(argv[i]);
    return 0;
}
