#include "stdio.h"
#include "time.h"
#include "string.h"
#include "stdarg.h"
#include "stdlib.h"
#ifdef _WIN32
        #include "conio.h"
#endif
#define Debug 1
#define true 1
#define false 0
#define KeyUP 65
#define KeyDown 66
#define KeyRight 67
#define KeyLeft 68
#define WinUp 72
#define WinDown 80
#define WinLeft 75
#define WinRight 77
#define Enter 13
#define SizeGet(A) (sizeof(A) / sizeof((A)[0]))

#ifdef _WIN32
    #include <windows.h>
    int getConsoleHeight() {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
#else
    #include <unistd.h>
    #include <sys/ioctl.h>
    int getConsoleHeight() {
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        return w.ws_row;
    }
#endif