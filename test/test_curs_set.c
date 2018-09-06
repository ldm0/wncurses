#include<ncurses.h>

int main()
{
	initscr();
	curs_set(0);
	getch();
	curs_set(1);
	getch();
	curs_set(2);
	getch();
	endwin();
}
