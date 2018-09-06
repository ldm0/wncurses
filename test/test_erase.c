#include<ncurses.h>

int main()
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
