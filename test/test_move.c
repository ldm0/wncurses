#include<ncurses.h>
#include<unistd.h>

int main()
{
	initscr();
	getch();
	//if move need refresh() to take effect?
	//yes
	
	move(3,3);
	sleep(3);
	getch();
	endwin();
}
