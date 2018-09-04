#include<ncurses.h>

int main()
{
	char str[]="hellohello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello hello  \nworld";
	initscr();
	addstr(str);
	refresh();
	getch();
	endwin();
}
