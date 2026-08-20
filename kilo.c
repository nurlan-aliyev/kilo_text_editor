#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

struct termios orig_temios;

void disableRawMode()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_temios);
}

void enableRawMode()
{
    tcgetattr(STDIN_FILENO, &orig_temios);
    atexit(disableRawMode);

    struct termios raw = orig_temios;

    tcgetattr(STDIN_FILENO, &raw);

    raw.c_iflag &= ~(ICRNL | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() 
{
    enableRawMode();

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q')
    {
        if (iscntrl(c))
        {
            printf("%d\r\n", c);
        }
        else 
        {
            printf("%d ('%c')\r\n", c, c);
        }
    }
    return 0;
}