#include<ncurses.h>
#include<stdio.h>


int main()
{
	printf("baudrate with no initscr(): %d",baudrate());
	getchar();
	initscr();
	printw("baudrate with initscr(): %d",baudrate());
	refresh();
	getch();
	endwin();
}
