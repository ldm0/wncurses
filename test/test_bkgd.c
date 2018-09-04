#include<ncurses.h>

int main()
{
	initscr();
	printw("lkasdjflkjahsdkljfnoijashdfasdkjf\nalsidjflkasdfkljaksdlfkjn\\nalskdjflkajsd");
	refresh();
	getch();
	bkgd('h');
	//if it set the bkgd instantly?
	//yes
	getch();
	refresh();
	getch();
	endwin();
}
