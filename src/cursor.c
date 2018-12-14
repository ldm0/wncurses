#include"cursor.h"
#include"window.h"
#include"swapbuffer.h"

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
		if (_wrefresh_pure(window) == ERR)
			return ERR;

	return OK;
}

int
curs_set			(int input)
{
	//not every window has a state, so I don't place the state in the WINDOW struct
	//I let the windows to store the cursor state
	CONSOLE_CURSOR_INFO _tmp_cur_info;
	if (!GetConsoleCursorInfo(stdscr->_swapbuffer[SWAPBUFFER_BACK], &_tmp_cur_info))
		return ERR;
	if (input == 0) {
		_tmp_cur_info.bVisible = FALSE;
	} else if (input == 1) {
		_tmp_cur_info.bVisible = TRUE;
		_tmp_cur_info.dwSize = 1;
	} else if (input == 2) {
		_tmp_cur_info.bVisible = TRUE;
		_tmp_cur_info.dwSize = 100;
	}
	if (!SetConsoleCursorInfo(stdscr->_swapbuffer[SWAPBUFFER_BACK], &_tmp_cur_info))
		return ERR;
	return OK;
}

int
mvcur				(int oldrow, int oldcol, int newrow, int newcol)
{
	stdscr->_cur.X += newcol - oldcol;
	stdscr->_cur.Y += newrow - oldrow;
	if (stdscr->_immed)
		if (_wrefresh_pure(stdscr) == ERR)
			return ERR;
	return OK;
}