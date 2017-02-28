#ifdef __unix__

#ifndef FIONREAD
#define FIONREAD 0x541B
#endif

#include <sys/select.h>
#include <termios.h>
#include <stdio.h>
#include <sys/ioctl.h>

int _kbhit() {
    int STDIN = 0;
    static int initialized = 0;

    if (!initialized) {

        // turn off line buffering with termios

        struct termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = 1;
    }

    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);

    return bytesWaiting;
}

#else
#include <conio.h>
#endif