#include<wncurses.h>

void test_border()
{
	initscr();
	border(0,0,0,0,0,0,0,0);
	getch();
	refresh();
	getch();
	//box(
	endwin();
}
