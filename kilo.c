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

    raw.c_lflag &= ~(ECHO);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() 
{
    enableRawMode();

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
    return 0;
}