#include<wncurses.h>

void test_printw(void)
{
	initscr();
	addstr("hello?\n");
	refresh();
	getch();
	printw("hello?");
	refresh();
	getch();
	endwin();
}