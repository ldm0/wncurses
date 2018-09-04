#include<ncurses.h>

int main()
{
	initscr();
	border(0,0,0,0,0,0,0,0);
	refresh();
	getch();
	//box(
	endwin();
}
