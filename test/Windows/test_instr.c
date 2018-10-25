#include<wncurses.h>

void test_instr()
{
	initscr();
	addstr("halskdjflkasndfoiasnldfnoianesf");
	getch();
	char emm[1000];
	memset(emm, 0, sizeof(emm));
	mvinstr(0, 3, emm);
	getch();
	mvaddstr(5, 0, emm);
	getch();
	endwin();
}