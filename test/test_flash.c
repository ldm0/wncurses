#include<ncurses.h>

int main()
{
	flash();
	initscr();
	flash();
	getch();
	endwin();
}
