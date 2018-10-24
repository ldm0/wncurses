#include<wncurses.h>

void test_flash()
{
	flash();
	initscr();
	flash();
	getch();
	endwin();
}
