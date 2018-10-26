#include<ncurses.h>

int main()
{
	initscr();
	addstr("OH, fuck you leather man");
	getch();
	mvdelch(0, 2);
	getch();
	endwin();
}
