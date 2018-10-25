#include<wncurses.h>

void test_beep()
{
	initscr();
	for (int i = 0; i < 3; ++i) {
		beep();
		getch();
	}
	endwin();
}