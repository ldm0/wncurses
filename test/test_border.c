#include<ncurses.h>

int main()
{
	initscr();
	border(0,0,0,0,0,0,0,0);
	getch();
	refresh();
	getch();
	//box(
	endwin();
}
