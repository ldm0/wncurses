#include<wncurses.h>

void test_delch()
{
	initscr();
	addstr("OH, fuck you leather man");
	getch();
	mvdelch(0, 2);
	getch();
	endwin();
}