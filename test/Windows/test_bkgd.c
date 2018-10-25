#include<wncurses.h>

void test_bkgd()
{
	initscr();
	printw("lkasdjflkjahsdkljfnoijashdfasdkjf\nalsidjflkasdfkljaksdlfkjn\\nalskdjflkajsd");
	refresh();
	getch();
	bkgd('h');
	//if it sets the bkgd instantly?
	//yes
	getch();
	refresh();
	getch();
	//if the h in the string printw was changed to the e?
	//ans yes
	bkgd('e');
        getch();
	//if the bkgd have the refresh effect?
	//ans shit yes
	printw("iiiiiiiiiiiiiii");
	bkgd('k');
	getch();
	endwin();
}
