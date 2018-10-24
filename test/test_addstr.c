#include<wncurses.h>

void test_addstr()
{
	char str[]="hellohello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello  \nworld";
	initscr();
	addstr(str);
	refresh();
	getch();
	endwin();
}
