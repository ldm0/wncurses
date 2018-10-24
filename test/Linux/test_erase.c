#include<wncurses.h>

void test_erase()
{
	initscr();
	printw("akldsjflkasldkfj;lasd");
	getch();
	erase();
	getch();
	refresh();
	getch();
	endwin();
}
