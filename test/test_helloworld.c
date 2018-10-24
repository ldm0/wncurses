#include<wncurses.h>

void test_helloworld()
{
	initscr();
	
	addstr("hello world\n");
	refresh();
	endwin();
}