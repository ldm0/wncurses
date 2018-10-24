#include"wncurses.h"
#include"cursor.h"

int
move				(int y, int x)
{
	return wmove(stdscr, y, x);
}

int
wmove				(WINDOW *window, int y, int x)
{
	window->_cur.Y = y;
	window->_cur.X = x;

	if (window->_immed)
		if (!_wrefresh_pure(window))
			return ERR;

	return OK;
}