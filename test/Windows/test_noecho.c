#include<wncurses.h>

void test_noecho()
{
	initscr();
	noecho();
	addstr("noecho: press 'a':");
	getch();
	echo();
	addstr("\necho: press 'a':");
	getch();
	getch();
	endwin();
}