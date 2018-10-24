#include<wncurses.h>
#include<stdio.h>


void test_baudrate()
{
	printf("baudrate with no initscr(): %d",baudrate());
	getchar();
	initscr();
	printw("baudrate with initscr(): %d",baudrate());
	refresh();
	getch();
	endwin();
}
