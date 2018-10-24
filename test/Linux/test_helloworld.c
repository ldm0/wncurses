#include<ncurses.h>

int main()
{
	initscr();
	
	addstr("hello world\n");
	refresh();
	endwin();
}
