#include<wncurses.h>

void test_timeout(void)
{
	initscr();
	timeout(1000);
	noecho();
	for (;;) {
		char input = getch();
		if (input == -1)
			mvprintw(0, 0, "no");
		else
			mvprintw(0, 0, "%c  ", input);
		Sleep(100);
	}
	endwin();
}