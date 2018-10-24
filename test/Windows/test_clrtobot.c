#include<wncurses.h>

void test_clrtobot()
{
	initscr();
	for (int y = 0; y < LINES; ++y)
		for (int x = 0; x < COLS; ++x)
			addch('h');
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

