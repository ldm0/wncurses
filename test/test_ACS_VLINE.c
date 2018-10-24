#include<wncurses.h>

void test_ACS_VLINE()
{
	initscr();
	//
	for(int i=0;i<460;++i){
		if(i%16==0)
			addch('\n');
		addch(i);
	}
	getch();
	endwin();
}
