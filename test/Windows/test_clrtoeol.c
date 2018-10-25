#include<wncurses.h>

void test_clrtoeol()
{
	initscr();
	addstr("hahha\nas;ldkjfal;skjdfl;kasjsdf\nz,xmcnv,mzxci\nadskfm\nasdfij");
	getch();
	move(2,2);
	getch();
	clrtoeol();
	getch();
	refresh();
	getch();
	endwin();
}

