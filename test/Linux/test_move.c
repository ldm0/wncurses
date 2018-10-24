#include<wncurses.h>

void test_move()
{
	initscr();
	getch();
	//if move need refresh() to take effect?
	//yes
	
	move(3,3);
	getch();
	endwin();
}
