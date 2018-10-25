#include<wncurses.h>

void test_vline()
{
	initscr();
	vline('a',5);
	getch();
	endwin();
}