#include<wncurses.h>
#include<windows.h>

void game()
{
	int input_vector_top = 0;
	char input_vector[20];

	for (;;) {
		getch();
		Sleep(10);
	}
}

void tmp_typegame()
{
	initscr();
	game();
	endwin();
}

