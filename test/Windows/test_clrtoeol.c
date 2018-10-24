#include<wncurses.h>

void test_clrtoeol()
{
	initscr();
	addstr("hahha\nas;ldkjfal;skjdfl;kasjsdf\nz,xmcnv,mzxci\nadskfm\nasdfij");
	getch();
	move(2,2);
	getch();
	//if take effect instantly?
	//yes
	clrtoeol();
	getch();
	refresh();
	getch();
	endwin();
}

