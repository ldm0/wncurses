#include<ncurses.h>

int main()
{
	initscr();
	for(int i=0;i<1024;++i){
		if(i%16==0)
			addch('\n');
		addch(i);
	}
	getch();
	endwin();
}
