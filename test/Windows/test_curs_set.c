#include<wncurses.h>

void test_curs_set()
{
	initscr();
	curs_set(0);
	getch();
	curs_set(1);
	getch();
	curs_set(2);
	getch();
	endwin();
}
