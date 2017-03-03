#include <stdio.h>

void parse(char *str, int mode)
{
    int i;

    for (i = 0; str[i]; i++) {
        switch (str[i]) {
          case 'a': putchar('4'); break;
          case 'e': putchar('3'); break;
          case 'l': putchar('1'); break;
          case 'o': putchar('0'); break;
          case 's': putchar('5'); break;
          default:  putchar(str[i]);
        }
    }

    putchar(' ');
}

int main(int argc, char *argv[])
{
    if (argc > 1) {
        int i;

        for (i = 1; i < argc; i++)
            parse(argv[i], 0);
    } else {
        char str[1024] = {0};

        while (scanf("%s", &str) != -1) {
            parse(str, 1);
        }
    }

    return 0;
}
