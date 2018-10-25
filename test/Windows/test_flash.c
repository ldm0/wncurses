#include<wncurses.h>

void test_flash()
{
	initscr();
	flash();
	getch();
	endwin();
}
