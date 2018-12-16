#include<wncurses.h>

void test_framerate(void)
{
	initscr();
	for (int i = 0; ; ++i) {
		printw("%d", i);
		move(0, 0);
		refresh();
	}
	endwin();
}