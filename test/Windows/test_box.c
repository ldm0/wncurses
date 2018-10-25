#include <wncurses.h>

void test_box()
{
    initscr();

    box(stdscr,'*','*');
    refresh();
    getch();

    endwin();
}
