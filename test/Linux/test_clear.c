#include<ncurses.h>

int main()
{
	initscr();
	addstr("What the f**k?\n");
	refresh();
	getch();
	//if the clear function take effect immidately or after refresh
	//yes
	clear();
	getch();
	refresh();
	getch();
	endwin();
}
