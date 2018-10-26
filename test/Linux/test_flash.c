#include<ncurses.h>

int main()
{
	initscr();
	while(1)
	flash();
	endwin();
}
