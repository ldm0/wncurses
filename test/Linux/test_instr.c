#include<ncurses.h>

int main()
{
	initscr();
	addstr("halskdjflkasndfoiasnldfnoianesf");
	getch();
	char emm[100];
	memset(emm, 0, sizeof(emm));
	mvinstr(0, 3, emm);
	getch();
	mvaddstr(5, 0, emm);
	getch();
	endwin();
}
