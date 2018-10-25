#include<wncurses.h>

void test_hline()
{
	initscr();
	hline('a', 100000);
	getch();
	endwin();
}