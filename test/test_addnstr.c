#include<wncurses.h>

void test_addnstr()
{
	char str[]="hello\nhello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello  \nworld";
	initscr();
	//if they print the \n or change the line
	//ans change the line
	addnstr(str,10);
	refresh();
	getch();
	clear();
	//if when the attr is biger than the str length
	//the attr is the same as the -1
	//ans yes
	addnstr(str,200);
	refresh();
	getch();
	addnstr(str,-1);
	refresh();
	getch();
	endwin();
}
