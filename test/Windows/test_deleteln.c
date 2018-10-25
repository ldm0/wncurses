#include<wncurses.h>

void test_deleteln()
{
	initscr();
	addstr("hey man\nlook at me!\ncarefully");
	getch();
	move(1, 0);
	getch();
	deleteln();
	getch();
	endwin();
}