#include<ncurses.h>

int main()
{
	char str[]="hello\nhello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello  \nworld";
	initscr();
	addnstr(str,10);
	refresh();
	getch();
	clear();
	addnstr(str,100);
	refresh();
	getch();
	addnstr(str,-1);
	refresh();
	getch();

	endwin();
}
