#include<wncurses.h>

void test_clrtobot()
{
	initscr();
	printw("hahha\nas;ldkjfal;skjdfl;kasjsdf\nz,xmcnv,mzxci\nadskfm\nasdfij");
	getch();
	move(2,2);
	getch();
	//if take effect instantly?
	//yes
	clrtobot();
	getch();
	refresh();
	getch();
	endwin();
}

