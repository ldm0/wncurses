#include<ncurses.h>

int main()
{
	initscr();
	addstr("donoughliu");
	getch();
	move(0, 2);
	getch();
	char tmp = erasechar();
	getch();
	mvprintw(1, 0, "%d", tmp);
	getch();
	endwin();
}
